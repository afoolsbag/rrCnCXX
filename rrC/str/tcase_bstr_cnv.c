/*===-- Byte String Conversions to Numeric Formats -------------*- C -*-===*//**
 *
 * \defgroup gBStrCnv 空终止字节字符串：转换成数值格式
 * \ingroup gStr
 *
 * \sa ["Conversions to numeric formats"](http://en.cppreference.com/w/c/string/byte#Conversions_to_numeric_formats). *cppreference.com*.
 *
 * \version 2018-04-25
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

#include "cver.h"
#include "cdef.h"
#include "str/tsuite_str.h"

/** \brief ASCII to Integer.
 *         将字节字符串转换成整数值。
 *  \sa http://en.cppreference.com/w/c/string/byte/atoi */
START_TEST(test_atoi)
	static_assert(sizeof(int) == sizeof(int32_t), "int isn't 32bits.");
	const int i = atoi("2147483647");
	ck_assert_int_eq(i, INT32_MAX);
END_TEST

/** \brief ASCII to Integer.
 *         将字节字符串转换成整数值。
 *  \sa http://en.cppreference.com/w/c/string/byte/atoi */
START_TEST(test_atol)
	static_assert(sizeof(long) == sizeof(int32_t), "long isn't 32bits.");
	const long l = atol("2147483647");
	ck_assert_int_eq(l, INT32_MAX);
END_TEST

/** \brief 将字节字符串转换成整数值（ascii to long-long）。
 *  \sa http://en.cppreference.com/w/c/string/byte/atoi */
START_TEST(test_atoll)
#if C99
	static_assert(sizeof(long long) == sizeof(int64_t),
		      "long long isn't 64bits.");
	const long long ll = atoll("9223372036854775807");
	ck_assert_int_eq(ll, INT64_MAX);
#endif/*C99*/
END_TEST

/** \brief 将字节字符串转换成浮点值（ascii to float）。
 *  \sa http://en.cppreference.com/w/c/string/byte/atof */
START_TEST(test_atof)
	static_assert(15 <= DBL_DIG, "double's decimal digits less 15.");
	const double d = atof("0.123456789012345");
	ck_assert_double_eq(d, 0.123456789012345);
END_TEST

/** \brief 将字节字符串转换成整数值（string to long）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtol */
START_TEST(test_strtol)
	static_assert(sizeof(long) == sizeof(int32_t), "long isn't 32bits.");
	const long i = strtol("2147483647", NULL, 0);
	ck_assert_int_eq(i, INT32_MAX);
END_TEST

/** \brief 将字节字符串转换成无符号整数值（string to unsigned-long）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtoul */
START_TEST(test_strtoul)
	static_assert(sizeof(unsigned long) == sizeof(uint32_t),
		      "unsigned long isn't 32bits.");
	const unsigned long l = strtoul("0xFFFFFFFF", NULL, 0);
	ck_assert_uint_eq(l, UINT32_MAX);
END_TEST

/** \brief 将字节字符串转换成整数值（string to long-long）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtol */
START_TEST(test_strtoll)
#if C99
	static_assert(sizeof(long long) == sizeof(int64_t),
		      "long long isn't 64bits.");
	const long long ll = strtoll("9223372036854775807", NULL, 0);
	ck_assert_int_eq(ll, INT64_MAX);
#endif/*C99*/
END_TEST

/** \brief 将字节字符串转换成无符号整数值（string to unsigned-long-long）
 *  \sa http://en.cppreference.com/w/c/string/byte/strtoul */
START_TEST(test_strtoull)
#if C99
	static_assert(sizeof(unsigned long long) == sizeof(uint64_t),
		      "unsigned long long isn't 64bits.");
	const unsigned long long ull = strtoull("0xFFFFFFFFFFFFFFFF", NULL, 0);
	ck_assert_uint_eq(ull, UINT64_MAX);
#endif/* C99*/
END_TEST

/** \brief 将字节字符串转换成`intmax_t`（string to integer-max）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtoimax */
START_TEST(test_strtoimax)
#if C99
	static_assert(sizeof(intmax_t) == sizeof(int64_t),
		      "intmax_t isn't 64bits.");
	const intmax_t imax = strtoimax("9223372036854775807", NULL, 0);
	ck_assert_int_eq(imax, INTMAX_MAX);
#endif/*C99*/
END_TEST

/** \brief 将字节字符串转换成`uintmax_t`（string to unsigned-max）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtoimax */
START_TEST(test_strtoumax)
#if C99
	static_assert(sizeof(uintmax_t) == sizeof(int64_t),
		      "uintmax_t isn't 64bits.");
	const uintmax_t umax = strtoumax("0xFFFFFFFFFFFFFFFF", NULL, 0);
	ck_assert_int_eq(umax, UINTMAX_MAX);
#endif/*C99*/
END_TEST

/** \brief 将字节字符串转换成浮点值（string to float）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtof */
START_TEST(test_strtof)
#if C99
	static_assert(6 <= FLT_DIG, "float's decimal digits less 6.");
	ck_assert_float_eq(strtof("0.123456", NULL), 0.123456f);
#endif/*C99*/
END_TEST

/** \brief 将字节字符串转换成浮点值（string to double）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtof */
START_TEST(test_strtod)
	static_assert(15 <= DBL_DIG, "double's decimal digits less 15.");
	ck_assert_double_eq(strtod("0.123456789012345", NULL),
			    0.123456789012345);
END_TEST

/** \brief 将字节字符串转换成浮点值（string to long-double）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strtof */
START_TEST(test_strtold)
#if C99
	static_assert(18 <= LDBL_DIG, "long double's decimal digits less 18.");
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