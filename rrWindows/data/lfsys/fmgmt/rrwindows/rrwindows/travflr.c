/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "travflr.h"

#include <stdlib.h>
#include <strsafe.h>

#include "rrwindows/winstr.h"

RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
TraverseFolderA(
    _In_z_                   LPCSTR CONST folderPath,
    _In_   OnFileFoundCallbackTypeA CONST OnFileFound,
    _In_                      CONST BOOL  recurse)
{
    CHAR wildcardPath[MAX_PATH];
    if (FAILED(StringCchCopyA(wildcardPath, _countof(wildcardPath), folderPath)))
        return ERROR_INVALID_PARAMETER;
    if (FAILED(StringCchCatA(wildcardPath, _countof(wildcardPath), "\\*")))
        return ERROR_INVALID_PARAMETER;

    DWORD rv = ERROR_SUCCESS;

    WIN32_FIND_DATAA data;
    SecureZeroMemory(&data, sizeof(data));

    HANDLE handle = INVALID_HANDLE_VALUE;
    if (INVALID_HANDLE_VALUE == (handle = FindFirstFileA(wildcardPath, &data))) {
        if (GetLastError() == ERROR_NO_MORE_FILES) {
            goto out_close_handle;
        } else {
            rv = GetLastError(); goto out;
        }
    }
    CHAR itemPath[MAX_PATH];
    do {
        if (FAILED(StringCchCopyA(itemPath, _countof(itemPath), folderPath))) {
            rv = ERROR_INVALID_PARAMETER; goto out_close_handle;
        }
        if (FAILED(StringCchCatA(itemPath, _countof(itemPath), "\\"))) {
            rv = ERROR_INVALID_PARAMETER; goto out_close_handle;
        }
        if (FAILED(StringCchCatA(itemPath, _countof(itemPath), data.cFileName))) {
            rv = ERROR_INVALID_PARAMETER; goto out_close_handle;
        }
        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && (CSTR_EQUAL == CmpStrA(data.cFileName, ".") || CSTR_EQUAL == CmpStrA(data.cFileName, "..")))
            continue;
        if (recurse && data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            if (ERROR_SUCCESS != (rv = TraverseFolderA(itemPath, OnFileFound, recurse)))
                goto out_close_handle;
        if (ERROR_SUCCESS != (rv = OnFileFound(itemPath, &data)))
            goto out_close_handle;
    } while (FindNextFileA(handle, &data));
    if (GetLastError() != ERROR_NO_MORE_FILES)
        rv = GetLastError();

out_close_handle:
    FindClose(handle);
out:
    return rv;
}

RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
TraverseFolderW(
    _In_z_                  LPCWSTR CONST folderPath,
    _In_   OnFileFoundCallbackTypeW CONST OnFileFound,
    _In_                      CONST BOOL  recurse)
{
    WCHAR wildcardPath[MAX_PATH];
    if (FAILED(StringCchCopyW(wildcardPath, _countof(wildcardPath), folderPath)))
        return ERROR_INVALID_PARAMETER;
    if (FAILED(StringCchCatW(wildcardPath, _countof(wildcardPath), L"\\*")))
        return ERROR_INVALID_PARAMETER;

    DWORD rv = ERROR_SUCCESS;

    WIN32_FIND_DATAW data;
    HANDLE handle = INVALID_HANDLE_VALUE;
    if (INVALID_HANDLE_VALUE == (handle = FindFirstFileW(wildcardPath, &data))) {
        if (GetLastError() == ERROR_NO_MORE_FILES) {
            goto out_close_handle;
        } else {
            rv = GetLastError(); goto out;
        }
    }
    WCHAR itemPath[MAX_PATH];
    do {
        if (FAILED(StringCchCopyW(itemPath, _countof(itemPath), folderPath))) {
            rv = ERROR_INVALID_PARAMETER; goto out_close_handle;
        }
        if (FAILED(StringCchCatW(itemPath, _countof(itemPath), L"\\"))) {
            rv = ERROR_INVALID_PARAMETER; goto out_close_handle;
        }
        if (FAILED(StringCchCatW(itemPath, _countof(itemPath), data.cFileName))) {
            rv = ERROR_INVALID_PARAMETER; goto out_close_handle;
        }
        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && (CSTR_EQUAL == CmpStrW(data.cFileName, L".") || CSTR_EQUAL == CmpStrW(data.cFileName, L"..")))
            continue;
        if (recurse && data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            if (ERROR_SUCCESS != (rv = TraverseFolderW(itemPath, OnFileFound, recurse)))
                goto out_close_handle;
        if (ERROR_SUCCESS != (rv = OnFileFound(itemPath, &data)))
            goto out_close_handle;
    } while (FindNextFileW(handle, &data));
    if (GetLastError() != ERROR_NO_MORE_FILES)
        rv = GetLastError();

out_close_handle:
    FindClose(handle);
out:
    return rv;
}
