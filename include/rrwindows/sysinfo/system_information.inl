/// \copyright Unlicense

#pragma once
#include "system_information.hxx"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

namespace rrwindows {

inline std::filesystem::path system_directory_path()
{
    WCHAR acBuf[MAX_PATH];
    if (GetSystemDirectoryW(acBuf, _countof(acBuf)) == 0)
        throw system_error_exception("GetSystemDirectoryW failed", GetLastError());
    return acBuf;
}

inline std::filesystem::path system_windows_directory_path()
{
    WCHAR acBuf[MAX_PATH];
    if (GetSystemWindowsDirectoryW(acBuf, _countof(acBuf)) == 0)
        throw system_error_exception("GetSystemWindowsDirectoryW failed", GetLastError());
    return acBuf;
}

inline std::filesystem::path windows_directory_path()
{
    WCHAR acBuf[MAX_PATH];
    if (GetWindowsDirectoryW(acBuf, _countof(acBuf)) == 0)
        throw system_error_exception("GetWindowsDirectoryW failed", GetLastError());
    return acBuf;
}

}
