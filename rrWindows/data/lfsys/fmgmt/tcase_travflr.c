/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/travflr.h"
#include "tsuite_fmgmt.h"

static DWORD CALLBACK
OnFileFound(LPCTSTR CONST path, LPWIN32_FIND_DATA CONST pData)
{
    DbgPrtD(_T("File: %s (%s)\n"), pData->cFileName, path);
    return ERROR_SUCCESS;
}

START_TEST(TestTravFlr)
{
    CONST DWORD ec = TraverseFolder(_T("Drive:\\path\\to\\folder"), OnFileFound, FALSE);
    if (ERROR_SUCCESS != ec)
        DbgPrtD(_T("TraverseFolder failed: %lu, %s\n"), ec, ErrorTextOf(ec));
}
END_TEST

TCase *TCaseTravFlr(void)
{
    TCase *tcase = tcase_create("TravFlr");
    tcase_add_test(tcase, TestTravFlr);
    return tcase;
}
