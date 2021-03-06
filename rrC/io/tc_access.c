/*===-- Access -------------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupAccess 文件访问
 * \ingroup groupFileIO
 *
 * \version 2020-01-09
 * \since 2016-11-14
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdio.h>

#include <check.h>

#include "c_versions.h"
#include "ts_io.h"

/**
 * \brief 创建文件
 * \sa <http://zh.cppreference.com/w/c/io/fopen>
 * \sa <http://zh.cppreference.com/w/c/io/fclose>
 */
START_TEST(tf_create_file)
{
    FILE *fp = fopen("tf.txt", "w");
    if (!fp)
        ck_abort_msg("fopen() failed: %s", strerror(errno));

    ck_assert(!fclose(fp));
}
END_TEST;

/**
 * \brief 移动文件
 * \sa <http://zh.cppreference.com/w/c/io/rename>
 */
START_TEST(tf_move_file)
{
    if (rename("tf.txt", "tf2.txt"))
        ck_abort_msg("rename() failed: %s", strerror(errno));
}
END_TEST;

/**
 * \brief 删除文件
 * \sa <http://zh.cppreference.com/w/c/io/remove>
 */
START_TEST(tf_delete_file)
{
    if (remove("tf2.txt"))
        ck_abort_msg("remove() failed: %s", strerror(errno));
}
END_TEST;

/**
 * \brief 生成并打开临时文件
 * \sa <http://zh.cppreference.com/w/c/io/tmpfile>
 */
START_TEST(tf_temporary_file)
{
#if TEST_OVERFLOW_TMP_FILES
    for(int i = 0; i < TMP_MAX && i < FOPEN_MAX; ++i)
        tmpfile();
#endif

    FILE *tp = tmpfile();
    ck_assert(tp);

    ck_assert(!fclose(tp));
}
END_TEST;

/**
 * \brief 生成临时文件名
 * \sa <http://zh.cppreference.com/w/c/io/tmpnam>
 */
START_TEST(tf_temporary_name)
{
#if NORMALIZED_MSC_VERSION
    char name[L_tmpnam];
    ck_assert(tmpnam(name));
    ck_assert(printf("tmpnam: %s\n", name));
#endif
}
END_TEST;

/**
 * @}
 */

TCase *tc_access(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_create_file);
    tcase_add_test(tc, tf_move_file);
    tcase_add_test(tc, tf_delete_file);
    tcase_add_test(tc, tf_temporary_file);
    tcase_add_test(tc, tf_temporary_name);
    return tc;
}
