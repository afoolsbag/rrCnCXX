/*===-- toupper in Windows API ---------------------------------*- C -*-===*//**
 *
 * \defgroup gToUpper Windows API 中的 `toupper`
 * \ingroup gStr
 *
 * \author zhengrr
 * \version 2018-08-24
 * \since 2018-02-23
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>
#include "rrwindows/rrwindows.h"

#include "_test.h"

/**
 * \brief Converts a character or string to uppercase.
 *
 * \sa ["CharUpper function"](https://msdn.microsoft.com/library/ms647474). *Microsoft Developer Network*.
 */
START_TEST(TestCharUpper)
{
    TCHAR txt[] = _T("love");
    CharUpper(txt);
    ck_assert(CSTR_EQUAL == CompareStringS(txt, _T("LOVE")));
}
END_TEST

/** @} */

TCase *TCaseToUpper(void)
{
    TCase *tcase = tcase_create("ToUpper");
    tcase_add_test(tcase, TestCharUpper);
    return tcase;
}
