/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "rmflr.h"

#include <strsafe.h>

#include "rrwindows/travflr.h"

static DWORD CALLBACK
OnFileFoundA(LPCSTR CONST path, LPWIN32_FIND_DATAA CONST pData)
{
    if (pData->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        if (!RemoveDirectoryA(path))
            return GetLastError();
    } else {
        if (!DeleteFileA(path))
            return GetLastError();
    }
    return ERROR_SUCCESS;
}

static DWORD CALLBACK
OnFileFoundW(LPCWSTR CONST path, LPWIN32_FIND_DATAW CONST pData)
{
    if (pData->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        if (!RemoveDirectoryW(path))
            return GetLastError();
    } else {
        if (!DeleteFileW(path))
            return GetLastError();
    }
    return ERROR_SUCCESS;
}

RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
RemoveFolderA(
    _In_z_ LPCSTR CONST folderPath)
{
    DWORD rv = ERROR_SUCCESS;
    if (ERROR_SUCCESS != (rv = TraverseFolderA(folderPath, OnFileFoundA, TRUE)))
        return rv;
    if (!RemoveDirectoryA(folderPath))
        return GetLastError();
    return ERROR_SUCCESS;
}

RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
RemoveFolderW(
    _In_z_ LPCWSTR CONST folderPath)
{
    DWORD rv = ERROR_SUCCESS;
    if (ERROR_SUCCESS != (rv = TraverseFolderW(folderPath, OnFileFoundW, TRUE)))
        return rv;
    if (!RemoveDirectoryW(folderPath))
        return GetLastError();
    return ERROR_SUCCESS;
}
