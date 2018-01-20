/**
 * \file
 * \brief Windows®查找文件
 * \author zhengrr
 * \date 2018-1-15 – 20
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <windows.h>

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	WIN32_FIND_DATA dFild = {0};
	HANDLE hFind = INVALID_HANDLE_VALUE;

	hFind = FindFirstFile(TEXT("DirectoryPath/*"), &dFild);
	if (INVALID_HANDLE_VALUE == hFind) {
		_ftprintf_s(stderr, TEXT("FindFirstFile failed with error: %d\n"), GetLastError());
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
		_ftprintf_s(stderr, TEXT("FindNextFile failed with error: %d\n"), GetLastError());
	}

	FindClose(hFind);
	return EXIT_SUCCESS;
}
