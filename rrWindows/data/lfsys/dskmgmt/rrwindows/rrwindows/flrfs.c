/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "flrfs.h"

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")

#include "rrwindows/winstr.h"

RRWINDOWS_API _Success_(return != 0) ULARGE_INTEGER WINAPI
GetFolderFreeSpaceA(
    _In_z_ LPCSTR CONST folderPath)
{
    ULARGE_INTEGER rv = {.QuadPart = 0};
    HRESULT hrslt = SEC_E_OK;
    CONST SIZE_T siz = (StrLenA(folderPath) + 1) * sizeof(CHAR);
    CHAR *CONST tmp = (CHAR *)HeapAlloc(GetProcessHeap(), 0, siz);
    if (NULL == tmp) {
        SetLastError(ERROR_OUTOFMEMORY);
        return rv;
    }
    if (FAILED(hrslt = StringCbCopyA(tmp, siz, folderPath))) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(HRESULT_CODE(hrslt));
        return rv;
    }
    if (!PathStripToRootA(tmp)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(ERROR_INVALID_PARAMETER);
        return rv;
    }
    if (!GetDiskFreeSpaceExA(tmp, &rv, NULL, NULL)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        return rv;
    }
    HeapFree(GetProcessHeap(), 0, tmp);
    return rv;
}

RRWINDOWS_API _Success_(return != 0) ULARGE_INTEGER WINAPI
GetFolderFreeSpaceW(
    _In_z_ LPCWSTR CONST folderPath)
{
    ULARGE_INTEGER rv = {.QuadPart = 0};
    HRESULT hrslt = SEC_E_OK;
    CONST SIZE_T siz = (StrLenW(folderPath) + 1) * sizeof(WCHAR);
    WCHAR *CONST tmp = (WCHAR *)HeapAlloc(GetProcessHeap(), 0, siz);
    if (NULL == tmp) {
        SetLastError(ERROR_OUTOFMEMORY);
        return rv;
    }
    if (FAILED(hrslt = StringCbCopyW(tmp, siz, folderPath))) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(HRESULT_CODE(hrslt));
        return rv;
    }
    if (!PathStripToRootW(tmp)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(ERROR_INVALID_PARAMETER);
        return rv;
    }
    if (!GetDiskFreeSpaceExW(tmp, &rv, NULL, NULL)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        return rv;
    }
    HeapFree(GetProcessHeap(), 0, tmp);
    return rv;
}
