/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gErrorHandling 错误处理
 * \ingroup gDebug
 *
 * \sa ["Error Handling"](https://docs.microsoft.com/zh-cn/windows/desktop/Debug/error-handling). *Microsoft Docs*.
 *
 * \version 2018-11-19
 * \since 2018-01-15
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsDebug.h"

START_TEST(tfAllocErrorMessage)
{
    PCTSTR CONST msg = AllocErrorMessage(ERROR_SUCCESS);
    ck_assert(msg);
    LocalFree((HLOCAL)msg);
}
END_TEST

/**
 * @}
 */

TCase *tcErrorHandling(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfAllocErrorMessage);
    return tc;
}
