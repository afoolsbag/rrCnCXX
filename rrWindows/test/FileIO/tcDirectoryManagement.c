/*===-- Directory Management -----------------------------------*- C -*-===*//**
 *
 * \defgroup gDirectoryManagement 目录管理
 * \ingroup gFileIO
 *
 * \sa ["Directory Management"](https://docs.microsoft.com/windows/desktop/fileio/directory-management). *Microsoft Docs*.
 *
 * \version 2018-10-19
 * \since 2018-06-01
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsFileIO.h"

CONST TCHAR Sub1[] = _T("\\sub");
CONST TCHAR Sub3[] = _T("\\sub\\to\\here");

START_TEST(tfCreateDirectoryRecursively)
{
    PCTSTR CONST dir = AllocExecutableDirectoryPath();
    ck_assert(dir);

    PCTSTR CONST tgt = StringAllocCat(dir, Sub3);
    HeapFree(GetProcessHeap(), 0, (PVOID)dir);
    ck_assert(tgt);

    ck_assert(CreateDirectoryRecursively(tgt));
    HeapFree(GetProcessHeap(), 0, (PVOID)tgt);
}
END_TEST

START_TEST(tfRemoveDirectoryTraversely)
{
    PCTSTR CONST dir = AllocExecutableDirectoryPath();
    ck_assert(dir);

    PCTSTR CONST tgt = StringAllocCat(dir, Sub1);
    HeapFree(GetProcessHeap(), 0, (PVOID)dir);
    ck_assert(tgt);

    ck_assert(RemoveDirectoryTraversely(tgt));
    HeapFree(GetProcessHeap(), 0, (PVOID)tgt);
}
END_TEST

/**
 * @}
 */

TCase *tcDirectoryManagement(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfCreateDirectoryRecursively);
    tcase_add_test(tc, tfRemoveDirectoryTraversely);
    return tc;
}
