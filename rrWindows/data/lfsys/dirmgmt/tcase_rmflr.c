/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <check/check.h>

#include "rrwindows/errtxt.h"
#include "rrwindows/dbgprt.h"
#include "rrwindows/rmflr.h"
#include "tsuite_dirmgmt.h"

START_TEST(TestRmFlr)
{
    CONST DWORD ec = RemoveFolder(_T("Drive:\\path\\to\\folder"));
    if (ERROR_SUCCESS != ec)
        DbgPrtD(_T("RemoveFolder failed: %lu, %s\n"), ec, ErrorTextOf(ec));
}
END_TEST

TCase *TCaseRmFlr(void)
{
    TCase *tcase = tcase_create("RmFlr");
    tcase_add_test(tcase, TestRmFlr);
    return tcase;
}
