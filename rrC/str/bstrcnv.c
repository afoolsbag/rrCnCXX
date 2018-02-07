/*===-- Byte String Conversions To Numeric Formats -------------*- C -*-===*//**
 *
 * \defgroup g_bstrcnv 单字节字符串转换成数值格式
 * \ingroup g_str
 *
 * \sa ["Conversions to numeric formats"](http://en.cppreference.com/w/c/string/byte#Conversions_to_numeric_formats). *cppreference.com*.
 *
 * \author zhengrr
 * \date 2018-2-3
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <inttypes.h>
#include <stdlib.h>

#include "std.h"

#include "str/test.h"

/**
 * \brief ASCII到浮点数（ASCII To Floating-Point）
 *
 * \sa ["atof"](http://en.cppreference.com/w/c/string/byte/atof). *cppreference.com*.
 */
START_TEST(bstratof)
	ck_assert_double_eq(atof("0.012"), 0.012);
END_TEST

/**
 * \brief ASCII到整数（ASCII To Integer）
 *
 * \sa ["atoi, atol, atoll"](http://en.cppreference.com/w/c/string/byte/atoi). *cppreference.com*.
 */
START_TEST(bstratoi)
	ck_assert_int_eq(atoi("666"), 666);
	ck_assert_int_eq(atol("9527"), 9527L);
#if C99
	ck_assert_int_eq(atoll("337845818"), 337845818LL);
#endif/* C99*/
END_TEST

/**
 * \brief 字符串到长整数（String To Long-Integer）
 *
 * \sa ["strtol, strtoll"](http://en.cppreference.com/w/c/string/byte/strtol). *cppreference.com*.
 */
START_TEST(bstrtol)
	ck_assert_int_eq(strtol("9527", NULL, 0), 9527L);
#if C99
	ck_assert_int_eq(strtoll("337845818", NULL, 0), 337845818LL);
#endif/* C99*/
END_TEST

/**
 * \brief 字符串到无符号长整数（String To Long-Integer）
 *
 * \sa ["strtoul, strtoull"](http://en.cppreference.com/w/c/string/byte/strtoul). *cppreference.com*.
 */
START_TEST(bstrtoul)
	ck_assert_int_eq(strtoul("9527", NULL, 0), 9527ul);
#if C99
	ck_assert_int_eq(strtoull("337845818", NULL, 0), 337845818ull);
#endif/* C99*/
END_TEST

/**
 * \brief 字符串到浮点数（String To Floating-Point）
 *
 * \sa ["strtof, strtod, strtold"](http://en.cppreference.com/w/c/string/byte/strtof). *cppreference.com*.
 */
START_TEST(bstrtof)
#if C99
	ck_assert_float_eq(strtof("0.76", NULL), 0.76f);
#endif/* C99*/
	ck_assert_double_eq(strtod("2.17", NULL), 2.17);
#if C99
	ck_assert_ldouble_eq(strtold("888.88", NULL), 888.88L);
#endif/* C99*/
END_TEST

/**
 * \brief 字符串到最长整数（String To Max-Long-Integer）
 *
 * \sa ["strtoimax, strtoumax"](http://en.cppreference.com/w/c/string/byte/strtoimax). *cppreference.com*.
 */
START_TEST(bstrtoimax)
#if C99
	ck_assert_int_eq(strtoimax("337845818", NULL, 0), 337845818LL);
	ck_assert_int_eq(strtoumax("337845818", NULL, 0), 337845818ull);
#endif/* C99*/
END_TEST

/** @} */

TCase *bstrcnv_tcs(void)
{
	TCase *tcs = tcase_create("bstrcnv");
	tcase_add_test(tcs, bstratof);
	tcase_add_test(tcs, bstratoi);
	tcase_add_test(tcs, bstrtol);
	tcase_add_test(tcs, bstrtoul);
	tcase_add_test(tcs, bstrtof);
	tcase_add_test(tcs, bstrtoimax);
	return tcs;
}
