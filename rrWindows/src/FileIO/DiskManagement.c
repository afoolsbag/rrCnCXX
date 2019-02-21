/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrWindows/FileIO/DiskManagement.h"

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")

#include "rrWindows/MenuRc/Strings.h"

RRWINDOWS_API
_Success_(return != 0)
ULARGE_INTEGER
WINAPI
GetFolderFreeSpaceA(
    _In_z_ LPCSTR CONST folderPath)
{
    ULARGE_INTEGER rv = {.QuadPart = 0};
    CONST SIZE_T siz = (StringCchLengthSA(folderPath) + 1) * sizeof(CHAR);
    CHAR *CONST tmp = (CHAR *)HeapAlloc(GetProcessHeap(), 0, siz);
    if (NULL == tmp) {
        SetLastError(ERROR_OUTOFMEMORY);
        return rv;
    }
    CONST HRESULT hr = StringCbCopyA(tmp, siz, folderPath);
    if (FAILED(hr)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(HRESULT_CODE(hr));
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

RRWINDOWS_API
_Success_(return != 0)
ULARGE_INTEGER
WINAPI
GetFolderFreeSpaceW(
    _In_z_ LPCWSTR CONST folderPath)
{
    ULARGE_INTEGER rv = {.QuadPart = 0};
    CONST SIZE_T siz = (StringCchLengthSW(folderPath) + 1) * sizeof(WCHAR);
    WCHAR *CONST tmp = (WCHAR *)HeapAlloc(GetProcessHeap(), 0, siz);
    if (NULL == tmp) {
        SetLastError(ERROR_OUTOFMEMORY);
        return rv;
    }
    CONST HRESULT hr = StringCbCopyW(tmp, siz, folderPath);
    if (FAILED(hr)) {
        HeapFree(GetProcessHeap(), 0, tmp);
        SetLastError(HRESULT_CODE(hr));
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
