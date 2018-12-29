/*===-- Pseudo-Random Number -----------------------------------*- C -*-===*//**
 *
 * \defgroup gPRN 伪随机数
 * \ingroup gNumr
 *
 * \sa ["Pseudo-random number generation"](http://en.cppreference.com/w/c/numeric/random). *cppreference.com*.
 *
 * \version 2018-12-29
 * \since 2016-10-10
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma warning(push)
#pragma warning(disable: 4820 4668)

#include <stdlib.h>
#include <time.h>

#include <check/check.h>

#pragma warning(pop)

#include "_test.h"

#pragma warning(disable: 4100)

/**
 * \brief 依据当前时间生成伪随机数。
 *        Generate Pseudo-Random Number (By Current Time).
 *         
 * \returns 生成的伪随机数，范围在 [0, RAND_MAX]。
 */
static int generate_pseudo_random_number(void)
{
    srand((unsigned)time(NULL));
    return rand();
}

START_TEST(tf_generate_pseudo_random_number)
{
    generate_pseudo_random_number();
}
END_TEST

/** @} */

TCase *tc_pseudo_random_number(void)
{
    TCase *const tc = tcase_create("pseudo_random_number");
    tcase_add_test(tc, tf_generate_pseudo_random_number);
    return tc;
}
