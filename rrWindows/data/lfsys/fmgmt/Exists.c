/**
 * \file
 * \brief Windows®文件存在
 * \author zhengrr
 * \date 2018-1-20
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <windows.h>

/**
 * \sa ["GetModuleFileName function"](https://msdn.microsoft.com/library/ms683197). *Microsoft® Developer Network*.
 * \sa ["_splitpath_s, _wsplitpath_s"](https://msdn.microsoft.com/library/8e46eyt7). *Microsoft® Developer Network*.
 * \sa ["GetFileAttributesEx function"](https://msdn.microsoft.com/library/aa364946). *Microsoft® Developer Network*.
 * \sa ["FileTimeToSystemTime function"](https://msdn.microsoft.com/library/ms724280). *Microsoft® Developer Network*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	TCHAR pathApp[_MAX_PATH] = {TEXT('\0')};
	GetModuleFileName(NULL, pathApp, _MAX_PATH);

	TCHAR driveApp[_MAX_DRIVE] = {TEXT('\0')};
	TCHAR dirApp[_MAX_DIR] = {TEXT('\0')};
	TCHAR nameApp[_MAX_FNAME] = {TEXT('\0')};
	TCHAR extApp[_MAX_EXT] = {TEXT('\0')};
	_tsplitpath_s(pathApp, driveApp, _MAX_DRIVE, dirApp, _MAX_DIR, nameApp, _MAX_FNAME, extApp, _MAX_EXT);

	TCHAR pathFile[_MAX_PATH] = {TEXT('\0')};
	_stprintf_s(pathFile, _MAX_PATH, TEXT("%s%s\\file.txt"), driveApp, dirApp);

	BOOL existFile = TRUE;
	if (INVALID_FILE_ATTRIBUTES == GetFileAttributes(pathFile)) {
		existFile = FALSE;
		const ULONG codeError = GetLastError();
		if (ERROR_FILE_NOT_FOUND != codeError)
			_ftprintf_s(stderr, TEXT("GetFileAttributes failed with error: %lu\n"), codeError);
	}
	_tprintf_s(TEXT("%s %s\n"), pathFile, existFile ? TEXT("exist.") : TEXT("not exist."));

	_tsystem(TEXT("pause"));

	return EXIT_SUCCESS;
}
