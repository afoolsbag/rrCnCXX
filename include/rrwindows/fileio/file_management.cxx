/// \copyright Unlicense

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/fileio/file_management.hxx"

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace rrwindows {

RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL temp_path()
{
    WCHAR buf[MAX_PATH + 1];
    if (GetTempPathW(MAX_PATH + 1, buf) == 0)
        throw system_error_exception("GetTempPathW failed", GetLastError());
    return buf;
}

}
