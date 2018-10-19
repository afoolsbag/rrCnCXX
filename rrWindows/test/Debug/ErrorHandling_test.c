/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gErrorHandling 错误处理。
 * \ingroup gDebug
 *
 * \sa ["Error Handling"](https://docs.microsoft.com/zh-cn/windows/desktop/Debug/error-handling). *Microsoft Docs*.
 *
 * \version 2018-10-19
 * \since 2018-01-15
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "_test.h"
#include "rrwindows/rrwindows.h"

START_TEST(tfErrorMessage)
{
    PTSTR msg = NULL;
    ck_assert(ErrorMessageAlloc(6L, &msg));
    LocalFree(msg);
}
END_TEST

/** @} */

TCase *tcErrorHandling(void)
{
    TCase *const tc = tcase_create("ErrorHandling");
    tcase_add_test(tc, tfErrorMessage);
    return tc;
}
