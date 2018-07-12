/*===-- Executable Version -------------------------------------*- C -*-===*//**
 *
 * \defgroup gExeVer 当前进程的可执行文件版本
 * \ingroup gVer
 *
 * \version 2018-07-12
 * \since 2018-07-12
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#pragma comment(lib, "mincore.lib")

#include <check/check.h>
#include "rrwindows/exepath.h"
#include "rrwindows/verinfo.h"

#include "tsuite_ver.h"

START_TEST(TestExeVer)
{
    WORD major, minor, patch, tweak;
    GetFileVersionInformation(ExecutablePath(), &major, &minor, &patch, &tweak);
    ck_assert_int_le(2018, major);
}
END_TEST

/** @} */

TCase *TCaseExeVer(void)
{
    TCase *tcase = tcase_create("ExeVer");
    tcase_add_test(tcase, TestExeVer);
    return tcase;
}
