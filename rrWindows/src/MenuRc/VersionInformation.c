/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrwindows/MenuRc/VersionInformation.h"

#pragma comment(lib, "Version.Lib")

#include "rrwindows/Memory/MemoryManagement.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileFixedInformationA(
    _In_z_          LPCSTR  CONST filePath,
    _Out_ VS_FIXEDFILEINFO *CONST pFixedInfo)
{
    CONST DWORD siz = GetFileVersionInfoSizeA(filePath, NULL);
    if (siz == 0)
        return FALSE;
    LPVOID CONST buf = HeapAlloc_Simplify(siz);
    if (NULL == buf) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }
    if (!GetFileVersionInfoA(filePath, 0, siz, buf)) {
        HeapFree_Simplify(buf);
        return FALSE;
    }
    VS_FIXEDFILEINFO *tmp;
    UINT len;
    if (!VerQueryValueA(buf, "\\", (LPVOID *)&tmp, &len)) {
        HeapFree_Simplify(buf);
        return FALSE;
    }
    CopyMemory(pFixedInfo, tmp, min(len, sizeof(VS_FIXEDFILEINFO)));
    HeapFree_Simplify(buf);
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileFixedInformationW(
    _In_z_         LPCWSTR  CONST filePath,
    _Out_ VS_FIXEDFILEINFO *CONST pFixedInfo)
{
    CONST DWORD siz = GetFileVersionInfoSizeW(filePath, NULL);
    if (siz == 0)
        return FALSE;
    LPVOID CONST buf = HeapAlloc_Simplify(siz);
    if (NULL == buf) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }
    if (!GetFileVersionInfoW(filePath, 0, siz, buf)) {
        HeapFree_Simplify(buf);
        return FALSE;
    }
    VS_FIXEDFILEINFO *tmp;
    UINT len;
    if (!VerQueryValueW(buf, L"\\", (LPVOID *)&tmp, &len)) {
        HeapFree_Simplify(buf);
        return FALSE;
    }
    CopyMemory(pFixedInfo, tmp, min(len, sizeof(VS_FIXEDFILEINFO)));
    HeapFree_Simplify(buf);
    return TRUE;
}