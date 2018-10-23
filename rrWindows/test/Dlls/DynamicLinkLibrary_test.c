/*===-- Dynamic-Link Libraries ---------------------------------*- C -*-===*//**
 *
 * \defgroup gDlls 动态链接库
 * \ingroup gDevelop
 *
 * \sa ["Dynamic-Link Libraries"](https://docs.microsoft.com/windows/desktop/Dlls/). *Microsoft Docs*.
 *
 * \version 2018-10-23
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright The Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "_test.h"
#include "rrwindows/rrwindows.h"

START_TEST(tfAllocExecutablePath)
{
    PCTSTR CONST path = AllocExecutablePath();
    ck_assert(path);
    HeapFree(GetProcessHeap(), 0, (PVOID)path);
}
END_TEST

START_TEST(tfAllocExecutableDirectoryPath)
{
    PCTSTR CONST path = AllocExecutableDirectoryPath();
    ck_assert(path);
    HeapFree(GetProcessHeap(), 0, (PVOID)path);
}
END_TEST

START_TEST(tfAllocExecutableName)
{
    PCTSTR CONST name = AllocExecutableName();
    ck_assert(name);
    HeapFree(GetProcessHeap(), 0, (PVOID)name);
}
END_TEST

START_TEST(tfAllocExecutableBaseName)
{
    PCTSTR CONST name = AllocExecutableBaseName();
    ck_assert(name);
    HeapFree(GetProcessHeap(), 0, (PVOID)name);
}
END_TEST

START_TEST(tfAllocExecutableExtensionName)
{
    PCTSTR CONST name = AllocExecutableExtensionName();
    ck_assert(name);
    HeapFree(GetProcessHeap(), 0, (PVOID)name);
}
END_TEST

START_TEST(tfAllocInitializationPath)
{
    PCTSTR CONST path = AllocInitializationPath();
    ck_assert(path);
    HeapFree(GetProcessHeap(), 0, (PVOID)path);
}
END_TEST

/** @} */

TCase *tcDynamicLinkLibrary(void)
{
    TCase *const tc = tcase_create("DynamicLinkLibrary");
    tcase_add_test(tc, tfAllocExecutablePath);
    tcase_add_test(tc, tfAllocExecutableDirectoryPath);
    tcase_add_test(tc, tfAllocExecutableName);
    tcase_add_test(tc, tfAllocExecutableBaseName);
    tcase_add_test(tc, tfAllocExecutableExtensionName);
    tcase_add_test(tc, tfAllocInitializationPath);
    return tc;
}
