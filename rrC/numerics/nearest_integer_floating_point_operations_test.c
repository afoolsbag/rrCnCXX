/*===-- Nearest Integer Floating-Point Operations --------------*- C -*-===*//**
 *
 * \defgroup gRnd 临近整数的浮点运算
 * \ingroup gNumr
 *
 * \sa <http://zh.cppreference.com/w/c/numeric/math>
 *
 * \version 2018-11-27
 * \since 2018-07-10
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma warning(push)
#pragma warning(disable: 4668)

#include <math.h>

#include <check/check.h>

#pragma warning(pop)

#include "_test.h"
#include "c_versions.h"

#pragma warning(disable: 4100)

/**
 * \brief 四舍五入。
 *        以远离 0 方向取整。
 * \sa <https://zh.cppreference.com/w/c/numeric/math/round>
 */
START_TEST(test_round)
{
#if C99 || MSC

    ck_assert_float_eq(roundf(6.4f), 6.0f);
    ck_assert_double_eq(round(6.5), 7.0);
    ck_assert_ldouble_eq(roundl(6.6L), 7.0L);

    ck_assert_int_eq(lroundf(6.4f), 6L);
    ck_assert_int_eq(lround(6.5), 7L);
    ck_assert_int_eq(lroundl(6.6L), 7L);

    ck_assert_int_eq(llroundf(6.4f), 6LL);
    ck_assert_int_eq(llround(6.5), 7LL);
    ck_assert_int_eq(llroundl(6.6L), 7LL);

#endif
}
END_TEST;

/** @} */

TCase *tc_nearest_integer_floating_point_operations(void)
{
    TCase *const tc = tcase_create("nearest_integer_floating_point_operations");
    tcase_add_test(tc, test_round);
    return tc;
}
