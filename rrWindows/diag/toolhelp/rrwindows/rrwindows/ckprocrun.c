/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "ckprocrun.h"

#undef UNICODE
#include <TlHelp32.h>

#include "rrwindows/winstr.h"

RRWINDOWS_API
_Success_(return != 0)
DWORD WINAPI
CheckProcessRunningA(
    _In_z_ LPCSTR CONST exeName)
{
    HANDLE CONST hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return 0uL;

    PROCESSENTRY32 info;
    info.dwSize = sizeof(info);
    Process32First(hdl, &info);
    do {
        if (CSTR_EQUAL == CmpStrA(exeName, info.szExeFile)) {
            CloseHandle(hdl);
            return info.th32ProcessID;
        }
    } while (Process32Next(hdl, &info));

    CloseHandle(hdl);
    return 0uL;
}

RRWINDOWS_API
_Success_(return != 0)
DWORD WINAPI
CheckProcessRunningW(
    _In_z_ LPCWSTR CONST exeName)
{
    HANDLE CONST hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return 0uL;

    PROCESSENTRY32W info;
    info.dwSize = sizeof(info);
    Process32FirstW(hdl, &info);
    do {
        if (CSTR_EQUAL == CmpStrW(exeName, info.szExeFile)) {
            CloseHandle(hdl);
            return info.th32ProcessID;
        }
    } while (Process32NextW(hdl, &info));

    CloseHandle(hdl);
    return 0uL;
}
