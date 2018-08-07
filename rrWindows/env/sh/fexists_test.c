/*===-- File Exists --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gFExists 文件存在判定
 * \ingroup gSh
 *
 * \author zhengrr
 * \version 2018-06-22
 * \since 2018-05-08
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <tchar.h>

#include <check/check.h>

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "tsuite_sh.h"

START_TEST(TestFExists)
{
    if (!PathFileExists(ExecutablePath())) {
        DpWarnFwLE(_T("TraverseFolder"));
        ck_abort();
    }
}
END_TEST

/** @} */

TCase *TCaseFExists(void)
{
    TCase *tcase = tcase_create("FExists");
    tcase_add_test(tcase, TestFExists);
    return tcase;
}
