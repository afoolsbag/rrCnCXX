/*===-- strcpy in Windows API ----------------------------------*- C -*-===*//**
 *
 * \defgroup gStrCpy WindowsAPI中的`strcpy`
 * \ingroup gStr
 *
 * \author zhengrr
 * \version 2018-06-26
 * \since 2018-06-02
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>
#include <tchar.h>

#include <check/check.h>
#include "rrWindows/rrWindows.h"

#include "test.h"

/**
 * \sa ["StringCchCopy function"](https://msdn.microsoft.com/library/ms647527). *Microsoft Developer Network*.
 */
START_TEST(TestStringCchCopy)
{
    TCHAR txt[5];
    if (FAILED(StringCchCopy(txt, countof(txt), _T("love")))) {
        ck_abort();
        return;
    }
    ck_assert(CSTR_EQUAL == CompareStringS(txt, _T("love")));
}
END_TEST

/** @} */

TCase *TCaseStrCpy(void)
{
    TCase *tcase = tcase_create("StrCpy");
    tcase_add_test(tcase, TestStringCchCopy);
    return tcase;
}
