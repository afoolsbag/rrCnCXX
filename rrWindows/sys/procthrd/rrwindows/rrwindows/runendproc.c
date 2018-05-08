/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "runendproc.h"

#include <stdlib.h>
#include <strsafe.h>
#undef UNICODE
#include <TlHelp32.h>

#include "rrwindows/winstr.h"

RRWINDOWS_API _Success_(return != FALSE) BOOL WINAPI
RunProcessA(
    _In_z_ LPCSTR CONST exePath,
    _In_z_ LPCSTR CONST exeParameters)
{
    CONST size_t paramBufCnt = StrLenA(exeParameters) + 2;
    LPSTR CONST paramBuf = HeapAlloc(GetProcessHeap(), 0, paramBufCnt * sizeof(CHAR));
    if (!paramBuf)
        return FALSE;
    paramBuf[0] = ' ';
    StringCchCopyA(paramBuf + 1, paramBufCnt - 1, exeParameters);
    STARTUPINFOA startupInfo;
    SecureZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    PROCESS_INFORMATION procInfo;
    SecureZeroMemory(&procInfo, sizeof(procInfo));

    CONST BOOL succ = CreateProcessA(exePath, paramBuf, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &procInfo);

    HeapFree(GetProcessHeap(), 0, paramBuf);
    if (succ) {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }
    return succ;
}

RRWINDOWS_API _Success_(return != FALSE) BOOL WINAPI
RunProcessW(
    _In_z_ LPCWSTR CONST exePath,
    _In_z_ LPCWSTR CONST exeParameters)
{
    CONST size_t paramBufCnt = StrLenW(exeParameters) + 2;
    LPWSTR CONST paramBuf = HeapAlloc(GetProcessHeap(), 0, paramBufCnt * sizeof(WCHAR));
    if (!paramBuf)
        return FALSE;
    paramBuf[0] = L' ';
    StringCchCopyW(paramBuf + 1, paramBufCnt - 1, exeParameters);
    STARTUPINFOW startupInfo;
    SecureZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    PROCESS_INFORMATION procInfo;
    SecureZeroMemory(&procInfo, sizeof(procInfo));

    CONST BOOL succ = CreateProcessW(exePath, paramBuf, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &procInfo);

    HeapFree(GetProcessHeap(), 0, paramBuf);
    if (succ) {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }
    return succ;
}

RRWINDOWS_API _Success_(return != FALSE) BOOL WINAPI
EndProcessA(
    _In_z_ CONST LPCSTR exeName)
{
    BOOL rv = TRUE;

    HANDLE CONST snapHdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == snapHdl)
        return FALSE;
    PROCESSENTRY32 info;
    info.dwSize = sizeof(info);
    Process32First(snapHdl, &info);
    do {
        if (CSTR_EQUAL == CmpStrA(exeName, info.szExeFile)) {
            HANDLE CONST hdl = OpenProcess(PROCESS_TERMINATE, FALSE, info.th32ProcessID);
            if (!TerminateProcess(hdl, EXIT_SUCCESS))
                rv = FALSE;
            CloseHandle(hdl);
        }
    } while (Process32Next(snapHdl, &info));
    CloseHandle(snapHdl);

    return rv;
}

RRWINDOWS_API _Success_(return != FALSE) BOOL WINAPI
EndProcessW(
    _In_z_ CONST LPCWSTR exeName)
{
    BOOL rv = TRUE;

    HANDLE CONST snapHdl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == snapHdl)
        return FALSE;
    PROCESSENTRY32W info;
    info.dwSize = sizeof(info);
    Process32FirstW(snapHdl, &info);
    do {
        if (CSTR_EQUAL == CmpStrW(exeName, info.szExeFile)) {
            HANDLE CONST hdl = OpenProcess(PROCESS_TERMINATE, FALSE, info.th32ProcessID);
            if (!TerminateProcess(hdl, EXIT_SUCCESS))
                rv = FALSE;
            CloseHandle(hdl);
        }
    } while (Process32NextW(snapHdl, &info));
    CloseHandle(snapHdl);

    return rv;
}
