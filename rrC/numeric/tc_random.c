/*===-- Pseudo-Random Number -----------------------------------*- C -*-===*//**
 *
 * \defgroup groupRandom 伪随机数
 * \ingroup groupNumeric
 *
 * \sa <http://zh.cppreference.com/w/c/numeric/random>
 *
 * \version 2020-01-09
 * \since 2016-10-10
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <check.h>

#include "ts_numeric.h"

START_TEST(tf_pseudo_random_number)
{
    /* 对伪随机数生成器播种 */
    srand((unsigned)time(NULL));

    /* 生成伪随机数 */
    const int r1 = rand();
    ck_assert(0 <= r1 && r1 <= RAND_MAX);
    printf("r1=%d\n", r1);

    const int r2 = rand();
    ck_assert(0 <= r2 && r2 <= RAND_MAX);
    printf("r2=%d\n", r2);

    const int r3 = rand();
    ck_assert(0 <= r3 && r3 <= RAND_MAX);
    printf("r3=%d\n", r3);
}
END_TEST;

/**
 * @}
 */

TCase *tc_random(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_pseudo_random_number);
    return tc;
}
