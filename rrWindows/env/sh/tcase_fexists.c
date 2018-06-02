/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <check/check.h>

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "tsuite_sh.h"

START_TEST(TestFExists)
{
    if (!PathFileExists(ExecutablePath())) {
        DbgPrtD(_T("TraverseFolder failed: %s, %lu, %s\n"), ExecutablePath(), GetLastError(), GetLastErrorText());
        ck_abort();
    }
}
END_TEST

TCase *TCaseFExists(void)
{
    TCase *tcase = tcase_create("FExists");
    tcase_add_test(tcase, TestFExists);
    return tcase;
}
