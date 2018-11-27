/*===-- Array --------------------------------------------------*- C -*-===*//**
 *
 * \defgroup gArray 数组
 * \ingroup gLang
 *
 * \sa ["Array declaration"](http://en.cppreference.com/w/c/language/array). *cppreference.com*.
 * \sa ["Array initialization"](http://en.cppreference.com/w/c/language/array_initialization). *cppreference.com*.
 *
 * \version 2018-11-27
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check/check.h>

#include "_test.h"
#include "c_versions.h"

#pragma warning(disable: 4100)

/**
 * \brief 复合字面量、匿名数组。
 *
 * \sa <http://zh.cppreference.com/w/c/language/compound_literal>
 */
START_TEST(tf_array_compound_literals)
{
#if C99
    int *p = (int[]) { 0, 1, 2 };  /* pointer to compound literals */
    ck_assert_int_eq(p[0], 0);
    ck_assert_int_eq(p[0], 0);
    ck_assert_int_eq(p[0], 0);
#endif
}
END_TEST;

/** @} */

TCase *tc_array(void)
{
    TCase *const tc = tcase_create("array");
    tcase_add_test(tc, tf_array_compound_literals);
    return tc;
}
