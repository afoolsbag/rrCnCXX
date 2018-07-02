/*===-- File Operation -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gFOp 文件操作
 * \ingroup gSh
 *
 * \sa ["IFileOperation function"](https://msdn.microsoft.com/library/bb775771.aspx). *MSDN*.
 * \sa ["SHFileOperation function"](https://msdn.microsoft.com/library/bb762164.aspx). *MSDN*.
 *
 * \author zhengrr
 * \version 2018-06-25
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

START_TEST(TestICopy)
{}
END_TEST

/**
 * \deprecated 过时的。
 */
START_TEST(TestShMove)
{}
END_TEST

/**
 * \deprecated 过时的。
 */
START_TEST(TestShCopy)
{}
END_TEST

/**
 * \deprecated 过时的。
 */
START_TEST(TestShDelete)
{
    return;
    SHFILEOPSTRUCT param;
    ZeroMemory(&param, sizeof(param));
    param.wFunc = FO_DELETE;
    param.pFrom = _T("D:\\vpt\0");
    param.pTo = NULL;
    SHFileOperation(&param);
}
END_TEST

/**
 * \deprecated 过时的。
 */
START_TEST(TestShRename)
{}
END_TEST

/** @} */

TCase *TCaseFOp(void)
{
    TCase *tcase = tcase_create("FOp");
    tcase_add_test(tcase, TestShMove);
    tcase_add_test(tcase, TestShCopy);
    tcase_add_test(tcase, TestShDelete);
    tcase_add_test(tcase, TestShRename);
    tcase_add_test(tcase, TestICopy);
    return tcase;
}
