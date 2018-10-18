/*===-- Directory Management -----------------------------------*- C -*-===*//**
 *
 * \defgroup gDirectoryManagement 目录管理
 * \ingroup gFileIO
 *
 * \sa ["Directory Management"](https://docs.microsoft.com/windows/desktop/fileio/directory-management). *Microsoft Docs*.
 *
 * \version 2018-10-18
 * \since 2018-06-01
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#include <strsafe.h>
#include <tchar.h>

#include <check/check.h>

#include "_test.h"
#include "rrwindows/rrwindows.h"

START_TEST(tfCreateFolder)
{
}
END_TEST

START_TEST(tfRemoveFolder)
{
}
END_TEST

/** @} */

TCase *tcDirectoryManagement(void)
{
    TCase *const tc = tcase_create("DirectoryManagement");
    tcase_add_test(tc, tfCreateFolder);
    tcase_add_test(tc, tfRemoveFolder);
    return tc;
}
