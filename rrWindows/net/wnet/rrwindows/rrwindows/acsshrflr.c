/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "acsshrflr.h"

#include <shellapi.h>
#pragma comment(lib, "Mpr.Lib")

#include "rrwindows/strsim.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ConnectSharedFolderA(
    _In_z_   LPCSTR CONST sharedFolderPath,
    _In_opt_ LPCSTR CONST username,
    _In_opt_ LPCSTR CONST password)
{
    CONST SIZE_T tmpCnt = StringCchLengthAs(sharedFolderPath) + 1;
    LPSTR CONST tmp = HeapAlloc(GetProcessHeap(), 0, tmpCnt * sizeof(CHAR));
    if (NULL == tmp) {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }
    CONST HRESULT hr = StringCchCopyA(tmp, tmpCnt, sharedFolderPath);
    if (FAILED(hr)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(HRESULT_CODE(hr));
        return FALSE;
    }
    NETRESOURCEA netRes;
    ZeroMemory(&netRes, sizeof(netRes));
    netRes.dwType = RESOURCETYPE_DISK;
    netRes.lpRemoteName = tmp;
    CONST DWORD ec = WNetAddConnection2A(&netRes, password, username, CONNECT_TEMPORARY);
    if (NOERROR != ec) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(ec);
        return FALSE;
    }
    HeapFree(GetProcessHeap(), 0, tmp);
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ConnectSharedFolderW(
    _In_z_   LPCWSTR CONST sharedFolderPath,
    _In_opt_ LPCWSTR CONST username,
    _In_opt_ LPCWSTR CONST password)
{
    CONST SIZE_T tmpCnt = StringCchLengthWs(sharedFolderPath) + 1;
    LPWSTR CONST tmp = HeapAlloc(GetProcessHeap(), 0, tmpCnt * sizeof(WCHAR));
    if (NULL == tmp) {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return FALSE;
    }
    CONST HRESULT hr = StringCchCopyW(tmp, tmpCnt, sharedFolderPath);
    if (FAILED(hr)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(HRESULT_CODE(hr));
        return FALSE;
    }
    NETRESOURCEW netRes;
    ZeroMemory(&netRes, sizeof(netRes));
    netRes.dwType = RESOURCETYPE_DISK;
    netRes.lpRemoteName = tmp;
    CONST DWORD ec = WNetAddConnection2W(&netRes, password, username, CONNECT_TEMPORARY);
    if (NOERROR != ec) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(ec);
        return FALSE;
    }
    HeapFree(GetProcessHeap(), 0, tmp);
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
DisconnectSharedFolderA(
    _In_z_ CONST LPCSTR sharedFolderPath)
{
    CONST DWORD ec = WNetCancelConnection2A(sharedFolderPath, 0, TRUE);
    if (NO_ERROR != ec) {
        SetLastError(ec);
        return FALSE;
    }
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
DisconnectSharedFolderW(
    _In_z_ CONST LPCWSTR sharedFolderPath)
{
    CONST DWORD ec = WNetCancelConnection2W(sharedFolderPath, 0, TRUE);
    if (NO_ERROR != ec) {
        SetLastError(ec);
        return FALSE;
    }
    return TRUE;
}
