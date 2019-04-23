/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrWindows/ProcThread/ProcessesAndThreads.h"

#undef UNICODE
#include <TlHelp32.h>
#include <WtsApi32.h>
#pragma comment(lib, "WtsApi32.Lib")

#include "rrWindows/MenuRc/Strings.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableA(
    _In_z_     PCSTR path,
    _In_opt_z_ PCSTR args,
    _In_opt_z_ PCSTR startIn,
    _In_       BOOL  show)
{
    CONST size_t pathLen = StringCchLengthSA(path);

    PSTR cmdBuf = NULL;
    if (args) {
        CONST size_t cmdCnt = pathLen + 1/*' '*/ + StringCchLengthSA(args) + 1/*'\0'*/;
        cmdBuf = HeapAlloc(GetProcessHeap(), 0, cmdCnt * sizeof(CHAR));
        if (!cmdBuf) {
            SetLastError(ERROR_OUTOFMEMORY);
            return FALSE;
        }
        CONST HRESULT hr1 = StringCchCopyA(cmdBuf, cmdCnt, path);
        if (FAILED(hr1)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr1));
            return FALSE;
        }
        cmdBuf[pathLen] = ' ';
        CONST HRESULT hr2 = StringCchCopyA(cmdBuf + pathLen + 1, cmdCnt - pathLen - 1, args);
        if (FAILED(hr2)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr2));
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
    _In_z_     PCWSTR path,
    _In_opt_z_ PCWSTR args,
    _In_opt_z_ PCWSTR startIn,
    _In_       BOOL   show)
{
    CONST size_t pathLen = StringCchLengthSW(path);

    PWSTR cmdBuf = NULL;
    if (args) {
        CONST size_t cmdCnt = pathLen + 1/*L' '*/ + StringCchLengthSW(args) + 1/*L'\0'*/;
        cmdBuf = HeapAlloc(GetProcessHeap(), 0, cmdCnt * sizeof(WCHAR));
        if (!cmdBuf) {
            SetLastError(ERROR_OUTOFMEMORY);
            return FALSE;
        }
        CONST HRESULT hr1 = StringCchCopyW(cmdBuf, cmdCnt, path);
        if (FAILED(hr1)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr1));
            return FALSE;
        }
        cmdBuf[pathLen] = L' ';
        CONST HRESULT hr2 = StringCchCopyW(cmdBuf + pathLen + 1, cmdCnt - pathLen - 1, args);
        if (FAILED(hr2)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr2));
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
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableAsActiveA(
    _In_z_     PCSTR path,
    _In_opt_z_ PCSTR args,
    _In_opt_z_ PCSTR startIn,
    _In_       BOOL  show)
{
    BOOL rv = FALSE;

    PSTR cmdBuf = NULL;
    HANDLE activeToken = NULL;

    CONST size_t pathLen = StringCchLengthSA(path);
    if (args) {
        CONST size_t cmdCnt = pathLen + 1/*' '*/ + StringCchLengthSA(args) + 1/*'\0'*/;
        cmdBuf = HeapAlloc(GetProcessHeap(), 0, cmdCnt * sizeof(CHAR));
        if (!cmdBuf) {
            SetLastError(ERROR_OUTOFMEMORY);
            goto exit;
        }
        CONST HRESULT hr1 = StringCchCopyA(cmdBuf, cmdCnt, path);
        if (FAILED(hr1)) {
            SetLastError(HRESULT_CODE(hr1));
            goto exit;
        }
        cmdBuf[pathLen] = ' ';
        CONST HRESULT hr2 = StringCchCopyA(cmdBuf + pathLen + 1, cmdCnt - pathLen - 1, args);
        if (FAILED(hr2)) {
            SetLastError(HRESULT_CODE(hr2));
            goto exit;
        }
    }

    CONST DWORD activeSessionId = WTSGetActiveConsoleSessionId();
    if (!WTSQueryUserToken(activeSessionId, &activeToken))
        goto exit;

    STARTUPINFOA startupInfo;
    ZeroMemory(&startupInfo, sizeof startupInfo);
    startupInfo.cb = sizeof startupInfo;
    startupInfo.lpDesktop = "WinSta0\\Default";
    startupInfo.dwFlags = STARTF_USESHOWWINDOW;
    startupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION procInfo;
    rv = CreateProcessAsUserA(activeToken, path, cmdBuf, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, startIn, &startupInfo, &procInfo);
    if (rv) {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }

exit:
    if (cmdBuf)
        HeapFree(GetProcessHeap(), 0, cmdBuf);
    if (activeToken)
        CloseHandle(activeToken);

    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableAsActiveW(
    _In_z_     PCWSTR path,
    _In_opt_z_ PCWSTR args,
    _In_opt_z_ PCWSTR startIn,
    _In_       BOOL   show)
{
    BOOL rv = FALSE;

    PWSTR cmdBuf = NULL;
    HANDLE activeToken = NULL;

    CONST size_t pathLen = StringCchLengthSW(path);
    if (args) {
        CONST size_t cmdCnt = pathLen + 1/*L' '*/ + StringCchLengthSW(args) + 1/*L'\0'*/;
        cmdBuf = HeapAlloc(GetProcessHeap(), 0, cmdCnt * sizeof(WCHAR));
        if (!cmdBuf) {
            SetLastError(ERROR_OUTOFMEMORY);
            return FALSE;
        }
        CONST HRESULT hr1 = StringCchCopyW(cmdBuf, cmdCnt, path);
        if (FAILED(hr1)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr1));
            return FALSE;
        }
        cmdBuf[pathLen] = L' ';
        CONST HRESULT hr2 = StringCchCopyW(cmdBuf + pathLen + 1, cmdCnt - pathLen - 1, args);
        if (FAILED(hr2)) {
            HeapFree(GetProcessHeap(), 0, cmdBuf);
            SetLastError(HRESULT_CODE(hr2));
            return FALSE;
        }
    }

    CONST DWORD activeSessionId = WTSGetActiveConsoleSessionId();
    if (!WTSQueryUserToken(activeSessionId, &activeToken))
        goto exit;

    STARTUPINFOW startupInfo;
    ZeroMemory(&startupInfo, sizeof startupInfo);
    startupInfo.cb = sizeof startupInfo;
    startupInfo.lpDesktop = L"WinSta0\\Default";
    startupInfo.dwFlags = STARTF_USESHOWWINDOW;
    startupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION procInfo;
    rv = CreateProcessAsUserW(activeToken, path, cmdBuf, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, startIn, &startupInfo, &procInfo);
    if (rv) {
        CloseHandle(procInfo.hProcess);
        CloseHandle(procInfo.hThread);
    }

exit:
    if (cmdBuf)
        HeapFree(GetProcessHeap(), 0, cmdBuf);
    if (activeToken)
        CloseHandle(activeToken);

    return rv;
}

RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
KillExecutableA(
    _In_z_ PCSTR exeName)
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
        if (CSTR_EQUAL != CompareStringSA(exeName, info.szExeFile))
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
    _In_z_ PCWSTR exeName)
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
        if (CSTR_EQUAL != CompareStringSW(exeName, info.szExeFile))
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
