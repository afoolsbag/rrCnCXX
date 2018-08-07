/*===-- Floating -----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gFloating 浮点
 * \ingroup gType
 *
 * \sa <https://zh.cppreference.com/w/c/language/arithmetic_types#Real_floating_types>
 * \sa <https://zh.cppreference.com/w/c/language/floating_constant>
 * \sa <https://zh.cppreference.com/w/c/types/limits#Limits_of_floating_point_types>
 *
 * \version 2018-07-10
 * \since 2016-06-27
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check/check.h>

#include "rrc/ver.h"

#include "test.h"

/**
 * \brief 四舍五入地（而非截断地）将浮点型转换为整型
 */
START_TEST(test_float_cast_int_rounding)
{
    ck_assert_int_eq((int)(7.65 + 0.5), 8);
}
END_TEST
