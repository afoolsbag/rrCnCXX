/*===-- Nearest Integer Floating-Point Operations --------------*- C -*-===*//**
 *
 * \defgroup gNearest 临近整数的浮点运算
 * \ingroup gNumeric
 *
 * \sa <http://zh.cppreference.com/w/c/numeric/math>
 *
 * \version 2019-01-28
 * \since 2018-07-10
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <math.h>

#include <check.h>

#include "ts_numeric.h"

/**
 * \brief 四舍五入，以远离 0 方向取整。
 */
START_TEST(tf_round)
{
    ck_assert_float_eq(roundf(6.4f), 6.0f);
    ck_assert_double_eq(round(6.5), 7.0);
    ck_assert_ldouble_eq(roundl(6.6L), 7.0L);

    ck_assert_int_eq(lroundf(6.4f), 6L);
    ck_assert_int_eq(lround(6.5), 7L);
    ck_assert_int_eq(lroundl(6.6L), 7L);

    ck_assert_int_eq(llroundf(6.4f), 6LL);
    ck_assert_int_eq(llround(6.5), 7LL);
    ck_assert_int_eq(llroundl(6.6L), 7LL);
}
END_TEST;

/**
 * @}
 */

TCase *tc_math_nearest(void)
{
    TCase *const tc = tcase_create("math_nearest");
    tcase_add_test(tc, tf_round);
    return tc;
}
