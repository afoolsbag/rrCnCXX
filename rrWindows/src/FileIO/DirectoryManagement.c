/** \copyright The Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/FileIO/DirectoryManagement.h"

#include <PathCch.h>
#pragma comment(lib, "pathcch.lib")
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>

#include "rrwindows/MenuRc/Strings.h"

static
_Success_(return != FALSE)
BOOL
WINAPI
CreateDirectoryRecursivelyW_Internal(
    _In_z_ LPCWSTR CONST path)
{
    if (PathFileExistsW(path))
        return TRUE;

    PWSTR parent = NULL;
    const size_t count = StringAllocCopyW(path, &parent);
    if (!count)
        return FALSE;

    {
        CONST HRESULT hr = PathCchRemoveFileSpec(parent, count);
        if (FAILED(hr)) {
            SetLastError(ERROR_INVALID_PARAMETER);
            HeapFree(GetProcessHeap(), 0, parent);
            return FALSE;
        }
    }

    if (!CreateDirectoryRecursivelyW_Internal(parent)) {
        HeapFree(GetProcessHeap(), 0, parent);
        return FALSE;
    }
    HeapFree(GetProcessHeap(), 0, parent);

    if (!CreateDirectoryW(path, NULL))
        return FALSE;
    return TRUE;
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
