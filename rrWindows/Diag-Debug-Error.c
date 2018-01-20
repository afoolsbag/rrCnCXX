/**
* \file
* \brief 错误处理
* \sa ["Error Handling"](https://msdn.microsoft.com/library/ms679320). *Microsoft® Developer Network*.
* \author zhengrr
* \date 2018-1-15 – 20
* \copyright The MIT License
*/

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \sa [GetLastError function](https://msdn.microsoft.com/library/ms679360). *Microsoft® Developer Network*.
 * \sa [FormatMessage function](https://msdn.microsoft.com/library/ms679351). *Microsoft® Developer Network*.
 */
VOID ShowLastError(const TCHAR *tips)
{
	const DWORD code = GetLastError();
	TCHAR *msg = NULL;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		code,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR) &msg,
		0,
		NULL);

	_ftprintf_s(stderr, TEXT("%s: system error %lu, %s"), tips, code, msg);
	LocalFree(msg);
}

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	GetProcessId(NULL);
	ShowLastError(TEXT("GetProcessId"));
	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}
