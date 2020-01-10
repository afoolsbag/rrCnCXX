/*===-- Enumeration --------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupEnum 结构体
 * \ingroup groupTypes
 *
 * \sa <https://zh.cppreference.com/w/c/language/enum>
 *
 * \version 2020-01-09
 * \since 2019-02-26
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check.h>

#include "c_versions.h"
#include "ts_types.h"

enum abc_t { a = 1, b = 2, c = 3 };

/**
 * \brief 枚举范围外的强制转换。
 */
START_TEST(tf_cast)
{
    const int i = 9;
    enum abc_t e = (enum abc_t)i;
    (void)e;
}
END_TEST;

/**
 * @}
 */

TCase *tc_enum(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_cast);
    return tc;
}
