/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/travflr.h"
#include "tsuite_fmgmt.h"
#include "rrwindows/exepath.h"

static DWORD CALLBACK
OnFileFound(LPCTSTR CONST path, LPWIN32_FIND_DATA CONST pData)
{
    return ERROR_SUCCESS;
}

START_TEST(TestTravFlr)
{
    DWORD ec = ERROR_SUCCESS;

    if (ERROR_SUCCESS != (ec = TraverseFolder(ExecutableDirectoryPath(), OnFileFound, FALSE))) {
        DpWarnFwLE(_T("TraverseFolder"));
        ck_abort(); return;
    }
}
END_TEST

TCase *TCaseTravFlr(void)
{
    TCase *tcase = tcase_create("TravFlr");
    tcase_add_test(tcase, TestTravFlr);
    return tcase;
}
