/*===-- Byte String Conversions to Numeric Formats -------------*- C -*-===*//**
 *
 * \defgroup g_bstr_cnv 单字节字符串转换成数值格式
 * \ingroup g_str
 *
 * \sa ["Conversions to numeric formats"](http://en.cppreference.com/w/c/string/byte#Conversions_to_numeric_formats). *cppreference.com*.
 *
 * \version 2018-03-29
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
#include "str/tsuite_str.h"

/** \brief ASCII to Integer
 *  \sa ["atoi, atol, atoll"](http://en.cppreference.com/w/c/string/byte/atoi). *cppreference.com*. */
START_TEST(test_atoi)
	_Static_assert(sizeof(int) == sizeof(int32_t), "int isn't 32bits.");
	const int i = atoi("2147483647");
	ck_assert_int_eq(i, INT32_MAX);
END_TEST

/** \brief ASCII to Long
 *  \sa ["atoi, atol, atoll"](http://en.cppreference.com/w/c/string/byte/atoi). *cppreference.com*. */
START_TEST(test_atol)
	_Static_assert(sizeof(long) == sizeof(int32_t), "long isn't 32bits.");
	const long l = atol("2147483647");
	ck_assert_int_eq(l, INT32_MAX);
END_TEST

/** \brief ASCII to Long-Long
 *  \sa ["atoi, atol, atoll"](http://en.cppreference.com/w/c/string/byte/atoi). *cppreference.com*. */
START_TEST(test_atoll)
#if C99
	_Static_assert(sizeof(long long) == sizeof(int64_t),
		       "long long isn't 64bits.");
	const long long ll = atoll("9223372036854775807");
	ck_assert_int_eq(ll, INT64_MAX);
#endif/*C99*/
END_TEST

/** \brief ASCII to Float
 *  \sa ["atof"](http://en.cppreference.com/w/c/string/byte/atof). *cppreference.com*. */
START_TEST(test_atof)
	_Static_assert(15 <= DBL_DIG, "double's decimal digits less 15.");
	const double d = atof("0.123456789012345");
	ck_assert_double_eq(d, 0.123456789012345);
END_TEST

/** \brief (Byte) String to Long
 *  \sa ["strtol, strtoll"](http://en.cppreference.com/w/c/string/byte/strtol). *cppreference.com*. */
START_TEST(test_strtol)
	_Static_assert(sizeof(long) == sizeof(int32_t), "long isn't 32bits.");
	const long i = strtol("2147483647", NULL, 0);
	ck_assert_int_eq(i, INT32_MAX);
END_TEST

/** \brief (Byte) String to Unsigned-Long
 *  \sa ["strtoul, strtoull"](http://en.cppreference.com/w/c/string/byte/strtoul). *cppreference.com*. */
START_TEST(test_strtoul)
	_Static_assert(sizeof(unsigned long) == sizeof(uint32_t),
		       "unsigned long isn't 32bits.");
	const unsigned long l = strtoul("0xFFFFFFFF", NULL, 0);
	ck_assert_uint_eq(l, UINT32_MAX);
END_TEST

/** \brief (Byte) String to Long-Long
 *  \sa ["strtol, strtoll"](http://en.cppreference.com/w/c/string/byte/strtol). *cppreference.com*. */
START_TEST(test_strtoll)
#if C99
	_Static_assert(sizeof(long long) == sizeof(int64_t),
		       "long long isn't 64bits.");
	const long long ll = strtoll("9223372036854775807", NULL, 0);
	ck_assert_int_eq(ll, INT64_MAX);
#endif/*C99*/
END_TEST

/** \brief (Byte) String to Unsigned-Long-Long
 *  \sa ["strtoul, strtoull"](http://en.cppreference.com/w/c/string/byte/strtoul). *cppreference.com*. */
START_TEST(test_strtoull)
#if C99
	_Static_assert(sizeof(unsigned long long) == sizeof(uint64_t),
		       "unsigned long long isn't 64bits.");
	const unsigned long long ull = strtoull("0xFFFFFFFFFFFFFFFF", NULL, 0);
	ck_assert_uint_eq(ull, UINT64_MAX);
#endif/* C99*/
END_TEST

/** \brief (Byte) String to Integer-Max/Unsigned-Max
 *  \sa ["strtoimax, strtoumax"](http://en.cppreference.com/w/c/string/byte/strtoimax). *cppreference.com*. */
START_TEST(test_strtoimax)
#if C99
	const intmax_t imax = strtoimax("9223372036854775807", NULL, 0);
	ck_assert_int_eq(imax, INTMAX_MAX);
#endif/*C99*/
END_TEST

/** \brief (Byte) String to Integer-Max/Unsigned-Max
 *  \sa ["strtoimax, strtoumax"](http://en.cppreference.com/w/c/string/byte/strtoimax). *cppreference.com*. */
START_TEST(test_strtoumax)
#if C99
	const uintmax_t umax = strtoumax("0xFFFFFFFFFFFFFFFF", NULL, 0);
	ck_assert_int_eq(umax, UINTMAX_MAX);
#endif/*C99*/
END_TEST

/**
 * \brief (Byte) String to Float
 * \sa ["strtof, strtod, strtold"](http://en.cppreference.com/w/c/string/byte/strtof). *cppreference.com*.
 */
START_TEST(test_strtof)
#if C99
	_Static_assert(6 <= FLT_DIG, "float's decimal digits less 6.");
	ck_assert_float_eq(strtof("0.123456", NULL), 0.123456f);
#endif/*C99*/
END_TEST

/**
 * \brief (Byte) String to Double
 * \sa ["strtof, strtod, strtold"](http://en.cppreference.com/w/c/string/byte/strtof). *cppreference.com*.
 */
START_TEST(test_strtod)
	_Static_assert(15 <= DBL_DIG, "double's decimal digits less 15.");
	ck_assert_double_eq(strtod("0.123456789012345", NULL),
			    0.123456789012345);
END_TEST

/**
 * \brief (Byte) String to Long-Double
 * \sa ["strtof, strtod, strtold"](http://en.cppreference.com/w/c/string/byte/strtof). *cppreference.com*.
 */
START_TEST(test_strtold)
#if C99
	_Static_assert(18 <= LDBL_DIG, "long double's decimal digits less 18.");
	ck_assert_ldouble_eq(strtold("0.123456789012345678", NULL),
			     0.123456789012345678L);
#endif/*C99*/
END_TEST

/** @} */

TCase *tcase_bstr_cnv(void)
{
	TCase *tcase = tcase_create("bstr_cnv");

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
