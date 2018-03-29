/*===-- Byte String Examination --------------------------------*- C -*-===*//**
 *
 * \defgroup g_bstr_exam 单字节字符串检验
 * \ingroup g_str
 *
 * \sa ["String examination"](http://en.cppreference.com/w/c/string/byte#String_examination). *cppreference.com*.
 *
 * \version 2018-03-29
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <inttypes.h>
#include <string.h>

#include <check.h>
#include "str/tsuite_str.h"

/** \brief String Length
 *  \sa ["strlen"](http://cplusplus.com/reference/cstring/strlen/). *C++ Reference*.
 *  \sa ["strlen, strnlen_s"](http://en.cppreference.com/w/c/string/byte/strlen). *cppreference.com*. */
START_TEST(test_strlen)
	const char src[] = "zhengrr";
	const size_t len = strlen(src);
	ck_assert_int_eq(len, 7);
END_TEST

/**
 * \brief String Compare
 * \sa ["strcmp"](http://cplusplus.com/reference/cstring/strcmp/). *C++ Reference*.
 * \sa ["strcmp"](http://en.cppreference.com/w/c/string/byte/strcmp). *cppreference.com*.
 */
START_TEST(test_strcmp)
	const char str_upper[] = "ZHENGRR";
	const char str_lower[] = "zhengrr";
	ck_assert(strcmp(str_upper, str_lower) < 0);
	ck_assert(0 < strcmp(str_lower, str_upper));
END_TEST

/** @} */

TCase *tcase_bstr_exam(void)
{
	TCase *tcase = tcase_create("bstr_exam");

	tcase_add_test(tcase, test_strlen);
	tcase_add_test(tcase, test_strcmp);

	return tcase;
}
