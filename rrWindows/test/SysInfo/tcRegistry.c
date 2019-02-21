/*===-- Registry -----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gRegistry 注册
 * \ingroup gSysInfo
 *
 * \sa ["Registry"](https://docs.microsoft.com/windows/desktop/SysInfo/registry). *Microsoft Docs*.
 *
 * \version 2018-10-22
 * \since 2018-01-15
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrWindows/rrWindows.h"
#include "tsSysInfo.h"

static PTSTR CONST App = _T("app");
static PTSTR CONST StrKey = _T("str");
static PTSTR CONST StrVal = _T("wow");
static PTSTR CONST IntKey = _T("int");
static PTSTR CONST IntValS = _T("666");
static CONST INT IntValI = 666;

START_TEST(tfWriteIni)
{
    PCTSTR CONST ini = AllocInitializationPath();
    ck_assert(ini);

    ck_assert(WritePrivateProfileString(App, StrKey, StrVal, ini));

    ck_assert(WritePrivateProfileString(App, IntKey, IntValS, ini));

    HeapFree(GetProcessHeap(), 0, (PVOID)ini);
}
END_TEST

START_TEST(tfGetIni)
{
    PCTSTR CONST ini = AllocInitializationPath();
    ck_assert(ini);

    TCHAR tmp[10];
    ck_assert(GetPrivateProfileString(App, StrKey, NULL, tmp, 10, ini));
    ck_assert(CompareStringInvariant(tmp, StrVal) == CSTR_EQUAL);

    CONST INT num = GetPrivateProfileInt(App, IntKey, 0, ini);
    ck_assert_int_eq(num, IntValI);

    HeapFree(GetProcessHeap(), 0, (PVOID)ini);
}
END_TEST

/**
 * @}
 */

TCase *tcRegistry(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfWriteIni);
    tcase_add_test(tc, tfGetIni);
    return tc;
}
