/// \copyright Unlicense

#include "rrwindows/menurc/version_information.hxx"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#pragma comment(lib, "Version.Lib")

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace {

/// \broef 获取指定文件的固定信息。
/// \details Version Information > Fixed Information
/// \returns std::array(major, minor, patch, tweak)
/// \version 2019-07-06
/// \since 2018-07-13
VS_FIXEDFILEINFO get_file_fixed_information(LPCSTR lpszPath)
{
    CONST DWORD dwSiz = GetFileVersionInfoSizeA(lpszPath, nullptr);
    if (dwSiz == 0)
        throw rrwindows::system_error_exception("GetFileVersionInfoSizeA failed", GetLastError());
    const auto buf = make_unique<uint8_t[]>(dwSiz);
    if (!buf)
        throw bad_alloc();
    if (GetFileVersionInfoA(lpszPath, 0, dwSiz, buf.get()) == 0)
        throw rrwindows::system_error_exception("GetFileVersionInfoA failed", GetLastError());

    VS_FIXEDFILEINFO *lpstInfo;
    unsigned len;
    if (!VerQueryValueA(buf.get(), R"(\)", reinterpret_cast<LPVOID *>(&lpstInfo), &len))
        throw runtime_error("specified info not exist or not valid in file version info");
    return *lpstInfo;
}
VS_FIXEDFILEINFO get_file_fixed_information(LPCWSTR lpszPath)
{
    CONST DWORD dwSiz = GetFileVersionInfoSizeW(lpszPath, nullptr);
    if (dwSiz == 0)
        throw rrwindows::system_error_exception("GetFileVersionInfoSizeW failed", GetLastError());
    const auto buf = make_unique<uint8_t[]>(dwSiz);
    if (!buf)
        throw bad_alloc();
    if (GetFileVersionInfoW(lpszPath, 0, dwSiz, buf.get()) == 0)
        throw rrwindows::system_error_exception("GetFileVersionInfoW failed", GetLastError());

    VS_FIXEDFILEINFO *lpstInfo;
    unsigned len;
    if (!VerQueryValueW(buf.get(), LR"(\)", reinterpret_cast<LPVOID *>(&lpstInfo), &len))
        throw runtime_error("specified info not exist or not valid in file version info");
    return *lpstInfo;
}

}

namespace rrwindows {

RRWINDOWS_API array<uint16_t, 4> RRWINDOWS_CALL get_file_file_version_information(const char *path)
{
    CONST VS_FIXEDFILEINFO stInfo = get_file_fixed_information(path);
    return {HIWORD(stInfo.dwFileVersionMS), LOWORD(stInfo.dwFileVersionMS), HIWORD(stInfo.dwFileVersionLS), LOWORD(stInfo.dwFileVersionLS)};
}

RRWINDOWS_API array<uint16_t, 4> RRWINDOWS_CALL get_file_file_version_information(const wchar_t *path)
{
    CONST VS_FIXEDFILEINFO stInfo = get_file_fixed_information(path);
    return {HIWORD(stInfo.dwFileVersionMS), LOWORD(stInfo.dwFileVersionMS), HIWORD(stInfo.dwFileVersionLS), LOWORD(stInfo.dwFileVersionLS)};
}

RRWINDOWS_API std::array<std::uint16_t, 4> RRWINDOWS_CALL get_file_product_version_information(const char *path)
{
    CONST VS_FIXEDFILEINFO stInfo = get_file_fixed_information(path);
    return {HIWORD(stInfo.dwProductVersionMS), LOWORD(stInfo.dwProductVersionMS), HIWORD(stInfo.dwProductVersionLS), LOWORD(stInfo.dwProductVersionLS)};
}

RRWINDOWS_API std::array<std::uint16_t, 4> RRWINDOWS_CALL get_file_product_version_information(const wchar_t *path)
{
    CONST VS_FIXEDFILEINFO stInfo = get_file_fixed_information(path);
    return {HIWORD(stInfo.dwProductVersionMS), LOWORD(stInfo.dwProductVersionMS), HIWORD(stInfo.dwProductVersionLS), LOWORD(stInfo.dwProductVersionLS)};
}

}
