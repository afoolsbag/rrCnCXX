/**
* \file
* \brief 错误处理
* \sa ["Error Handling"](https://msdn.microsoft.com/library/ms679320). *Microsoft® Developer Network*.
* \author zhengrr
* \date 2018-1-15 – 17
* \copyright The MIT License
*/

#include <stdio.h>

#include <tchar.h>
#include <Windows.h>

/**
 * \sa [GetLastError function](https://msdn.microsoft.com/library/ms679360). *Microsoft® Developer Network*.
 * \sa [FormatMessage function](https://msdn.microsoft.com/library/ms679351). *Microsoft® Developer Network*.
 */
VOID ShowLastError(PCTSTR tips)
{
	DWORD code = GetLastError();
	PTSTR msg = NULL;

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

	_ftprintf_s(stderr, TEXT("%s: system error %d, %s"), tips, code, msg);
	LocalFree(msg);
}
