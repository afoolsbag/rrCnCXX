/*===-- Single Instance Application ----------------------------*- C -*-===*//**
 *
 * \defgroup gSglInstApp 单实例应用
 * \ingroup gSync
 *
 * \author zhengrr
 * \version 2018-08-22
 * \since 2018-01-20
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "_test.h"

START_TEST(TestSglInstApp)
{
    if (NULL != OpenMutex(MUTEX_ALL_ACCESS, FALSE, _T("rrWindowsSia")))
        return;
    CreateMutex(NULL, FALSE, _T("rrWindowsSia"));
}
END_TEST

/** @} */

TCase *TCaseSglInstApp(void)
{
    TCase *tcase = tcase_create("SglInstApp");
    tcase_add_test(tcase, TestSglInstApp);
    return tcase;
}
