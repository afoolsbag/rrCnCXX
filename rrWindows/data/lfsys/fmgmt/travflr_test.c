/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>
#include "rrWindows/rrWindows.h"

#include "test.h"

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
