/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/acsshrflr.h"
#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "tsuite_wnet.h"

START_TEST(TestAcsShrFlr)
{
    CONST TCHAR path[] = _T("\\\\localhost\\path\\to\\folder");
    CONST TCHAR usr[] = _T("username");
    CONST TCHAR pwd[] = _T("password");
    if (!ConnectSharedFolder(path, usr, pwd))
        DpWarnFwLE(_T("ConnectSharedFolder(%s, %s, %s)"), path, usr, pwd);
}
END_TEST

TCase *TCaseAcsShrFlr(VOID)
{
    TCase *tcase = tcase_create("AcsShrFlr");
    tcase_add_test(tcase, TestAcsShrFlr);
    return tcase;
}
