/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "acsshrflr.h"

#include <stdlib.h>
#include <shellapi.h>

#pragma comment(lib, "Mpr.Lib")

RRWINDOWS_API _Success_(return == NOERROR) DWORD WINAPI
ConnectSharedFolderA(
    _In_z_   LPCSTR CONST sharedFolderPath,
    _In_opt_ LPCSTR CONST username,
    _In_opt_ LPCSTR CONST password)
{
    DWORD rv = ERROR_SUCCESS;

    CONST SIZE_T tmpCnt = strlen(sharedFolderPath) + 1;
    LPSTR CONST tmp = malloc(tmpCnt * sizeof(CHAR));
    if (!tmp) {
        rv = ERROR_OUTOFMEMORY;
        goto out;
    }
    strcpy_s(tmp, tmpCnt, sharedFolderPath);

    NETRESOURCEA netRes;
    SecureZeroMemory(&netRes, sizeof(netRes));
    netRes.dwType = RESOURCETYPE_DISK;
    netRes.lpRemoteName = tmp;
    rv = WNetAddConnection2A(&netRes, password, username, CONNECT_TEMPORARY);

//out_free_tmp:
    free(tmp);
out:
    return rv;
}

RRWINDOWS_API _Success_(return == NOERROR) DWORD WINAPI
ConnectSharedFolderW(
    _In_z_   LPCWSTR CONST sharedFolderPath,
    _In_opt_ LPCWSTR CONST username,
    _In_opt_ LPCWSTR CONST password)
{
    DWORD rv = ERROR_SUCCESS;

    CONST SIZE_T tmpCnt = wcslen(sharedFolderPath) + 1;
    LPWSTR CONST tmp = malloc(tmpCnt * sizeof(WCHAR));
    if (!tmp) {
        rv = ERROR_OUTOFMEMORY;
        goto out;
    }
    wcscpy_s(tmp, tmpCnt, sharedFolderPath);

    NETRESOURCEW netRes;
    SecureZeroMemory(&netRes, sizeof(netRes));
    netRes.dwType = RESOURCETYPE_DISK;
    netRes.lpRemoteName = tmp;
    rv = WNetAddConnection2W(&netRes, password, username, CONNECT_TEMPORARY);

//out_free_tmp:
    free(tmp);
out:
    return rv;
}

RRWINDOWS_API _Success_(return == NOERROR) DWORD WINAPI
DisconnectSharedFolderA(
    _In_z_ CONST LPCSTR sharedFolderPath)
{
    return WNetCancelConnection2A(sharedFolderPath, 0, TRUE);
}

RRWINDOWS_API _Success_(return == NOERROR) DWORD WINAPI
DisconnectSharedFolderW(
    _In_z_ CONST LPCWSTR sharedFolderPath)
{
    return WNetCancelConnection2W(sharedFolderPath, 0, TRUE);
}
