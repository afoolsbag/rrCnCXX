/*===-- File Operation -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gFOp 文件操作
 * \ingroup gSh
 *
 * \author zhengrr
 * \version 2018-06-22
 * \since 2018-06-22
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <shellapi.h>
#pragma comment(lib, "shell32.lib")
#include <tchar.h>

#include <check/check.h>

START_TEST(TestShCopy)
{

}
END_TEST

START_TEST(TestICopy)
{

}
END_TEST

/** @} */

TCase *TCaseFOp(void)
{
    TCase *tcase = tcase_create("FOp");
    tcase_add_test(tcase, TestShCopy);
    tcase_add_test(tcase, TestICopy);
    return tcase;
}
