/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "cntproc.h"

#undef UNICODE
#include <TlHelp32.h>

#include "rrwindows/strsim.h"

RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
CountProcessesByExecutableA(
    _In_z_ LPCSTR CONST exeName)
{
    INT cnt = 0;

    HANDLE CONST hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return -1;

    PROCESSENTRY32 info;
    info.dwSize = sizeof(info);
    if (!Process32First(hdl, &info))
        goto out_clshdl;
    do {
        if (CSTR_EQUAL == CompareStringAs(exeName, info.szExeFile))
            ++cnt;
    } while (Process32Next(hdl, &info));

out_clshdl:
    if (!CloseHandle(hdl))
        return -1;

    return cnt;
}

RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
CountProcessesByExecutableW(
    _In_z_ LPCWSTR CONST exeName)
{
    INT cnt = 0;

    HANDLE CONST hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return -1;

    PROCESSENTRY32W info;
    info.dwSize = sizeof(info);
    if (!Process32FirstW(hdl, &info))
        goto out_clshdl;
    do {
        if (CSTR_EQUAL == CompareStringWs(exeName, info.szExeFile))
            ++cnt;
    } while (Process32NextW(hdl, &info));

out_clshdl:
    if (!CloseHandle(hdl))
        return -1;

    return cnt;
}
