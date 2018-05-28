/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/acsshrflr.h"
#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"

START_TEST(TestAcsShrFlr)
{
    if (ConnectSharedFolder(_T("\\\\localhost\\path\\to\\folder"),
                            _T("username"),
                            _T("password")))
        DbgPrtD(_T("Connect shared folder failed: %s\n"), GetLastErrorText());
}
END_TEST

TCase *TCaseAcsShrFlr(VOID)
{
    TCase *tcase = tcase_create("AcsShrFlr");
    tcase_add_test(tcase, TestAcsShrFlr);
    return tcase;
}
