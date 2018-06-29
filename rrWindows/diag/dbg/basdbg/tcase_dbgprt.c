/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"

START_TEST(TestPrtDbg)
{
    DpFatal(_T("Test DpFatal."));
    DpError(_T("Test DpError."));
    DpWarn(_T("Test DpWarn."));
    DpWarnFwLE(_T("Test DpWarnFwLE"));
    DpInfo(_T("Test DpInfo."));
    DpDebug(_T("Test DpDebug."));
    DpDebugFunc();
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
