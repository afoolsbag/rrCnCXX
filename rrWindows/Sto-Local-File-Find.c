/**
 * \file
 * \brief Windows® 查找文件
 * \author zhengrr
 * \date 2018-1-15
 * \copyright The MIT License
 */

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
	WIN32_FIND_DATA dataFind = {0};
	HANDLE handleFind = INVALID_HANDLE_VALUE;

	handleFind = FindFirstFile(TEXT("DirectoryPath/*"), &dataFind);
	if (INVALID_HANDLE_VALUE == handleFind) {
		ShowLastError(TEXT("FindFirstFile"));
		return EXIT_FAILURE;
	}

	do {
		if (dataFind.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			_tprintf(TEXT("  %s   <DIR>\n"), dataFind.cFileName);
		} else {
			_tprintf(TEXT("  %s   \n"), dataFind.cFileName);
		}
	} while (0 != FindNextFile(handleFind, &dataFind));
	if (ERROR_NO_MORE_FILES != GetLastError()) {
		ShowLastError(TEXT("FindNextFile"));
	}

	FindClose(handleFind);
	return EXIT_SUCCESS;
}
