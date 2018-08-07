/*===-- Structure ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gStruct 结构体
 * \ingroup gType
 *
 * \sa <http://en.cppreference.com/w/c/language/struct>
 * \sa <http://en.cppreference.com/w/c/language/struct_initialization>
 * \sa <http://en.cppreference.com/w/c/language/compound_literal>
 *
 * \version 2018-07-10
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check/check.h>

#include "rrc/ver.h"

#include "test.h"

struct point_t {
    double x, y;
};

/** \brief 复合字面量、匿名数组
 *  \sa ["compound literals"](http://en.cppreference.com/w/c/language/compound_literal). *cppreference.com*. */
START_TEST(test_struct_compound_literals)
{
#if C99
    struct point_t pcl = (struct point_t) { .x = 9, .y = 5 };  /* pointer to compound literals */
    ck_assert_int_eq(pcl.x, 9);
    ck_assert_int_eq(pcl.y, 5);
#endif/*C99*/
}
END_TEST;

/** @} */

TCase *tcase_struct(void)
{
    TCase *tcase = tcase_create("struct");

    tcase_add_test(tcase, test_struct_compound_literals);

    return tcase;
}
