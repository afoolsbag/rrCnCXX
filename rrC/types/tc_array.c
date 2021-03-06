/*===-- Array --------------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupArray 数组
 * \ingroup groupTypes
 *
 * \sa <http://zh.cppreference.com/w/c/language/array>
 * \sa <http://zh.cppreference.com/w/c/language/array_initialization>
 *
 * \version 2020-01-09
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check.h>

#include "c_versions.h"
#include "ts_types.h"

/**
 * \brief 复合字面量、匿名数组。
 *
 * \sa <http://zh.cppreference.com/w/c/language/compound_literal>
 */
START_TEST(tf_array_compound_literals)
{
#if STANDARD_C99 || NORMALIZED_MSC_VERSION
    int *p = (int[]) { 0, 1, 2 };
    ck_assert_int_eq(p[0], 0);
    ck_assert_int_eq(p[1], 1);
    ck_assert_int_eq(p[2], 2);
#endif
}
END_TEST;

/**
 * \brief 变长数组。
 */
START_TEST(tf_variable_length_arrays)
{
#if FEATURE_VLA
#endif
}
END_TEST;


/**
 * @}
 */

TCase *tc_array(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_array_compound_literals);
    tcase_add_test(tc, tf_variable_length_arrays);
    return tc;
}
