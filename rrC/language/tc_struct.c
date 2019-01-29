/*===-- Structure ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gStruct 结构体
 * \ingroup gLang
 *
 * \sa <http://en.cppreference.com/w/c/language/struct>
 * \sa <http://en.cppreference.com/w/c/language/struct_initialization>
 * \sa <http://en.cppreference.com/w/c/language/compound_literal>
 *
 * \version 2019-01-28
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check/check.h>

#include "ts_language.h"

#include "c_versions.h"

struct point_t {
    double x, y;
};

/** \brief 复合字面量、匿名数组
 *  \sa ["compound literals"](http://en.cppreference.com/w/c/language/compound_literal). *cppreference.com*. */
START_TEST(tf_struct_compound_literals)
{
#if C99
    struct point_t pcl = (struct point_t) { .x = 9, .y = 5 };  /* pointer to compound literals */
    ck_assert_int_eq(pcl.x, 9);
    ck_assert_int_eq(pcl.y, 5);
#endif
}
END_TEST;

/** @} */

TCase *tc_structure(void)
{
    TCase *const tc = tcase_create("struct");
    tcase_add_test(tc, tf_struct_compound_literals);
    return tc;
}
