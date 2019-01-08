/** \copyright Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/ToolHelp/ToolHelpLibrary.h"

#undef UNICODE
#include <TlHelp32.h>

#include "rrwindows/MenuRc/Strings.h"

RRWINDOWS_API
_Success_(0 <= return)
INT
WINAPI
CountProcessesByExecutableA(
    _In_z_ PCSTR CONST executableName)
{
    INT count = 0;

    HANDLE CONST snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
        return -1;

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(processEntry);
    if (!Process32First(snapshot, &processEntry))
        goto exit;
    do {
        if (CompareString_SimplifyA(executableName, processEntry.szExeFile) == CSTR_EQUAL)
            ++count;
    } while (Process32Next(snapshot, &processEntry));

exit:
    if (!CloseHandle(snapshot))
        return -1;

    return count;
}

RRWINDOWS_API
_Success_(0 <= return)
INT
WINAPI
CountProcessesByExecutableW(
    _In_z_ PCWSTR CONST executableName)
{
    INT count = 0;

    HANDLE CONST snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
        return -1;

    PROCESSENTRY32W processEntry;
    processEntry.dwSize = sizeof(processEntry);
    if (!Process32FirstW(snapshot, &processEntry))
        goto exit;
    do {
        if (CompareString_SimplifyW(executableName, processEntry.szExeFile) == CSTR_EQUAL)
            ++count;
    } while (Process32NextW(snapshot, &processEntry));

exit:
    if (!CloseHandle(snapshot))
        return -1;

    return count;
}
