/**
 * \addtogroup gError
 * @{
 */

#define _CRT_SECURE_NO_WARNINGS
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include <check.h>

#include "ts_error.h"

START_TEST(tf_error)
{
    /* 展开为 POSIX 兼容的线程错误号 */
    (void)errno;

    /* 错误码对应的可读描述 */
    const char *const errdesc = strerror(errno);
    (void)errdesc;

    /* 将描述推入 `stderr` 流 */
    perror("perror() test");
}
END_TEST;

/**
 * @}
 */

TCase *tc_error(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_error);
    return tc;
}
