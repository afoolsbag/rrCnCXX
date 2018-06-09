/** \copyright The MIT License */

#include <stdlib.h>
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/cr8flr.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "rrwindows/prtdbg.h"
#include "tsuite_dirmgmt.h"

START_TEST(TestCr8Flr)
{
    DWORD ec = ERROR_SUCCESS;

    TCHAR flrPath[MAX_PATH];
    if (FAILED(StringCchCopy(flrPath, _countof(flrPath), ExecutableDirectoryPath()))) {
        ck_abort(); return;
    }
    if (!PathAppend(flrPath, _T("tmpflr\\subflr\\subsubflr"))) {
        ck_abort(); return;
    }
    if (ERROR_SUCCESS != (ec = CreateFolder(flrPath))) {
        DpInfo(_T("CreateFolder failed, %lu, %s"), ec, ErrorTextOf(ec));
        ck_abort(); return;
    }
}
END_TEST

TCase *TCaseCr8Flr(void)
{
    TCase *tcase = tcase_create("Cr8Flr");
    tcase_add_test(tcase, TestCr8Flr);
    return tcase;
}
