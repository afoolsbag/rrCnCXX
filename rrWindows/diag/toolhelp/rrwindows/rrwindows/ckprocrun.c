/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "ckprocrun.h"

#undef UNICODE
#include <TlHelp32.h>

#include "rrwindows/winstr.h"

RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
CheckProcessRunningA(
    _In_z_ LPCSTR CONST exeName)
{
    HANDLE CONST hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return -1;

    PROCESSENTRY32 info;
    info.dwSize = sizeof(info);
    if (FALSE == Process32First(hdl, &info)) {
        if (!CloseHandle(hdl))
            return -1;
        return 0;
    }
    do {
        if (CSTR_EQUAL == CompareStringAs(exeName, info.szExeFile)) {
            if (!CloseHandle(hdl))
                return -1;
            return 1;
        }
    } while (Process32Next(hdl, &info));

    if (!CloseHandle(hdl))
        return -1;
    return 0;
}

RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
CheckProcessRunningW(
    _In_z_ LPCWSTR CONST exeName)
{
    HANDLE CONST hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return -1;

    PROCESSENTRY32W info;
    info.dwSize = sizeof(info);
    if (FALSE == Process32FirstW(hdl, &info)) {
        if (!CloseHandle(hdl))
            return -1;
        return 0;
    }
    do {
        if (CSTR_EQUAL == CompareStringWs(exeName, info.szExeFile)) {
            if (!CloseHandle(hdl))
                return -1;
            return 1;
        }
    } while (Process32NextW(hdl, &info));

    if (!CloseHandle(hdl))
        return -1;
    return 0;
}
