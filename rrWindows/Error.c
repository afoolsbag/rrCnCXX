/** \copyright The MIT License */

#include "Error.h"

#include <stdio.h>

/**
 * \sa [GetLastError function](https://msdn.microsoft.com/library/ms679360). *Microsoft® Developer Network*.
 * \sa [FormatMessage function](https://msdn.microsoft.com/library/ms679351). *Microsoft® Developer Network*.
 */
VOID ShowLastError(PCTSTR tips)
{
	DWORD codeLastError = GetLastError();
	PTSTR messageLastError = NULL;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		codeLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR) &messageLastError,
		0,
		NULL);
	OutputDebugString(messageLastError);
	_ftprintf_s(stderr, TEXT("%s: system error %d, %s"),
		    tips, codeLastError, messageLastError);
	LocalFree(messageLastError);
}
