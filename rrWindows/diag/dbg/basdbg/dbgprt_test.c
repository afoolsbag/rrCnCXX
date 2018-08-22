/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "check/check.h"
#include "rrWindows/rrWindows.h"

#include "test.h"

START_TEST(TestPrtDbg)
{
    DpWarn(_T("Test DpWarn."));
    DpWarnFwLE(_T("Test DpWarnFwLE"));
    DpInfo(_T("Test DpInfo."));
    DpDebug(_T("Test DpDebug."));
    DpTrace(_T("Test DpTrace."));
    DpTraceEnter();
    DpTraceLeave();
}
END_TEST

TCase *TCaseDbgPrt(VOID)
{
    TCase *tcase = tcase_create("PrtDbg");
    tcase_add_test(tcase, TestPrtDbg);
    return tcase;
}
