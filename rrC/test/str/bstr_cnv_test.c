/*===-- Byte String Conversions to Numeric Formats -------------*- C -*-===*//**
 *
 * \defgroup gBStrCnv 空终止字节字符串：转换成数值格式
 * \ingroup gStr
 *
 * \sa ["Conversions to numeric formats"](https://zh.cppreference.com/w/c/string/byte#Conversions_to_numeric_formats). *cppreference.com*.
 *
 * \version 2018-07-11
 * \since 2018-02-03
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <assert.h>
#include <float.h>
#include <inttypes.h>
#include <stdlib.h>

#include <check/check.h>
#include "rrc/adp.h"
#include "rrc/def.h"

#include "_test.h"

/**
 * \brief 将字节字符串转换成整数值。
 *        ASCII to Integer.
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/atoi>
 */
START_TEST(test_atoi)
{
    static_assert(sizeof(int) * 8 == 32);
    ck_assert_int_eq(atoi("2147483647"), INT32_MAX);

    static_assert(sizeof(long) * 8 == 32);
    ck_assert_int_eq(atol("2147483647"), INT32_MAX);

#if C99 || MSC
    static_assert(sizeof(long long) * 8 == 64);
    ck_assert_int_eq(atoll("9223372036854775807"), INT64_MAX);
#endif
}
END_TEST;

/**
 * \brief 将字节字符串转换成浮点值
 *        ASCII to Floating.
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/atof>
 */
START_TEST(test_atof)
{
    static_assert(15 <= DBL_DIG);
    ck_assert_double_eq(atof("0.123456789012345"), 0.123456789012345);
}
END_TEST;

/**
 * \brief 将字节字符串转换成整数值。
 *        String to Integer.
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtol>
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtoul>
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtoimax>
 */
START_TEST(test_strtoi)
{
    static_assert(sizeof(long) * 8 == 32);
    ck_assert_int_eq(strtol("2147483647", NULL, 0), INT32_MAX);

#if C99 || MSC
    static_assert(sizeof(long long) * 8 == 64);
    ck_assert_int_eq(strtoll("9223372036854775807", NULL, 0), INT64_MAX);

    static_assert(sizeof(intmax_t) * 8 == 64);
    ck_assert_int_eq(strtoimax("9223372036854775807", NULL, 0), INTMAX_MAX);
#endif

    static_assert(sizeof(unsigned long) * 8 == 32);
    ck_assert_uint_eq(strtoul("0xFFFFFFFF", NULL, 0), UINT32_MAX);

#if C99 || MSC
    static_assert(sizeof(unsigned long long) * 8 == 64);
    ck_assert_uint_eq(strtoull("0xFFFFFFFFFFFFFFFF", NULL, 0), UINT64_MAX);

    static_assert(sizeof(uintmax_t) * 8 == 64);
    ck_assert_int_eq(strtoumax("0xFFFFFFFFFFFFFFFF", NULL, 0), UINTMAX_MAX);
#endif
}
END_TEST;

/**
 * \brief 将字节字符串转换成浮点值。
 *        String to Floating.
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtof>
 */
START_TEST(test_strtof)
{
#if C99 || MSC
    static_assert(6 <= FLT_DIG);
    ck_assert_float_eq(strtof("0.123456", NULL), 0.123456f);
#endif

    static_assert(15 <= DBL_DIG);
    ck_assert_double_eq(strtod("0.123456789012345", NULL), 0.123456789012345);

#if C99
    static_assert(18 <= LDBL_DIG);
    ck_assert_ldouble_eq(strtold("0.123456789012345678", NULL), 0.123456789012345678L);
#elif MSC
    static_assert(15 <= LDBL_DIG);
    ck_assert_ldouble_eq(strtold("0.123456789012345", NULL), 0.123456789012345L);
#endif
}
END_TEST;

/** @} */

TCase *tcase_bstr_cnv(void)
{
    TCase *tcase = tcase_create("bstr_cnv");

    tcase_add_test(tcase, test_atoi);
    tcase_add_test(tcase, test_atof);

    tcase_add_test(tcase, test_strtoi);
    tcase_add_test(tcase, test_strtof);

    return tcase;
}
