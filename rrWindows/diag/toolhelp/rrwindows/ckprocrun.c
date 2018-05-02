/** \copyright The MIT License */

#define RRWINDOWS_CKPROCRUN_EXPORTS
#include "ckprocrun.h"

#include <tchar.h>
#undef UNICODE
#include <TlHelp32.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

RRWINDOWS_CKPROCRUN_API
_Success_(return != 0)
DWORD WINAPI
CheckProcessRunningA(
    _In_z_ LPCSTR CONST exeFileFullName)
{
    HANDLE hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return FALSE;

    PROCESSENTRY32 info;
    info.dwSize = sizeof(info);
    Process32First(hdl, &info);
    do {
        if (!strcmp(exeFileFullName, info.szExeFile)) {
            CloseHandle(hdl);
            return info.th32ProcessID;
        }
    } while (Process32Next(hdl, &info));

    CloseHandle(hdl);
    return FALSE;
}

RRWINDOWS_CKPROCRUN_API
_Success_(return != 0)
DWORD WINAPI
CheckProcessRunningW(
    _In_z_ LPCWSTR CONST exeFileFullName)
{
    HANDLE hdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hdl)
        return FALSE;

    PROCESSENTRY32W info;
    info.dwSize = sizeof(info);
    Process32FirstW(hdl, &info);
    do {
        if (!wcscmp(exeFileFullName, info.szExeFile)) {
            CloseHandle(hdl);
            return info.th32ProcessID;
        }
    } while (Process32NextW(hdl, &info));

    CloseHandle(hdl);
    return FALSE;
}
