/**
 * \file
 * \brief Windows® 查找文件
 * \author zhengrr
 * \date 2018-1-15
 * \copyright The MIT License
 */

#include <stdio.h>

#include <tchar.h>
#include <windows.h>

#include "Diag-Debug-Error.h"

/**
 * \sa [WIN32_FILE_ATTRIBUTE_DATA structure](https://msdn.microsoft.com/library/aa365739)
 * \sa [GetFileAttributesEx function](https://msdn.microsoft.com/library/aa364946)
 * \sa [FileTimeToSystemTime function](https://msdn.microsoft.com/library/ms724280)
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	WIN32_FIND_DATA dFild = {0};
	HANDLE hFind = INVALID_HANDLE_VALUE;

	hFind = FindFirstFile(TEXT("DirectoryPath/*"), &dFild);
	if (INVALID_HANDLE_VALUE == hFind) {
		ShowLastError(TEXT("FindFirstFile"));
		return EXIT_FAILURE;
	}

	do {
		if (dFild.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			_tprintf_s(TEXT("DIR:  %s\n"), dFild.cFileName);
		} else {
			_tprintf_s(TEXT("FILE: %s\n"), dFild.cFileName);
		}
	} while (0 != FindNextFile(hFind, &dFild));

	if (ERROR_NO_MORE_FILES != GetLastError()) {
		ShowLastError(TEXT("FindNextFile"));
	}

	FindClose(hFind);
	return EXIT_SUCCESS;
}
