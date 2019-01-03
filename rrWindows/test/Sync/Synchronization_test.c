/*===-- Synchronization ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gSync 同步
 * \ingroup gDevelop
 *
 * \sa ["Synchronization"](https://docs.microsoft.com/windows/desktop/Sync/). *Microsoft Docs*.
 *
 * \version 2019-01-03
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "_test.h"

static CONST TCHAR MutexName[] = _T("rrWindowsTest");

START_TEST(tfSingletonProcess)
{
    if (OpenMutex(MUTEX_ALL_ACCESS, FALSE, MutexName))
        return;
    CreateMutex(NULL, FALSE, MutexName);
}
END_TEST

/** @} */

TCase *tcSynchronization(void)
{
    TCase *const tc = tcase_create("Synchronization");
    tcase_add_test(tc, tfSingletonProcess);
    return tc;
}
