/*===-- Unicode and Character Sets -----------------------------*- C -*-===*//**
 *
 * \defgroup gUnicodeAndCharacterSets 统一码与字符集
 * \ingroup gIntl
 *
 * \sa ["Unicode and Character Sets"](https://docs.microsoft.com/windows/desktop/Intl/unicode-and-character-sets). *Microsoft Docs*.
 *
 * \version 2018-10-23
 * \since 2018-10-23
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <uchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check.h>

#include "rrWindows/rrWindows.h"
#include "tsIntl.h"

static CONST CHAR  Utf8[] = "你好，世界";
static CONST WCHAR Unicode[] = L"你好，世界";
static CONST CHAR  Gb2312[] = "\xC4\xE3\xBA\xC3\xA3\xAC\xCA\xC0\xBD\xE7";

START_TEST(tfMultiByteAllocWideChar)
{
    PCWSTR CONST tmp = MultiByteAllocWideChar(CP_UTF8, Utf8);
    ck_assert(tmp);
    ck_assert(CompareStringInvariantW(tmp, Unicode) == CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
}
END_TEST

START_TEST(tfWideCharAllocMultiByte)
{
    PCSTR CONST tmp = WideCharAllocMultiByte(CP_UTF8, Unicode);
    ck_assert(tmp);
    ck_assert(CompareStringInvariantA(tmp, Utf8) == CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
}
END_TEST

START_TEST(tfMultiByteAllocMultiByte)
{
    PCSTR CONST tmp = MultiByteAllocMultiByte(CP_UTF8, Utf8, CP_GB2312);
    ck_assert(tmp);
    ck_assert(CompareStringInvariantA(tmp, Gb2312) == CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
}
END_TEST

/**
 * @}
 */

TCase *tcUnicodeAndCharacterSets(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfMultiByteAllocWideChar);
    tcase_add_test(tc, tfWideCharAllocMultiByte);
    tcase_add_test(tc, tfMultiByteAllocMultiByte);
    return tc;
}
