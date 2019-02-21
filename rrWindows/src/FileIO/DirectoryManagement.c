/** \copyright The Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrWindows/FileIO/DirectoryManagement.h"

#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
#include <PathCch.h>
#pragma comment(lib, "pathcch.lib")
#endif
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>

#include "rrWindows/Intl/NationalLanguageSupport.h"
#include "rrWindows/Intl/UnicodeAndCharacterSets.h"
#include "rrWindows/MenuRc/Strings.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
CreateDirectoryRecursivelyA(
    _In_z_ PCSTR CONST path)
{
    PCWSTR CONST tmp = MultiByteAllocWideChar(CP_ACP, path);
    if (!tmp)
        return FALSE;
    CONST BOOL result = CreateDirectoryRecursivelyW(tmp);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
    return result;
}

static
_Success_(return != FALSE)
BOOL
WINAPI
CreateDirectoryRecursivelyW_Internal(
    _In_z_ PCWSTR CONST path)
{
    if (PathFileExistsW(path))
        return TRUE;

    SIZE_T count;
    PWSTR CONST parent = StringAllocCopyCW(path, &count);
    if (!parent)
        return FALSE;

    {
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
        CONST HRESULT hr = PathCchRemoveFileSpec(parent, count);
        if (FAILED(hr)) {
            SetLastError(ERROR_INVALID_PARAMETER);
            HeapFree(GetProcessHeap(), 0, parent);
            return FALSE;
        }
#else
        PathRemoveFileSpecW(parent);
#endif
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
    _In_z_ PCWSTR CONST path)
{
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
    PWSTR tmp = NULL;
    CONST HRESULT hr = PathAllocCanonicalize(path, PATHCCH_ALLOW_LONG_PATHS, &tmp);
    if (FAILED(hr)) {
        SetLastError(HRESULT_CODE(hr));
        return FALSE;
    }
    CONST BOOL result = CreateDirectoryRecursivelyW_Internal(tmp);
    LocalFree(tmp);
    return result;
#else
    WCHAR tmp[MAX_PATH];
    PathCanonicalizeW(tmp, path);
    return CreateDirectoryRecursivelyW_Internal(tmp);
#endif
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveDirectoryTraverselyA(
    _In_z_ PCSTR CONST path)
{
    PCWSTR CONST tmp = MultiByteAllocWideChar(CP_ACP, path);
    if (!tmp)
        return FALSE;
    CONST BOOL result = RemoveDirectoryTraverselyW(tmp);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
    return result;
}

static
_Success_(return != FALSE)
BOOL
WINAPI
RemoveDirectoryTraverselyW_Internal(
    _In_z_ PCWSTR CONST path)
{
    WIN32_FIND_DATAW data;
    HANDLE handle = INVALID_HANDLE_VALUE;
    {
        PCWSTR CONST wildcard = StringAllocCatW(path, L"\\*");
        if (!wildcard)
            return FALSE;
        handle = FindFirstFileW(wildcard, &data);
        HeapFree(GetProcessHeap(), 0, (PVOID)wildcard);
    }
    if (handle == INVALID_HANDLE_VALUE) {
        if (GetLastError() != ERROR_NO_MORE_FILES)
            return FALSE;
        if (!RemoveDirectoryW(path))
            return FALSE;
        return TRUE;
    }
    do {
        if (CompareStringInvariantW(data.cFileName, L".") != CSTR_EQUAL && CompareStringInvariantW(data.cFileName, L"..") != CSTR_EQUAL) {
            PCWSTR CONST item = StringAllocCat3W(path, L"\\", data.cFileName);
            if (!item) {
                FindClose(handle);
                return FALSE;
            }
            CONST BOOL result =
                data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ?
                RemoveDirectoryTraverselyW_Internal(item) :
                DeleteFileW(item);
            HeapFree(GetProcessHeap(), 0, (PVOID)item);
            if (!result) {
                FindClose(handle);
                return FALSE;
            }
        }
    } while (FindNextFileW(handle, &data));
    FindClose(handle);
    if (GetLastError() != ERROR_NO_MORE_FILES)
        return FALSE;
    if (!RemoveDirectoryW(path))
        return FALSE;
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveDirectoryTraverselyW(
    _In_z_ PCWSTR CONST path)
{
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
    PWSTR tmp = NULL;
    CONST HRESULT hr = PathAllocCanonicalize(path, PATHCCH_ALLOW_LONG_PATHS, &tmp);
    if (FAILED(hr)) {
        SetLastError(HRESULT_CODE(hr));
        return FALSE;
    }
    CONST BOOL result = RemoveDirectoryTraverselyW_Internal(tmp);
    LocalFree(tmp);
    return result;
#else
    WCHAR tmp[MAX_PATH];
    PathCanonicalizeW(tmp, path);
    return RemoveDirectoryTraverselyW_Internal(tmp);
#endif
}
