/*===-- Structure ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gStructure 结构体
 * \ingroup gTypes
 *
 * \sa <http://zh.cppreference.com/w/c/language/struct>
 * \sa <http://zh.cppreference.com/w/c/language/struct_initialization>
 * \sa <http://zh.cppreference.com/w/c/language/compound_literal>
 *
 * \version 2019-02-13
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check.h>

#include "c_versions.h"
#include "ts_types.h"

struct point_t {
    double x, y;
};

/**
 * \brief 复合字面量、匿名结构体。
 *
 * \sa <http://zh.cppreference.com/w/c/language/compound_literal>
 */
START_TEST(tf_struct_compound_literals)
{
#if STANDARD_C99 || NORMALIZED_MSC_VERSION
    const struct point_t s = (struct point_t) { .x = 9., .y = 5. };
    ck_assert_double_eq(s.x, 9.);
    ck_assert_double_eq(s.y, 5.);
#endif
}
END_TEST;

/**
 * @}
 */

TCase *tc_structure(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_struct_compound_literals);
    return tc;
}
