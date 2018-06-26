/** \copyright The MIT License */

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/cr8flr.h"
#include "rrwindows/def.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "rrwindows/prtdbgstr.h"
#include "tsuite_dirmgmt.h"

START_TEST(TestCr8Flr)
{
    DWORD ec = ERROR_SUCCESS;

    TCHAR flrPath[MAX_PATH];
    if (FAILED(StringCchCopy(flrPath, countof(flrPath), ExecutableDirectoryPath()))) {
        ck_abort(); return;
    }
    if (!PathAppend(flrPath, _T("tmpflr\\subflr\\subsubflr"))) {
        ck_abort(); return;
    }
    if (ERROR_SUCCESS != (ec = CreateFolder(flrPath))) {
        DpWarnFwLE(_T("CreateFolder"));
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
