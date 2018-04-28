/** \copyright The MIT License */

#include <stdlib.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/ckprocrun.h"
#include "tsuite_toolhelp.h"

START_TEST(TestCkProcRun)
{
    ck_assert(CheckProcessRunning(_T("svchost.exe")));
    ck_assert(!CheckProcessRunning(_T("svchost-yeyeye.exe")));
}
END_TEST

TCase *TCaseCkProcRun(VOID)
{
    TCase *tcase = tcase_create("CkProcRun");
    tcase_add_test(tcase, TestCkProcRun);
    return tcase;
}
