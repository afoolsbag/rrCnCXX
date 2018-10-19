/*===-- Directory Management -----------------------------------*- C -*-===*//**
 *
 * \defgroup gStrings 字符串
 * \ingroup gMenuRc
 *
 * \sa ["Strings"](https://docs.microsoft.com/zh-cn/windows/desktop/menurc/strings). *Microsoft Docs*.
 *
 * \version 2018-10-18
 * \since 2018-10-18
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>
#include <tchar.h>

#include <check/check.h>
#include "rrwindows/rrwindows.h"

#include "_test.h"

START_TEST(tfStringAllocCat)
{
    static CONST TCHAR src1[] = _T("head");
    static CONST TCHAR src2[] = _T("tail");
    static CONST TCHAR full[] = _T("headtail");

    PTSTR dest = NULL;
    ck_assert(StringAllocCat(src1, src2, &dest));
    ck_assert_int_eq(CompareString(LOCALE_USER_DEFAULT, 0, dest, -1, full, -1), CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, dest);
}
END_TEST

START_TEST(tfStringAllocCopy)
{
    static CONST TCHAR src[] = _T("To be, or not to be, that is the question.");

    PTSTR dest = NULL;
    ck_assert(StringAllocCopy(src, &dest));
    ck_assert_int_eq(CompareString(LOCALE_USER_DEFAULT, 0, dest, -1, src, -1), CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, dest);
}
END_TEST

/** @} */

TCase *tcStrings(void)
{
    TCase *const tc = tcase_create("DirectoryManagement");
    tcase_add_test(tc, tfStringAllocCat);
    tcase_add_test(tc, tfStringAllocCopy);
    return tc;
}
