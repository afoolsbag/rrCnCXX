/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "cr8flr.h"

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>

static _Success_(return == ERROR_SUCCESS) DWORD WINAPI
RecursiveCreateFolderA(
    _In_z_ LPCSTR CONST folderPath)
{
    if (PathFileExistsA(folderPath))
        return ERROR_SUCCESS;

    HRESULT hr = SEC_E_OK;
    DWORD ec = ERROR_SUCCESS;

    CHAR basePath[MAX_PATH];
    if (FAILED(hr = StringCchCopyA(basePath, _countof(basePath), folderPath)))
        return HRESULT_CODE(hr);
    if (!PathRemoveFileSpecA(basePath))
        return ERROR_INVALID_PARAMETER;

    if (!PathFileExistsA(basePath) && ERROR_SUCCESS != (ec = RecursiveCreateFolderA(basePath)))
        return ec;
    if (!CreateDirectoryA(folderPath, NULL))
        return GetLastError();

    return ERROR_SUCCESS;
}

static _Success_(return == ERROR_SUCCESS) DWORD WINAPI
RecursiveCreateFolderW(
    _In_z_ LPCWSTR CONST folderPath)
{
    if (PathFileExistsW(folderPath))
        return ERROR_SUCCESS;

    HRESULT hr = SEC_E_OK;
    DWORD ec = ERROR_SUCCESS;

    WCHAR basePath[MAX_PATH];
    if (FAILED(hr = StringCchCopyW(basePath, _countof(basePath), folderPath)))
        return HRESULT_CODE(hr);
    if (!PathRemoveFileSpecW(basePath))
        return ERROR_INVALID_PARAMETER;

    if (!PathFileExistsW(basePath) && ERROR_SUCCESS != (ec = RecursiveCreateFolderW(basePath)))
        return ec;
    if (!CreateDirectoryW(folderPath, NULL))
        return GetLastError();

    return ERROR_SUCCESS;
}

RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
CreateFolderA(
    _In_z_ LPCSTR CONST folderPath)
{
    CHAR flrPath[MAX_PATH];
    if (!PathCanonicalizeA(flrPath, folderPath))
        return GetLastError();
    return RecursiveCreateFolderA(flrPath);
}

RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
CreateFolderW(
    _In_z_ LPCWSTR CONST folderPath)
{
    WCHAR flrPath[MAX_PATH];
    if (!PathCanonicalizeW(flrPath, folderPath))
        return GetLastError();
    return RecursiveCreateFolderW(flrPath);
}
