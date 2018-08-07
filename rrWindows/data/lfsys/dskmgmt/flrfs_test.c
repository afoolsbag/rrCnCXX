/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "rrwindows/flrfs.h"
#include "tsuite_dskmgmt.h"

START_TEST(TestFlrFS)
{
    CONST ULARGE_INTEGER availableFreeBytes = GetFolderFreeSpace(ExecutableDirectoryPath());
    if (0 == availableFreeBytes.QuadPart) {
        DpWarnFwLE(TEXT("GetFolderFreeSpace"));
        ck_abort();
        return;
    } else {
        DpInfo(TEXT("%s available free bytes %llu."), ExecutableDirectoryPath(), availableFreeBytes.QuadPart);
    }
}
END_TEST

TCase *TCaseFlrFS(void)
{
    TCase *tcase = tcase_create("FlrFS");
    tcase_add_test(tcase, TestFlrFS);
    return tcase;
}
