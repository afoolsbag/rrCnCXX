/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>
#include <tchar.h>

#include <check/check.h>
#include "rrWindows/data/lfsys/dirmgmt/cr8flr.h"
#include "rrWindows/diag/dbg/basdbg/dbgprt.h"
#include "rrWindows/diag/dbg/errhdl/errtxt.h"
#include "rrWindows/svc/dll/exepath.h"
#include "rrWindows/def.h"

#include "test.h"

START_TEST(TestCr8Flr)
{
    TCHAR flrPath[MAX_PATH];
    if (FAILED(StringCchCopy(flrPath, countof(flrPath), ExecutableDirectoryPath()))) {
        ck_abort(); return;
    }
    if (!PathAppend(flrPath, _T("tmpflr\\subflr\\subsubflr"))) {
        ck_abort(); return;
    }
    if (ERROR_SUCCESS != CreateFolder(flrPath)) {
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
