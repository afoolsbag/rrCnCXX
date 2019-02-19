/*===-- NationalLanguageSupport --------------------------------*- C -*-===*//**
 *
 * \defgroup gNationalLanguageSupport 国家语言支持
 * \ingroup gIntl
 *
 * \sa ["National Language Support"](https://docs.microsoft.com/windows/desktop/Intl/national-language-support). *Microsoft Docs*.
 *
 * \version 2018-10-23
 * \since 2018-10-23
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsIntl.h"

static CONST TCHAR Str1[] = _T("1234567");
static CONST TCHAR Str2[] = _T("1234567");

START_TEST(tfCompareStringInvariant)
{
    ck_assert(CompareStringInvariant(Str1, Str2) == CSTR_EQUAL);
}
END_TEST

START_TEST(tfCompareStringSystemDefault)
{
    ck_assert(CompareStringSystemDefault(Str1, Str2) == CSTR_EQUAL);
}
END_TEST

START_TEST(tfCompareStringUserDefault)
{
    ck_assert(CompareStringUserDefault(Str1, Str2) == CSTR_EQUAL);
}
END_TEST

/**
 * @}
 */

TCase *tcNationalLanguageSupport(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfCompareStringInvariant);
    tcase_add_test(tc, tfCompareStringSystemDefault);
    tcase_add_test(tc, tfCompareStringUserDefault);
    return tc;
}
