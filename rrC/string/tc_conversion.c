/*===-- String Conversion --------------------------------------*- C -*-===*//**
 *
 * \defgroup groupStringConversion 字符串转换
 * \ingroup groupString
 *
 * \version 2020-01-09
 * \since 2018-02-03
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <assert.h>
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

#include <check.h>

#include "ts_string.h"
#include "c_versions.h"

#if NORMALIZED_MSC_VERSION
#pragma warning(push)
#pragma warning(disable: 4127)
#endif

/**
 * \brief ASCII 字符串到整值（ASCII to Integer）
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/atoi>
 */
START_TEST(tf_atoi)
{
    if (sizeof(int) == 4)
        ck_assert_int_eq(atoi("2147483647"), INT32_MAX);
    else
        ck_abort_msg("sizeof(int) = %zu", sizeof(int));

    if (sizeof(long) == 4)
        ck_assert_int_eq(atol("2147483647"), INT32_MAX);
    else if(sizeof(long) == 8)
        ck_assert_int_eq(atol("9223372036854775807"), INT64_MAX);
    else
        ck_abort_msg("sizeof(long) = %zu", sizeof(long));

#if STANDARD_C99 || NORMALIZED_MSC_VERSION
    if (sizeof(long long) == 8)
        ck_assert_int_eq(atoll("9223372036854775807"), INT64_MAX);
    else
        ck_abort_msg("sizeof(long long) = %zu", sizeof(long long));
#endif
}
END_TEST;

/**
 * \brief ASCII 字符串到浮点值（ASCII to Floating）
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/atof>
 */
START_TEST(tf_atof)
{
    if (15 <= DBL_DIG)
        ck_assert_double_eq(atof("0.123456789012345"), 0.123456789012345);
    else
        ck_abort_msg("DBL_DIG = %d", DBL_DIG);
}
END_TEST;

/**
 * \brief 字符串到整值（String to Integer）
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtol>
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtoul>
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtoimax>
 */
START_TEST(tf_strtoi)
{
    if (sizeof(long) == 4)
        ck_assert_int_eq(strtol("2147483647", NULL, 0), INT32_MAX);
    else if(sizeof(long) == 8)
        ck_assert_int_eq(strtol("9223372036854775807", NULL, 0), INT64_MAX);
    else
        ck_abort_msg("sizeof(long) = %zu", sizeof(long));

#if STANDARD_C99 || NORMALIZED_MSC_VERSION
    if (sizeof(long long) == 8)
        ck_assert_int_eq(strtoll("9223372036854775807", NULL, 0), INT64_MAX);
    else
        ck_abort_msg("sizeof(long long) = %zu", sizeof(long long));

    if (sizeof(intmax_t) == 8)
        ck_assert_int_eq(strtoimax("9223372036854775807", NULL, 0), INTMAX_MAX);
    else
        ck_abort_msg("sizeof(intmax_t) = %zu", sizeof(intmax_t));
#endif

    if (sizeof(unsigned long) == 4)
        ck_assert_uint_eq(strtoul("0xFFFFFFFF", NULL, 0), UINT32_MAX);
    else if(sizeof(unsigned long) == 8)
        ck_assert_uint_eq(strtoul("0xFFFFFFFFFFFFFFFF", NULL, 0), UINT64_MAX);
    else
        ck_abort_msg("sizeof(unsigned long) = %zu", sizeof(unsigned long));

#if STANDARD_C99 || NORMALIZED_MSC_VERSION
    if (sizeof(unsigned long long) == 8)
        ck_assert_uint_eq(strtoull("0xFFFFFFFFFFFFFFFF", NULL, 0), UINT64_MAX);
    else
        ck_abort_msg("sizeof(unsigned long long) = %zu", sizeof(unsigned long long));

    if (sizeof(uintmax_t) == 8)
        ck_assert_int_eq(strtoumax("0xFFFFFFFFFFFFFFFF", NULL, 0), UINTMAX_MAX);
    else
        ck_abort_msg("sizeof(uintmax_t) = %zu", sizeof(uintmax_t));
#endif
}
END_TEST;

/**
 * \brief 字符串到浮点值（String to Floating）
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strtof>
 */
START_TEST(tf_strtof)
{
#if STANDARD_C99 || NORMALIZED_MSC_VERSION
    if (6 <= FLT_DIG)
        ck_assert_float_eq(strtof("0.123456", NULL), 0.123456f);
    else
        ck_abort_msg("FLT_DIG = %d", FLT_DIG);
#endif

    if (15 <= DBL_DIG)
        ck_assert_double_eq(strtod("0.123456789012345", NULL), 0.123456789012345);
    else
        ck_abort_msg("DBL_DIG = %d", DBL_DIG);

#if STANDARD_C99
    if (18 <= LDBL_DIG)
        ck_assert_ldouble_eq(strtold("0.123456789012345678", NULL), 0.123456789012345678L);
    else
        ck_abort_msg("LDBL_DIG = %d", LDBL_DIG);
#elif NORMALIZED_MSC_VERSION
    if (15 <= LDBL_DIG)
        ck_assert_ldouble_eq(strtold("0.123456789012345", NULL), 0.123456789012345L);
    else
        ck_abort_msg("DBL_DIG = %d", LDBL_DIG);
#endif
}
END_TEST;

#if NORMALIZED_MSC_VERSION
#pragma warning(pop)
#endif

/**
 * @}
 */

TCase *tc_string_conversion(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_atoi);
    tcase_add_test(tc, tf_atof);
    tcase_add_test(tc, tf_strtoi);
    tcase_add_test(tc, tf_strtof);
    return tc;
}
