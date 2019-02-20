/*===-- Directory Management -----------------------------------*- C -*-===*//**
 *
 * \defgroup gStrings 字符串
 * \ingroup gMenuRc
 *
 * \sa ["Strings"](https://docs.microsoft.com/windows/desktop/menurc/strings). *Microsoft Docs*.
 *
 * \version 2019-01-03
 * \since 2018-10-18
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsMenuRc.h"

static CONST TCHAR Head[] = _T("Head");
static CONST TCHAR Body[] = _T("Body");
static CONST TCHAR Tail[] = _T("Tail");
static CONST TCHAR HeadTail[] = _T("HeadTail");
static CONST TCHAR HeadBodyTail[] = _T("HeadBodyTail");
static CONST TCHAR ToBeOrNot[] = _T("To be, or not to be, that is the question.");

START_TEST(tfStringAllocCat)
{
    PCTSTR CONST tmp = StringAllocCat(Head, Tail);
    ck_assert(tmp);
    ck_assert(CompareStringInvariant(tmp, HeadTail) == CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
}
END_TEST

START_TEST(tfStringAllocCat3)
{
    PCTSTR CONST tmp = StringAllocCat3(Head, Body, Tail);
    ck_assert(tmp);
    ck_assert(CompareStringInvariant(tmp, HeadBodyTail) == CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
}
END_TEST

START_TEST(tfStringAllocCopy_Const)
{
    SIZE_T count;
    PCTSTR CONST tmp = StringAllocCopyC(ToBeOrNot, &count);
    ck_assert(tmp);
    ck_assert(count);
    ck_assert(CompareStringInvariant(tmp, ToBeOrNot) == CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
}
END_TEST

START_TEST(tfStringAllocCopy)
{
    PCTSTR CONST tmp = StringAllocCopy(ToBeOrNot);
    ck_assert(tmp);
    ck_assert(CompareStringInvariant(tmp, ToBeOrNot) == CSTR_EQUAL);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
}
END_TEST

/**
 * @}
 */

TCase *tcStrings(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfStringAllocCat);
    tcase_add_test(tc, tfStringAllocCat3);
    tcase_add_test(tc, tfStringAllocCopy_Const);
    tcase_add_test(tc, tfStringAllocCopy);
    return tc;
}
