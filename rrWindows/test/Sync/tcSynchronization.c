#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "tsSync.h"

/**
 * \addtogroup gSync
 * @{
 */

START_TEST(tfSingletonProcess)
{
    static CONST TCHAR MutexName[] = _T("rrWindowsTest");

    if (OpenMutex(MUTEX_ALL_ACCESS, FALSE, MutexName))
        return;
    CreateMutex(NULL, FALSE, MutexName);
}
END_TEST

/**
 * @}
 */

TCase *tcSynchronization(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfSingletonProcess);
    return tc;
}
