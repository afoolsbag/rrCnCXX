/// \copyright Unlicense

#include "rrwindows/memory/memory_management.hxx"

#include <map>
#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;
using namespace gsl;

//------------------------------------------------------------------------------
// 堆内存：heap

namespace rrwindows {

RRWINDOWS_API void *RRWINDOWS_CALL heap_malloc(size_t size)
{
    CONST LPVOID lpMem {HeapAlloc(GetProcessHeap(), 0, static_cast<SIZE_T>(size))};
    if (!lpMem)
        throw bad_alloc();
    return lpMem;
}

RRWINDOWS_API void *RRWINDOWS_CALL heap_calloc(size_t count, size_t unit_size)
{
    CONST SIZE_T dwBytes {count * unit_size};
    CONST LPVOID lpMem {HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwBytes)};
    if (!lpMem)
        throw bad_alloc();
    return lpMem;
}

RRWINDOWS_API void *RRWINDOWS_CALL heap_realloc(void *p, std::size_t new_size)
{
    CONST LPVOID lpMem {HeapReAlloc(GetProcessHeap(), 0, reinterpret_cast<LPVOID>(p), static_cast<SIZE_T>(new_size))};
    if (!lpMem)
        throw bad_alloc();
    return lpMem;
}

RRWINDOWS_API void RRWINDOWS_CALL heap_free(void *p) noexcept
{
    HeapFree(GetProcessHeap(), 0, reinterpret_cast<LPVOID>(p));
}

}

//------------------------------------------------------------------------------
// 地址窗口扩展内存：address windowing extensions

namespace {

void logged_set_lock_pages_privilege(HANDLE hProcess, bool enable)
{
    // 打开令牌
    CONST HANDLE hToken {[&] {
        HANDLE hTokenTmp;
        if (!OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hTokenTmp))
            throw rrwindows::system_error_exception("OpenProcessToken failed", GetLastError());
        return hTokenTmp;
    }()};
    const auto finally_close_token = finally([&] { CloseHandle(hToken); });

    struct {
        DWORD Count {1};
        LUID_AND_ATTRIBUTES Privilege[1] {};
    } stInfo;

    if (enable)
        stInfo.Privilege[0].Attributes = SE_PRIVILEGE_ENABLED;
    else
        stInfo.Privilege[0].Attributes = 0;

    // 查找权限
    if (!LookupPrivilegeValue(nullptr, SE_LOCK_MEMORY_NAME, &stInfo.Privilege[0].Luid))
        throw rrwindows::system_error_exception("LookupPrivilegeValue with SE_LOCK_MEMORY_NAME failed", GetLastError());

    // 调整权限
    if (!AdjustTokenPrivileges(hToken, FALSE, reinterpret_cast<PTOKEN_PRIVILEGES>(&stInfo), 0, nullptr, nullptr))
        throw rrwindows::system_error_exception("AdjustTokenPrivileges failed", GetLastError());
    if (GetLastError() != ERROR_SUCCESS)
        throw runtime_error("cannot enable the SE_LOCK_MEMORY_NAME privilege");
}

struct awe_t {
    PVOID lpWnd;
    ULONG_PTR  ulpPagesActual;
    PULONG_PTR pulpPagesHandle;
};

map<PVOID, awe_t> static_awe_map;

}

namespace rrwindows {

RRWINDOWS_API void *RRWINDOWS_CALL awe_malloc(size_t size)
{
    // 获取页尺寸
    CONST SYSTEM_INFO stSysInfo {[] {
        SYSTEM_INFO stSysInfoTmp;
        GetSystemInfo(&stSysInfoTmp);
        return stSysInfoTmp;
    }()};

    // 计算页数量和页数组句柄尺寸
    CONST ULONG_PTR ulpPagesRequest {size / stSysInfo.dwPageSize};
    CONST ULONG_PTR ulpPagesHandleSize {ulpPagesRequest * sizeof(ULONG_PTR)};

    // 分配页数组句柄
    CONST PULONG_PTR pulpPagesHandle {reinterpret_cast<ULONG_PTR *>(HeapAlloc(GetProcessHeap(), 0, ulpPagesHandleSize))};
    if (!pulpPagesHandle)
        throw runtime_error("HeapAlloc failed");

    bool auto_free_handle {true};
    const auto finally_free_handle = finally([&] {
        if (auto_free_handle)
            HeapFree(GetProcessHeap(), 0, pulpPagesHandle);
    });

    // 获取“锁定物理页”权限
    logged_set_lock_pages_privilege(GetCurrentProcess(), true);

    // 分配页（物理内存）
    CONST ULONG_PTR ulpPagesActual {[&] {
        ULONG_PTR ulpPagesActualTmp = ulpPagesRequest;
        if (!AllocateUserPhysicalPages(GetCurrentProcess(), &ulpPagesActualTmp, pulpPagesHandle))
            throw system_error_exception("AllocateUserPhysicalPages failed", GetLastError());
        return ulpPagesActualTmp;
    }()};

    bool auto_free_pages {true};
    const auto finally_free_pages = finally([&] {
        if (auto_free_pages) {
            ULONG_PTR ulpPagesActualTmp = ulpPagesActual;
            FreeUserPhysicalPages(GetCurrentProcess(), &ulpPagesActualTmp, pulpPagesHandle);
        }
    });

    if (ulpPagesActual != ulpPagesRequest)
        throw runtime_error("AllocateUserPhysicalPages not enough");

    // 分配窗口（虚拟内存）
    CONST LPVOID lpWnd {VirtualAlloc(nullptr, static_cast<SIZE_T>(size), MEM_RESERVE | MEM_PHYSICAL, PAGE_READWRITE)};
    if (!lpWnd)
        throw system_error_exception("VirtualAlloc failed", GetLastError());

    bool auto_free_wnd {true};
    const auto finally_free_wnd = finally([&] {
        if (auto_free_wnd)
            VirtualFree(lpWnd, 0, MEM_RELEASE);
    });

    // 映射页（物理内存）到窗口（虚拟内存）
    if (!MapUserPhysicalPages(lpWnd, ulpPagesActual, pulpPagesHandle))
        throw system_error_exception("MapUserPhysicalPages failed", GetLastError());

    bool auto_unmap {true};
    const auto finally_unmap = finally([&] {
        if (auto_unmap)
            MapUserPhysicalPages(lpWnd, ulpPagesActual, nullptr);
    });

    // 存入数据到映射表，取消自动资源释放，返回虚拟指针
    static_awe_map.insert(make_pair(lpWnd, awe_t {lpWnd, ulpPagesActual, pulpPagesHandle}));
    auto_unmap = false;
    auto_free_wnd = false;
    auto_free_pages = false;
    auto_free_handle = false;
    return lpWnd;
}

RRWINDOWS_API void RRWINDOWS_CALL awe_free(void *p) noexcept
{
    try {
        const awe_t awe {[&] {
            const auto tmp = static_awe_map.at(p);
            static_awe_map.erase(p);
            return tmp;
        }()};

        // 取消映射
        MapUserPhysicalPages(awe.lpWnd, awe.ulpPagesActual, nullptr);

        // 释放虚拟内存
        VirtualFree(awe.lpWnd, 0, MEM_RELEASE);

        // 释放物理内存
        ULONG_PTR pages_number = awe.ulpPagesActual;
        FreeUserPhysicalPages(GetCurrentProcess(), &pages_number, awe.pulpPagesHandle);

        // 释放页数组句柄
        HeapFree(GetProcessHeap(), 0, awe.pulpPagesHandle);

    } catch (...) {
        return;
    }
}

}
