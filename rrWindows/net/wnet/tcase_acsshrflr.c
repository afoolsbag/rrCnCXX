/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/acsshrflr.h"
#include "rrwindows/prtdbgstr.h"
#include "rrwindows/errtxt.h"
#include "tsuite_wnet.h"

START_TEST(TestAcsShrFlr)
{
    CONST DWORD ec = ConnectSharedFolder(_T("\\\\localhost\\path\\to\\folder"),
                                         _T("username"),
                                         _T("password"));
    if (ERROR_SUCCESS != ec)
        DpWarnFwLE(_T("ConnectSharedFolder"));
}
END_TEST

TCase *TCaseAcsShrFlr(VOID)
{
    TCase *tcase = tcase_create("AcsShrFlr");
    tcase_add_test(tcase, TestAcsShrFlr);
    return tcase;
}
