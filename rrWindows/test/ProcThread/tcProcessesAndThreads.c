#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "tsProcThread.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/**
 * \addtogroup gProcThread
 * @{
 */

/**
 * \sa [`CreateThread`和`_beginthreadex`](http://cnblogs.com/lgxqf/archive/2009/02/10/1387480.html)
 */
static DWORD WINAPI ThrdFunc(LPVOID CONST lpThreadParameter)
{
    UNREFERENCED_PARAMETER(lpThreadParameter);

    HANDLE CONST stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdoutHandle == INVALID_HANDLE_VALUE)
        return EXIT_FAILURE;

    TCHAR msg[] = _T("hello, world\n");
    WriteConsole(stdoutHandle, msg, sizeof msg / sizeof *msg - 1, NULL, NULL);
    return EXIT_SUCCESS;
}

START_TEST(tfFirstStep)
{
    HANDLE CONST thrd = CreateThread(NULL, 0, ThrdFunc, NULL, 0, NULL);
    if (!thrd)
        ck_abort_msg("CreateThread() failed: %lu", GetLastError());

    WaitForSingleObject(thrd, INFINITE);
}
END_TEST;

/**
 * @}
 */

TCase *tcProcessesAndThreads(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfFirstStep);
    return tc;
}
