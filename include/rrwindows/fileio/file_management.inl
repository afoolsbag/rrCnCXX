/// \copyright Unlicense

#pragma once
#include "file_management.hxx"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

namespace rrwindows {

inline std::filesystem::path temp_path()
{
    WCHAR buf[MAX_PATH + 1];
    if (GetTempPathW(MAX_PATH + 1, buf) == 0)
        throw system_error_exception("GetTempPathW failed", GetLastError());
    return buf;
}

}
