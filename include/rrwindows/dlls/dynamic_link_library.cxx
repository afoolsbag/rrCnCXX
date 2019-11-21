/// \copyright Unlicense

#include "rrwindows/dlls/dynamic_link_library.hxx"

#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
#include <PathCch.h>
#pragma comment(lib, "pathcch.lib")
#endif
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace rrwindows {

RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL executable_path()
{
    shared_ptr<WCHAR[]> buf {};
    for (DWORD dwCnt = MAX_PATH; ; dwCnt *= 2) {
        buf = make_unique<WCHAR[]>(dwCnt);
        if (!buf)
            throw bad_alloc();
        const auto dwLen = GetModuleFileNameW(nullptr, buf.get(), dwCnt);
        if (dwLen == 0)
            throw system_error_exception("GetModuleFileNameW failed", GetLastError());
        if (dwLen < dwCnt)
            return buf.get();
    }
}

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL rrwindows_path()
{
    shared_ptr<WCHAR[]> buf {};
    for (DWORD dwCnt = MAX_PATH; ; dwCnt *= 2) {
        buf = make_unique<WCHAR[]>(dwCnt);
        if (!buf)
            throw bad_alloc();
        CONST DWORD dwLen = GetModuleFileNameW(
            reinterpret_cast<HINSTANCE>(&__ImageBase),
            reinterpret_cast<LPWSTR>(buf.get()),
            dwCnt);
        if (dwLen == 0)
            throw system_error_exception("GetModuleFileNameW failed", GetLastError());
        if (dwLen < dwCnt)
            return buf.get();
    }
}

}
