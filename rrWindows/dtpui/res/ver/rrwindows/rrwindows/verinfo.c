/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "verinfo.h"

#pragma comment(lib, "Version.Lib")

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileVersionInformationA(
    _In_z_    LPCSTR CONST filePath,
    _Out_opt_ LPWORD CONST pMajor,
    _Out_opt_ LPWORD CONST pMinor,
    _Out_opt_ LPWORD CONST pPatch,
    _Out_opt_ LPWORD CONST pTweak)
{
    CONST DWORD siz = GetFileVersionInfoSizeA(filePath, NULL);
    if (siz == 0)
        return FALSE;
    LPVOID CONST buf = HeapAlloc(GetProcessHeap(), 0, siz);
    if (NULL == buf) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }
    if (!GetFileVersionInfoA(filePath, 0, siz, buf)) {
        HeapFree(GetProcessHeap(), 0, buf);
        return FALSE;
    }
    VS_FIXEDFILEINFO *ver;
    UINT len;
    if (!VerQueryValueA(buf, "\\", (LPVOID *)&ver, &len)) {
        HeapFree(GetProcessHeap(), 0, buf);
        return FALSE;
    }
    if (NULL != pMajor)
        *pMajor = HIWORD(ver->dwFileVersionMS);
    if (NULL != pMinor)
        *pMinor = LOWORD(ver->dwFileVersionMS);
    if (NULL != pPatch)
        *pPatch = HIWORD(ver->dwFileVersionLS);
    if (NULL != pTweak)
        *pTweak = LOWORD(ver->dwFileVersionLS);
    HeapFree(GetProcessHeap(), 0, buf);
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileVersionInformationW(
    _In_z_   LPCWSTR CONST filePath,
    _Out_opt_ LPWORD CONST pMajor,
    _Out_opt_ LPWORD CONST pMinor,
    _Out_opt_ LPWORD CONST pPatch,
    _Out_opt_ LPWORD CONST pTweak)
{
    CONST DWORD siz = GetFileVersionInfoSizeW(filePath, NULL);
    if (siz == 0)
        return FALSE;
    LPVOID CONST buf = HeapAlloc(GetProcessHeap(), 0, siz);
    if (NULL == buf) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }
    if (!GetFileVersionInfoW(filePath, 0, siz, buf)) {
        HeapFree(GetProcessHeap(), 0, buf);
        return FALSE;
    }
    VS_FIXEDFILEINFO *ver;
    UINT len;
    if (!VerQueryValueW(buf, L"\\", (LPVOID *)&ver, &len)) {
        HeapFree(GetProcessHeap(), 0, buf);
        return FALSE;
    }
    if (NULL != pMajor)
        *pMajor = HIWORD(ver->dwFileVersionMS);
    if (NULL != pMinor)
        *pMinor = LOWORD(ver->dwFileVersionMS);
    if (NULL != pPatch)
        *pPatch = HIWORD(ver->dwFileVersionLS);
    if (NULL != pTweak)
        *pTweak = LOWORD(ver->dwFileVersionLS);
    HeapFree(GetProcessHeap(), 0, buf);
    return TRUE;
}
