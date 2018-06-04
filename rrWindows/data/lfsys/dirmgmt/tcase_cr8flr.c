/*===-- Create Folder ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gCr8Flr 创建文件夹
 * \ingroup gDirMgnt
 *
 * \version 2018-06-04
 * \since 2018-06-04
 * \author zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "tsuite_dirmgmt.h"

START_TEST(TestCr8Flr)
{
    TCHAR flrPath[MAX_PATH];
    if (FAILED(StringCchCopy(flrPath, _countof(flrPath), ExecutableDirectoryPath()))) {
        ck_abort(); return;
    }
    if (!PathAppend(flrPath, _T("tmpflr"))) {
        ck_abort(); return;
    }
    if (!CreateDirectory(flrPath, NULL)) {
        DbgPrtD(_T("CreateDirectory failed, %lu, %s\n"), GetLastError(), GetLastErrorText());
        ck_abort(); return;
    }
}
END_TEST

/** @} */

TCase *TCaseCr8Flr(void)
{
    TCase *tcase = tcase_create("Cr8Flr");
    tcase_add_test(tcase, TestCr8Flr);
    return tcase;
}
