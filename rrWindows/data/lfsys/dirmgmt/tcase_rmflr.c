/** \copyright The MIT License */

#include <stdlib.h>
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <check/check.h>

#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "rrwindows/rmflr.h"
#include "rrwindows/prtdbg.h"
#include "tsuite_dirmgmt.h"

START_TEST(TestRmFlr)
{
    DWORD ec = ERROR_SUCCESS;

    TCHAR flrPath[MAX_PATH];
    if (FAILED(StringCchCopy(flrPath, _countof(flrPath), ExecutableDirectoryPath()))) {
        ck_abort(); return;
    }
    if (!PathAppend(flrPath, _T("tmpflr"))) {
        ck_abort(); return;
    }
    if (ERROR_SUCCESS != (ec = RemoveFolder(flrPath))) {
        DpWarn(_T("RemoveFolder failed: %lu, %s"), ec, ErrorTextOf(ec));
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
