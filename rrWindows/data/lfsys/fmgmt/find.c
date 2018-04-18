/*===-- Find File ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup g_find 查找文件
 * \ingroup g_fmgmt
 *
 * \version 2018-04-16
 * \since 2018-01-15
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <windows.h>

typedef VOID(*OnFolderFoundCallbackType)(LPCTSTR folderName, LPCTSTR folderPath);
typedef VOID(*OnFileFoundCallbackType)(LPCTSTR fileName, LPCTSTR filePath);

/// \brief 遍历文件夹。
/// \param folderPath    欲遍历的文件夹路径。
/// \param OnFolderFound 当找到子文件夹时的回调。
/// \param OnFileFound   当找到文件时的回调。
/// \param recurse       遍历。
/// \returns 零：成功；非零：失败，正：`errno.h`，`-1`；无效参数，`-2`：`winerror.h`。
///
/// \sa ["FindFirstFile function"](https://msdn.microsoft.com/library/aa364418). *Microsoft® Developer Network*.
/// \sa ["FindNextFile function"](https://msdn.microsoft.com/library/aa364428). *Microsoft® Developer Network*.
/// \sa ["FindClose function"](https://msdn.microsoft.com/library/aa364413). *Microsoft® Developer Network*.
errno_t TraverseFolder(CONST LPCTSTR folderPath, OnFolderFoundCallbackType OnFolderFound, OnFileFoundCallbackType OnFileFound, BOOL recurse)
{
    errno_t status = NOERROR;
    TCHAR wildcardPath[MAX_PATH];
    TCHAR itemPath[MAX_PATH];
    HANDLE handle = INVALID_HANDLE_VALUE;
    WIN32_FIND_DATA data;

    if (!OnFileFound && !OnFolderFound) {
        status = -1;
        goto out;
    }

    SecureZeroMemory(wildcardPath, sizeof wildcardPath);
    SecureZeroMemory(itemPath, sizeof itemPath);
    SecureZeroMemory(&data, sizeof data);

    if (status = _tcscpy_s(wildcardPath, _countof(wildcardPath), folderPath))
        goto out;
    if (status = _tcscat_s(wildcardPath, _countof(wildcardPath), TEXT("\\*")))
        goto out;

    if ((handle = FindFirstFile(wildcardPath, &data)) == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_NO_MORE_FILES) {
            goto out_close_handle;
        } else {
            status = -2;
            goto out;
        }
    }

    do {
        if (status = _tcscpy_s(itemPath, _countof(itemPath), folderPath))
            goto out_close_handle;
        if (status = _tcscat_s(itemPath, _countof(itemPath), TEXT("\\")))
            goto out_close_handle;
        if (status = _tcscat_s(itemPath, _countof(itemPath), data.cFileName))
            goto out_close_handle;
        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (_tcscmp(data.cFileName, TEXT(".")) && _tcscmp(data.cFileName, TEXT(".."))) {
                if (OnFolderFound)
                    OnFolderFound(data.cFileName, itemPath);
                if (recurse)
                    TraverseFolder(itemPath, OnFolderFound, OnFileFound, recurse);
            }
        } else {
            if (OnFileFound)
                OnFileFound(data.cFileName, itemPath);
        }
    } while (FindNextFile(handle, &data));

    if (GetLastError() != ERROR_NO_MORE_FILES)
        status = -2;

out_close_handle:
    FindClose(handle);
out:
    return status;
}

/** @} */

VOID OnFolderFound(LPCTSTR folderName, LPCTSTR folderPath)
{
    _tprintf_s(TEXT("Folder: %s (%s)\n"), folderName, folderPath);
}

VOID OnFileFound(LPCTSTR fileName, LPCTSTR filePath)
{
    _tprintf_s(TEXT("File: %s (%s)\n"), fileName, filePath);
}

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    if (2 != argc) {
        assert(2 == argc);
        return EXIT_FAILURE;
    }

    errno_t status = TraverseFolder(argv[1], OnFolderFound, OnFileFound, TRUE);

    _tsystem(TEXT("pause"));
    return status ? EXIT_FAILURE : EXIT_SUCCESS;
}
