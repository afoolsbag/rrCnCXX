/**
 * \file
 * \brief Windows®初始化文件
 * \author zhengrr
 * \date 2018-1-15 – 20
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

#define INI_VALUE_LIMIT 80

/**
 * \sa ["GetModuleFileName function"](https://msdn.microsoft.com/library/ms683197). *Microsoft® Developer Network*.
 * \sa ["_splitpath_s, _wsplitpath_s"](https://msdn.microsoft.com/library/8e46eyt7). *Microsoft® Developer Network*.
 * \sa ["sprintf_s, _sprintf_s_l, swprintf_s, _swprintf_s_l"](https://msdn.microsoft.com/library/ce3zzk1k). *Microsoft® Developer Network*.
 * \sa ["WritePrivateProfileString function"](https://msdn.microsoft.com/library/ms725501). *Microsoft® Developer Network*.
 * \sa ["GetPrivateProfileString function"](https://msdn.microsoft.com/library/ms724353). *Microsoft® Developer Network*.
 * \sa ["GetPrivateProfileInt"](https://msdn.microsoft.com/library/ms724345). *Microsoft® Developer Network*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	TCHAR pathApp[_MAX_PATH] = {TEXT('\0')};
	GetModuleFileName(NULL, pathApp, _MAX_PATH);

	TCHAR drApp[_MAX_DRIVE] = {TEXT('\0')};
	TCHAR dirApp[_MAX_DIR] = {TEXT('\0')};
	TCHAR nameApp[_MAX_FNAME] = {TEXT('\0')};
	TCHAR extApp[_MAX_EXT] = {TEXT('\0')};
	_tsplitpath_s(pathApp, drApp, _MAX_DRIVE, dirApp, _MAX_DIR, nameApp, _MAX_FNAME, extApp, _MAX_EXT);

	TCHAR pathIni[MAX_PATH] = {TEXT('\0')};
	_stprintf_s(pathIni, _MAX_PATH, "%s%s/app.ini", drApp, dirApp);

	if (!WritePrivateProfileString(TEXT("app"), TEXT("string"), TEXT("wow"), pathIni)) {
		_ftprintf_s(stderr, TEXT("WritePrivateProfileString failed with error: %lu\n"), GetLastError());
		return EXIT_FAILURE;
	}
	if (!WritePrivateProfileString(TEXT("app"), TEXT("int"), TEXT("666"), pathIni)) {
		_ftprintf_s(stderr, TEXT("WritePrivateProfileString failed with error: %lu\n"), GetLastError());
		return EXIT_FAILURE;
	}

	TCHAR valueStr[INI_VALUE_LIMIT] = {TEXT('\0')};
	GetPrivateProfileString(TEXT("app"), TEXT("string"), TEXT(""), valueStr, INI_VALUE_LIMIT, pathIni);
	const INT valueInt = GetPrivateProfileInt(TEXT("app"), TEXT("int"), 1337, pathIni);

	_tprintf_s(TEXT("app:string: %s\n"), valueStr);
	_tprintf_s(TEXT("app:int: %d\n"), valueInt);

	return EXIT_SUCCESS;
}
