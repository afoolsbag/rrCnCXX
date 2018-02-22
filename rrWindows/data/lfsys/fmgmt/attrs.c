/**
 * \file
 * \brief Windows®文件属性
 * \author zhengrr
 * \date 2018-1-15 – 20
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <windows.h>

/**
 * \sa ["WIN32_FILE_ATTRIBUTE_DATA structure"](https://msdn.microsoft.com/library/aa365739). *Microsoft® Developer Network*.
 * \sa ["GetFileAttributesEx function"](https://msdn.microsoft.com/library/aa364946). *Microsoft® Developer Network*.
 * \sa ["FileTimeToSystemTime function"](https://msdn.microsoft.com/library/ms724280). *Microsoft® Developer Network*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	WIN32_FILE_ATTRIBUTE_DATA attrs = {0};
	FILETIME ftLocal = {0};
	SYSTEMTIME stLocal = {0};

	GetFileAttributesEx("FilePath", GetFileExInfoStandard, &attrs);

	FileTimeToLocalFileTime(&attrs.ftCreationTime, &ftLocal);
	FileTimeToSystemTime(&ftLocal, &stLocal);
	_tprintf_s(TEXT("CreationTime: %hu:%hu:%hu\n"), stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

	return EXIT_SUCCESS;
}
