/// \copyright Unlicense

#pragma once
#include "version_information.hxx"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#pragma comment(lib, "Version.Lib")

#include "rrwindows/debug/error_handling.hxx"

namespace rrwindows {

namespace internal {

/// \broef 获取指定文件的固定信息。
/// \details Version Information > Fixed Information
/// \returns std::array(major, minor, patch, tweak)
/// \version 2019-07-06
/// \since 2018-07-13
inline VS_FIXEDFILEINFO get_file_fixed_information(LPCSTR lpszPath)
{
    CONST DWORD dwSiz = GetFileVersionInfoSizeA(lpszPath, nullptr);
    if (dwSiz == 0)
        throw system_error_exception("GetFileVersionInfoSizeA failed", GetLastError());
    const auto buf = std::make_unique<uint8_t[]>(dwSiz);
    if (!buf)
        throw std::bad_alloc {};
    if (GetFileVersionInfoA(lpszPath, 0, dwSiz, buf.get()) == 0)
        throw system_error_exception("GetFileVersionInfoA failed", GetLastError());

    VS_FIXEDFILEINFO *lpstInfo;
    unsigned len;
    if (!VerQueryValueA(buf.get(), "\\", reinterpret_cast<LPVOID *>(&lpstInfo), &len))
        throw std::runtime_error {"specified info not exist or not valid in file version info"};
    return *lpstInfo;
}

inline VS_FIXEDFILEINFO get_file_fixed_information(LPCWSTR lpszPath)
{
    CONST DWORD dwSiz = GetFileVersionInfoSizeW(lpszPath, nullptr);
    if (dwSiz == 0)
        throw system_error_exception("GetFileVersionInfoSizeW failed", GetLastError());
    const auto buf = std::make_unique<uint8_t[]>(dwSiz);
    if (!buf)
        throw std::bad_alloc {};
    if (GetFileVersionInfoW(lpszPath, 0, dwSiz, buf.get()) == 0)
        throw system_error_exception("GetFileVersionInfoW failed", GetLastError());

    VS_FIXEDFILEINFO *lpstInfo;
    unsigned len;
    if (!VerQueryValueW(buf.get(), L"\\", reinterpret_cast<LPVOID *>(&lpstInfo), &len))
        throw std::runtime_error {"specified info not exist or not valid in file version info"};
    return *lpstInfo;
}

}

inline std::array<uint16_t, 4> get_file_file_version_information(const char *path)
{
    CONST VS_FIXEDFILEINFO stInfo = internal::get_file_fixed_information(path);
    return {HIWORD(stInfo.dwFileVersionMS), LOWORD(stInfo.dwFileVersionMS), HIWORD(stInfo.dwFileVersionLS), LOWORD(stInfo.dwFileVersionLS)};
}

inline std::array<uint16_t, 4> get_file_file_version_information(const wchar_t *path)
{
    CONST VS_FIXEDFILEINFO stInfo = internal::get_file_fixed_information(path);
    return {HIWORD(stInfo.dwFileVersionMS), LOWORD(stInfo.dwFileVersionMS), HIWORD(stInfo.dwFileVersionLS), LOWORD(stInfo.dwFileVersionLS)};
}

inline std::array<std::uint16_t, 4> get_file_file_version_information(const std::filesystem::path &path)
{
    return get_file_file_version_information(path.c_str());
}

inline std::array<std::uint16_t, 4> get_file_product_version_information(const char *path)
{
    CONST VS_FIXEDFILEINFO stInfo = internal::get_file_fixed_information(path);
    return {HIWORD(stInfo.dwProductVersionMS), LOWORD(stInfo.dwProductVersionMS), HIWORD(stInfo.dwProductVersionLS), LOWORD(stInfo.dwProductVersionLS)};
}

inline std::array<std::uint16_t, 4> get_file_product_version_information(const wchar_t *path)
{
    CONST VS_FIXEDFILEINFO stInfo = internal::get_file_fixed_information(path);
    return {HIWORD(stInfo.dwProductVersionMS), LOWORD(stInfo.dwProductVersionMS), HIWORD(stInfo.dwProductVersionLS), LOWORD(stInfo.dwProductVersionLS)};
}

inline std::array<std::uint16_t, 4> get_file_product_version_information(const std::filesystem::path &path)
{
    return get_file_product_version_information(path.c_str());
}

}
