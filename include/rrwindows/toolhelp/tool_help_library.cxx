/// \copyright Unlicense

#include "rrwindows/toolhelp/tool_help_library.hxx"

#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef UNICODE
#include <TlHelp32.h>

#include "rrwindows/debug/error_handling.hxx"
#include "rrwindows/menurc/strings.hxx"

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API std::size_t RRWINDOWS_CALL count_processes_by_name(const char *executable_name)
{
    CONST HANDLE hSnapshot {CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)};
    if (hSnapshot == INVALID_HANDLE_VALUE)
        throw system_error_exception("CreateToolhelp32Snapshot failed", GetLastError());
    const auto finally_close_snapshot = finally([&] { CloseHandle(hSnapshot); });

    PROCESSENTRY32 stProcessEntry;
    stProcessEntry.dwSize = sizeof(stProcessEntry);

    SIZE_T sizCount {0};
    if (!Process32First(hSnapshot, &stProcessEntry)) {
        CONST DWORD dwError {GetLastError()};
        if (dwError == ERROR_NO_MORE_FILES)
            return sizCount;
        throw system_error_exception("Process32First failed", GetLastError());
    }
    do {
        if (strcmp(executable_name, stProcessEntry.szExeFile) == 0)
            ++sizCount;
    } while (Process32Next(hSnapshot, &stProcessEntry));

    return sizCount;
}

RRWINDOWS_API std::size_t RRWINDOWS_CALL count_processes_by_name(const wchar_t *executable_name)
{
    CONST HANDLE hSnapshot {CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)};
    if (hSnapshot == INVALID_HANDLE_VALUE)
        throw system_error_exception("CreateToolhelp32Snapshot failed", GetLastError());
    const auto finally_close_snapshot = finally([&] { CloseHandle(hSnapshot); });

    PROCESSENTRY32W stProcessEntry;
    stProcessEntry.dwSize = sizeof(stProcessEntry);

    SIZE_T sizCount {0};
    if (!Process32FirstW(hSnapshot, &stProcessEntry)) {
        CONST DWORD dwError {GetLastError()};
        if (dwError == ERROR_NO_MORE_FILES)
            return sizCount;
        throw system_error_exception("Process32FirstW failed", GetLastError());
    }
    do {
        if (strcmp(executable_name, stProcessEntry.szExeFile) == 0)
            ++sizCount;
    } while (Process32NextW(hSnapshot, &stProcessEntry));

    return sizCount;
}

}
