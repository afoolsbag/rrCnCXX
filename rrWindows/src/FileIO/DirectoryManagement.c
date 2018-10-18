/** \copyright The Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/FileIO/DirectoryManagement.h"

#include <PathCch.h>
#pragma comment(lib, "pathcch.lib")
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>

static
_Success_(return != FALSE)
BOOL
WINAPI
CreateDirectoryRecursivelyW_Internal(
    _In_z_ LPCWSTR CONST path)
{
    BOOL result = TRUE;

    if (PathFileExistsW(path))
        return TRUE;

    size_t length;
    {
        CONST HRESULT hr = StringCchLengthW(path, STRSAFE_MAX_CCH, &length);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            return FALSE;
        }
    }
    CONST size_t size = length + 1;
    LPWSTR CONST parent = HeapAlloc(GetProcessHeap(), 0, size * sizeof(WCHAR));
    if (!parent) {
        SetLastError(ERROR_OUTOFMEMORY);
        return FALSE;
    }
    {
        CONST HRESULT hr = StringCchCopyW(parent, size, path);
        if (FAILED(hr)) {
            SetLastError(HRESULT_CODE(hr));
            result = FALSE;
            goto exit_free_parent;
        }
    }
    {
        CONST HRESULT hr = PathCchRemoveFileSpec(parent, size);
        if (FAILED(hr)) {
            SetLastError(ERROR_INVALID_PARAMETER);
            result = FALSE;
            goto exit_free_parent;
        }
    }

    if (!CreateDirectoryRecursivelyW_Internal(parent)) {
        result = FALSE;
        goto exit_free_parent;
    }

    if (!CreateDirectoryW(path, NULL))
        result = FALSE;

exit_free_parent:
    if (!HeapFree(GetProcessHeap(), 0, parent))
        result = FALSE;
    return result;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
CreateDirectoryRecursivelyW(
    _In_z_ LPCWSTR CONST path)
{
    PWSTR tmp = NULL;
    CONST HRESULT hr = PathAllocCanonicalize(path, PATHCCH_ALLOW_LONG_PATHS, &tmp);
    if (FAILED(hr)) {
        SetLastError(HRESULT_CODE(hr));
        return FALSE;
    }

    CONST BOOL result = CreateDirectoryRecursivelyW_Internal(tmp);

    LocalFree(tmp);
    return result;
}
