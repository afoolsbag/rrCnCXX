/** \copyright Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/ProcThread/ProcessesAndThreads.h"

#undef UNICODE
#include <TlHelp32.h>

#include "rrwindows/MenuRc/Strings.h"

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableA(
    _In_z_     PCSTR CONST path,
    _In_opt_z_ PCSTR CONST command,
    _In_opt_z_ PCSTR CONST startIn,
    _In_       CONST BOOL  show)
{
    PSTR cmdBuf = NULL;
    if (command) {
        CONST size_t cmdBufCnt = 1/*' '*/ + StringCchLength_SimplifyA(command) + 1/*'\0'*/;
        cmdBuf = HeapAlloc(GetProcessHeap(), 0, cmdBufCnt * sizeof(CHAR));
        if (!cmdBuf) {
            SetLastError(ERROR_OUTOFMEMORY);
            return FALSE;
        }
        cmdBuf[0] = ' ';
        CONST HRESULT hr = StringCchCopyA(cmdBuf + 1, cmdBufCnt - 1, command);
        if (FAILED(hr)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr));
            return FALSE;
        }
    }

    STARTUPINFOA startupInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    startupInfo.dwFlags = STARTF_USESHOWWINDOW;
    startupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION procInfo;

    CONST BOOL succ = CreateProcessA(path, cmdBuf, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, startIn, &startupInfo, &procInfo);

    if (succ) {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }

    if (cmdBuf)
        HeapFree(GetProcessHeap(), 0, cmdBuf);

    return succ;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableW(
    _In_z_     PCWSTR CONST path,
    _In_opt_z_ PCWSTR CONST command,
    _In_opt_z_ PCWSTR CONST startIn,
    _In_        CONST BOOL  show)
{
    PWSTR cmdBuf = NULL;
    if (command) {
        CONST size_t cmdBufCnt = 1/*L' '*/ + StringCchLength_SimplifyW(command) + 1/*L'\0'*/;
        cmdBuf = HeapAlloc(GetProcessHeap(), 0, cmdBufCnt * sizeof(WCHAR));
        if (!cmdBuf) {
            SetLastError(ERROR_OUTOFMEMORY);
            return FALSE;
        }
        cmdBuf[0] = L' ';
        CONST HRESULT hr = StringCchCopyW(cmdBuf + 1, cmdBufCnt - 1, command);
        if (FAILED(hr)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr));
            return FALSE;
        }
    }

    STARTUPINFOW startupInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    startupInfo.dwFlags = STARTF_USESHOWWINDOW;
    startupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION procInfo;

    CONST BOOL succ = CreateProcessW(path, cmdBuf, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, startIn, &startupInfo, &procInfo);

    if (succ) {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }

    if (cmdBuf)
        HeapFree(GetProcessHeap(), 0, cmdBuf);

    return succ;
}

RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
KillExecutableA(
    _In_z_ CONST PCSTR exeName)
{
    INT cnt = 0;

    HANDLE CONST snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE)
        goto err;

    PROCESSENTRY32 info;
    info.dwSize = sizeof(info);
    if (!Process32First(snap, &info))
        goto out_clssnap;
    do {
        if (CSTR_EQUAL != CompareString_SimplifyA(exeName, info.szExeFile))
            continue;
        HANDLE CONST hdl = OpenProcess(PROCESS_TERMINATE, FALSE, info.th32ProcessID);
        if (NULL == hdl)
            goto err_clssnap;
        if (!TerminateProcess(hdl, EXIT_FAILURE))
            ++cnt;
        if (!CloseHandle(hdl))
            goto err_clssnap;
    } while (Process32Next(snap, &info));

out_clssnap:
    if (!CloseHandle(snap))
        return -1;

    return cnt;

err_clssnap:
    CloseHandle(snap);
err:
    return -1;
}

RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
KillExecutableW(
    _In_z_ CONST PCWSTR exeName)
{
    INT cnt = 0;

    HANDLE CONST snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE)
        goto err;

    PROCESSENTRY32W info;
    info.dwSize = sizeof(info);
    if (!Process32FirstW(snap, &info))
        goto out_clssnap;
    do {
        if (CSTR_EQUAL != CompareString_SimplifyW(exeName, info.szExeFile))
            continue;
        HANDLE CONST hdl = OpenProcess(PROCESS_TERMINATE, FALSE, info.th32ProcessID);
        if (NULL == hdl)
            goto err_clssnap;
        if (!TerminateProcess(hdl, EXIT_FAILURE))
            ++cnt;
        if (!CloseHandle(hdl))
            goto err_clssnap;
    } while (Process32NextW(snap, &info));

out_clssnap:
    if (!CloseHandle(snap))
        return -1;

    return cnt;

err_clssnap:
    CloseHandle(snap);
err:
    return -1;
}