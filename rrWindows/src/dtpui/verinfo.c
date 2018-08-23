/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "rrwindows/dtpui/verinfo.h"

#pragma comment(lib, "Version.Lib")

#include "rrwindows/svc/memsim.h"

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
    LPVOID CONST buf = HeapAllocS(siz);
    if (NULL == buf) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }
    if (!GetFileVersionInfoA(filePath, 0, siz, buf)) {
        HeapFreeS(buf);
        return FALSE;
    }
    VS_FIXEDFILEINFO *tmp;
    UINT len;
    if (!VerQueryValueA(buf, "\\", (LPVOID *)&tmp, &len)) {
        HeapFreeS(buf);
        return FALSE;
    }
    CopyMemory(pFixedInfo, tmp, min(len, sizeof(VS_FIXEDFILEINFO)));
    HeapFreeS(buf);
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
    LPVOID CONST buf = HeapAllocS(siz);
    if (NULL == buf) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }
    if (!GetFileVersionInfoW(filePath, 0, siz, buf)) {
        HeapFreeS(buf);
        return FALSE;
    }
    VS_FIXEDFILEINFO *tmp;
    UINT len;
    if (!VerQueryValueW(buf, L"\\", (LPVOID *)&tmp, &len)) {
        HeapFreeS(buf);
        return FALSE;
    }
    CopyMemory(pFixedInfo, tmp, min(len, sizeof(VS_FIXEDFILEINFO)));
    HeapFreeS(buf);
    return TRUE;
}
