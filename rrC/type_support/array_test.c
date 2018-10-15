/*===-- Array --------------------------------------------------*- C -*-===*//**
 *
 * \defgroup gArray 数组
 * \ingroup gType
 *
 * \sa ["Array declaration"](http://en.cppreference.com/w/c/language/array). *cppreference.com*.
 * \sa ["Array initialization"](http://en.cppreference.com/w/c/language/array_initialization). *cppreference.com*.
 *
 * \version 2018-03-29
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check/check.h>
#include "rrc/adp.h"

#include "_test.h"

/**
 * \brief 复合字面量、匿名数组。
 *
 * \sa <http://zh.cppreference.com/w/c/language/compound_literal>
 */
START_TEST(test_array_compound_literals)
{
#if C99
    int *pcl = (int[]) { 0, 1, 2 };  /* pointer to compound literals */
    ck_assert_int_eq(pcl[0], 0);
    ck_assert_int_eq(pcl[0], 0);
    ck_assert_int_eq(pcl[0], 0);
#endif/*C99*/
}
END_TEST;

/** @} */

TCase *tcase_array(void)
{
    TCase *tcase = tcase_create("array");
    tcase_add_test(tcase, test_array_compound_literals);
    return tcase;
}