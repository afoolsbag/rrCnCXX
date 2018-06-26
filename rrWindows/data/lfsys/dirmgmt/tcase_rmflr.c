/** \copyright The MIT License */

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <check/check.h>

#include "rrwindows/def.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "rrwindows/rmflr.h"
#include "rrwindows/prtdbgstr.h"
#include "tsuite_dirmgmt.h"

START_TEST(TestRmFlr)
{
    DWORD ec = ERROR_SUCCESS;

    TCHAR flrPath[MAX_PATH];
    if (FAILED(StringCchCopy(flrPath, countof(flrPath), ExecutableDirectoryPath()))) {
        ck_abort(); return;
    }
    if (!PathAppend(flrPath, _T("tmpflr"))) {
        ck_abort(); return;
    }
    if (ERROR_SUCCESS != (ec = RemoveFolder(flrPath))) {
        DpWarnFwLE(_T("RemoveFolder"));
        ck_abort(); return;
    }
}
END_TEST

TCase *TCaseRmFlr(void)
{
    TCase *tcase = tcase_create("RmFlr");
    tcase_add_test(tcase, TestRmFlr);
    return tcase;
}
