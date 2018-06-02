/*===-- toupper in Windows API ---------------------------------*- C -*-===*//**
 *
 * \defgroup gToUpper WindowsAPI中的`toupper`
 * \ingroup gStr
 *
 * \author zhengrr
 * \version 2018-06-02
 * \since 2018-02-23
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "tsuite_str.h"

/**
 * \brief Converts a character or string to uppercase.
 *
 * \sa ["CharUpper function"](https://msdn.microsoft.com/library/ms647474). *Microsoft Developer Network*.
 */
START_TEST(TestCharUpper)
{
    TCHAR txt[] = _T("love");
    CharUpper(txt);
    ck_assert_str_eq(txt, _T("LOVE"));
}
END_TEST

/** @} */

TCase *TCaseToUpper(void)
{
    TCase *tcase = tcase_create("ToUpper");
    tcase_add_test(tcase, TestCharUpper);
    return tcase;
}
