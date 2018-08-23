/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>
#include "rrwindows/rrwindows.h"

#include "_test.h"

START_TEST(TestCntProcByExe)
{
    ck_assert_int_lt(0, CountProcessesByExecutable(_T("svchost.exe")));
    ck_assert_int_eq(0, CountProcessesByExecutable(_T("svchost-yeyeye.exe")));
}
END_TEST

TCase *TCaseCntProc(VOID)
{
    TCase *tcase = tcase_create("CkProcRun");
    tcase_add_test(tcase, TestCntProcByExe);
    return tcase;
}
