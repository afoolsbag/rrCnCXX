/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 错误处理。
 *
 * \sa ["Error Handling"](https://msdn.microsoft.com/library/ms679320). *Microsoft® Developer Network*.
 *
 * \version 2018-04-16
 * \since 2018-01-15
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \sa ["GetLastError function"](https://msdn.microsoft.com/library/ms679360). *Microsoft® Developer Network*.
 * \sa ["FormatMessage function"](https://msdn.microsoft.com/library/ms679351). *Microsoft® Developer Network*.
 */
VOID PrintLastError(CONST TCHAR *CONST tips)
{
    CONST DWORD code = GetLastError();
    TCHAR *msg = NULL;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, code, MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
        &msg, 0, NULL);

    _ftprintf_s(stderr, _T("%s: error code %lu, error message %s"), tips, code, msg);
    LocalFree(msg);
}

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    GetProcessId(NULL);
    PrintLastError(_T("GetProcessId"));
    _tsystem(_T("pause"));
    return EXIT_SUCCESS;
}
