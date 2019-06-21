/*===-- Input/Output -------------------------------------------*- C -*-===*//**
 *
 * \defgroup gIO 文件输入、输出
 * \ingroup gFileIO
 *
 * \version 2019-06-21
 * \since 2019-02-13
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include "ts_io.h"

/**
 * \brief 直接输入、输出
 * \sa <https://en.cppreference.com/w/c/io/fwrite>
 * \sa <https://en.cppreference.com/w/c/io/fread>
 */
START_TEST(tf_direct_io)
{
    bool okay = false;
    
    const double data[] = {1., 3., 3., 7.};
    const size_t size = sizeof *data;
    const size_t count = sizeof data / size;

    double *buf = malloc(count * size);
    if (!buf) {
        perror("malloc() failed");
        goto exit;
    }

    FILE *tp = tmpfile();
    if (!tp) {
        perror("tmpfile() failed");
        goto exit_free;
    }

    /* 写入 */
    if (fwrite(data, size, count, tp) != count) {
        perror("fwrite() failed");
        goto exit_close;
    }

    rewind(tp);

    /* 读出 */
    if (fread(buf, size, count, tp) < count && !feof(tp)) {
        perror("fread() failed");
        goto exit_close;
    }

    if (memcmp(buf, data, count * size)) {
        fputs("assert_mem_eq abort", stderr);
        goto exit_close;
    }

    okay = true;

exit_close:
    fclose(tp);
exit_free:
    free(buf);
exit:
    if (!okay)
        ck_abort();
}
END_TEST;

/**
 * \brief 无格式输入、输出
 */
START_TEST(tf_unformatted_io)
{
}
END_TEST;

/**
 * \brief 有格式输入、输出
 */
START_TEST(tf_formatted_io)
{
}
END_TEST;

/**
 * @}
 */

TCase *tc_io(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_direct_io);
    tcase_add_test(tc, tf_unformatted_io);
    tcase_add_test(tc, tf_formatted_io);
    return tc;
}
