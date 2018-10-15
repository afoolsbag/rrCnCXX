/*===-- File Access --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gFileAccess 文件访问
 * \ingroup gIO
 *
 * \sa ["File access"](http://en.cppreference.com/w/c/io#File_access). *cppreference.com*.
 *
 * \version 2018-10-15
 * \since 2016-11-14
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#include <stdio.h>

#include <check/check.h>

#include "_test.h"
#include "c_versions.h"

/**
 * \brief 打开文件。
 *        File Open.
 * \sa <http://en.cppreference.com/w/c/io/fopen>
 */
START_TEST(tf_fopen)
{
#if LIB_EXT1
    FILE *fp;
    fopen_s(&fp, "hello.txt", "a+");
#else
    FILE *fp = fopen("hello.txt", "a+");
#endif
    if (!fp) {
        ck_abort_msg("File Open Failed");
        return;
    }
    fclose(fp);
}
END_TEST;

/**
 * \brief 以不同名称打开既存的文件流。
 *        File Re-open.
 * \sa <http://en.cppreference.com/w/c/io/freopen>
 */
START_TEST(tf_freopen)
{

}
END_TEST;

/** @} */

TCase *tc_file_access(void)
{
    TCase *const tc = tcase_create("file_access");
    tcase_add_test(tc, tf_fopen);
    tcase_add_test(tc, tf_freopen);
    return tc;
}
