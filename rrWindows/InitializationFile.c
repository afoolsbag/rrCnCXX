/**
 * \file
 * \brief Windows® 初始化文件
 * \author zhengrr
 * \date 2018-1-15
 * \copyright The MIT License
 */

#include <stdio.h>

#include <tchar.h>
#include <windows.h>

#include "Error.h"

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
	TCHAR pathApp[_MAX_PATH] = {'\0'};
	TCHAR drApp[_MAX_DRIVE] = {'\0'};
	TCHAR dirApp[_MAX_DIR] = {'\0'};
	TCHAR nameApp[_MAX_FNAME] = {'\0'};
	TCHAR extApp[_MAX_EXT] = {'\0'};

	TCHAR pathIni[MAX_PATH] = {'\0'};

	TCHAR valueStr[INI_VALUE_LIMIT] = {'\0'};
	INT valueInt = 0;

	GetModuleFileName(NULL, pathApp, _MAX_PATH);
	_tsplitpath_s(pathApp, drApp, _MAX_DRIVE, dirApp, _MAX_DIR,
		      nameApp, _MAX_FNAME, extApp, _MAX_EXT);
	_stprintf_s(pathIni, _MAX_PATH, "%s%s/app.ini", drApp, dirApp);

	if (!WritePrivateProfileString(TEXT("app"), TEXT("string"), TEXT("wow"),
				       pathIni)) {
		ShowLastError(TEXT("WritePrivateProfileString"));
		return EXIT_FAILURE;
	}
	if (!WritePrivateProfileString(TEXT("app"), TEXT("int"), TEXT("666"),
				       pathIni)) {
		ShowLastError(TEXT("WritePrivateProfileString"));
		return EXIT_FAILURE;
	}

	GetPrivateProfileString(TEXT("app"), TEXT("string"), TEXT(""),
				valueStr, INI_VALUE_LIMIT, pathIni);
	valueInt = GetPrivateProfileInt(TEXT("app"), TEXT("int"), 1337,
					pathIni);

	_tprintf_s(TEXT("app:string: %s\n"), valueStr);
	_tprintf_s(TEXT("app:int: %d\n"), valueInt);

	return EXIT_SUCCESS;
}
