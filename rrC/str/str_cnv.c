/*===-- (Byte) String Conversions to Numeric Formats -----------*- C -*-===*//**
 *
 * \defgroup g_str_cnv （单字节）字符串转换成数值格式
 * \ingroup g_str
 *
 * \sa ["Conversions to numeric formats"](http://en.cppreference.com/w/c/string/byte#Conversions_to_numeric_formats). *cppreference.com*.
 *
 * \version 2018-03-28
 * \since 2018-02-03
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <float.h>
#include <inttypes.h>
#include <stdlib.h>

#include <check.h>
#include "std.h"
#include "str/tsuite.h"

/** \brief ASCII to Integer
 *  \sa ["atoi, atol, atoll"](http://en.cppreference.com/w/c/string/byte/atoi). *cppreference.com*. */
START_TEST(test_atoi)
	ck_assert_int_eq(atoi("2147483647"), INT32_MAX);
END_TEST

/** \brief ASCII to Long
 *  \sa ["atoi, atol, atoll"](http://en.cppreference.com/w/c/string/byte/atoi). *cppreference.com*. */
START_TEST(test_atol)
	ck_assert_int_eq(atol("2147483647"), INT32_MAX);
END_TEST

/** \brief ASCII to Long-Long
 *  \sa ["atoi, atol, atoll"](http://en.cppreference.com/w/c/string/byte/atoi). *cppreference.com*. */
START_TEST(test_atoll)
#if C99
	ck_assert_int_eq(atoll("9223372036854775807"), INT64_MAX);
#endif/*C99*/
END_TEST

/** \brief ASCII to Float
 *  \sa ["atof"](http://en.cppreference.com/w/c/string/byte/atof). *cppreference.com*. */
START_TEST(test_atof)
	DBL_DIG;
	ck_assert_double_eq(atof("0.123456789012345"), 0.123456789012345);
END_TEST

/** \brief (Byte) String to Long
 *  \sa ["strtol, strtoll"](http://en.cppreference.com/w/c/string/byte/strtol). *cppreference.com*. */
START_TEST(test_strtol)
	ck_assert_int_eq(strtol("2147483647", NULL, 0), INT32_MAX);
END_TEST

/** \brief (Byte) String to Unsigned-Long
 *  \sa ["strtoul, strtoull"](http://en.cppreference.com/w/c/string/byte/strtoul). *cppreference.com*. */
START_TEST(test_strtoul)
	ck_assert_uint_eq(strtoul("4294967295", NULL, 0), UINT32_MAX);
END_TEST

/** \brief (Byte) String to Long-Long
 *  \sa ["strtol, strtoll"](http://en.cppreference.com/w/c/string/byte/strtol). *cppreference.com*. */
START_TEST(test_strtoll)
#if C99
	ck_assert_int_eq(strtoll("9223372036854775807", NULL, 0), INT64_MAX);
#endif/*C99*/
END_TEST

/** \brief (Byte) String to Unsigned-Long-Long
 *  \sa ["strtoul, strtoull"](http://en.cppreference.com/w/c/string/byte/strtoul). *cppreference.com*. */
START_TEST(test_strtoull)
#if C99
	ck_assert_uint_eq(strtoull("18446744073709551615", NULL, 0), UINT64_MAX);
#endif/* C99*/
END_TEST

/** \brief (Byte) String to Integer-Max/Unsigned-Max
 *  \sa ["strtoimax, strtoumax"](http://en.cppreference.com/w/c/string/byte/strtoimax). *cppreference.com*. */
START_TEST(test_strtoimax)
#if C99
	ck_assert_int_eq(strtoimax("9223372036854775807", NULL, 0), INTMAX_MAX);
#endif/*C99*/
END_TEST

/** \brief (Byte) String to Integer-Max/Unsigned-Max
 *  \sa ["strtoimax, strtoumax"](http://en.cppreference.com/w/c/string/byte/strtoimax). *cppreference.com*. */
START_TEST(test_strtoumax)
#if C99
	ck_assert_int_eq(strtoumax("18446744073709551615", NULL, 0), UINTMAX_MAX);
#endif/*C99*/
END_TEST

/**
 * \brief (Byte) String to Float
 * \sa ["strtof, strtod, strtold"](http://en.cppreference.com/w/c/string/byte/strtof). *cppreference.com*.
 */
START_TEST(test_strtof)
#if C99
	FLT_DIG;
	ck_assert_float_eq(strtof("0.123456", NULL), 0.123456f);
#endif/*C99*/
END_TEST

/**
 * \brief (Byte) String to Double
 * \sa ["strtof, strtod, strtold"](http://en.cppreference.com/w/c/string/byte/strtof). *cppreference.com*.
 */
START_TEST(test_strtod)
	DBL_DIG;
	ck_assert_double_eq(strtod("0.123456789012345", NULL), 0.123456789012345);
END_TEST

/**
 * \brief (Byte) String to Long-Double
 * \sa ["strtof, strtod, strtold"](http://en.cppreference.com/w/c/string/byte/strtof). *cppreference.com*.
 */
START_TEST(test_strtold)
#if C99
	LDBL_DIG;
	ck_assert_ldouble_eq(strtold("0.123456789012345678", NULL), 0.123456789012345678L);
#endif/*C99*/
END_TEST

/** @} */

TCase *tcase_str_cnv(void)
{
	TCase *tcase = tcase_create("str_cnv");

	tcase_add_test(tcase, test_atoi);
	tcase_add_test(tcase, test_atol);
	tcase_add_test(tcase, test_atoll);
	tcase_add_test(tcase, test_atof);

	tcase_add_test(tcase, test_strtol);
	tcase_add_test(tcase, test_strtoul);
	tcase_add_test(tcase, test_strtoll);
	tcase_add_test(tcase, test_strtoull);
	tcase_add_test(tcase, test_strtoimax);
	tcase_add_test(tcase, test_strtoumax);
	tcase_add_test(tcase, test_strtof);
	tcase_add_test(tcase, test_strtod);
	tcase_add_test(tcase, test_strtold);

	return tcase;
}
