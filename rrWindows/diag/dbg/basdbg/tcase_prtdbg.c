/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/prtdbgstr.h"

START_TEST(TestPrtDbg)
{
    DpDebugFunc();
    DpInfo(_T("Lovely little fool."));
}
END_TEST

TCase *TCasePrtDbg(VOID)
{
    TCase *tcase = tcase_create("PrtDbg");
    tcase_add_test(tcase, TestPrtDbg);
    return tcase;
}
