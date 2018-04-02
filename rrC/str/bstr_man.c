/*===-- Byte String Manipulation -------------------------------*- C -*-===*//**
 *
 * \defgroup g_bstr_man 单字节字符串操作
 * \ingroup g_str
 *
 * \sa ["String manipulation"](http://en.cppreference.com/w/c/string/byte#String_manipulation). *cppreference.com*.
 *
 * \version 2018-03-29
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <string.h>

#include <check/check.h>
#include "str/tsuite_str.h"

/** \brief 字符串复制（String Copies）
 *  \sa ["strcpy, strcpy_s"](http://en.cppreference.com/w/c/string/byte/strcpy). *cppreference.com*. */
START_TEST(test_strcpy)
	char dst[8] = "";
	const char src[] = "zhengrr";
	strcpy(dst, src);
	ck_assert_str_eq(src, dst);
END_TEST

/** \brief 字符串复制（String N Copies）
 *  \sa ["strncpy, strncpy_s"](http://en.cppreference.com/w/c/string/byte/strncpy). *cppreference.com*. */
START_TEST(test_strncpy)
	char dst[8] = "";
	const char src[] = "zhengrr";
	strncpy(dst, src, sizeof(dst) - 1);
	dst[sizeof(dst) - 1] = '\0';
	ck_assert_str_eq(src, dst);
END_TEST

/** \brief 字符串链接（String Catenates）
 *  \sa ["strcat, strcat_s"](http://en.cppreference.com/w/c/string/byte/strcat). *cppreference.com*. */
START_TEST(test_strcat)
	char dst[8] = "zheng";
	const char src[] = "rr";
	strcat(dst, src);
	ck_assert_str_eq(dst, "zhengrr");
END_TEST

/** \brief 字符串链接（String N Catenates）
 *  \sa ["strncat, strncat_s"](http://en.cppreference.com/w/c/string/byte/strncat). *cppreference.com*. */
START_TEST(test_strncat)
	char dst[8] = "zheng";
	const char src[] = "rr";
	strncat(dst, src, sizeof(dst) - strlen(dst) - 1);
	ck_assert_str_eq(dst, "zhengrr");
END_TEST

/** \brief strxfrm
 *  \sa ["strxfrm"](http://en.cppreference.com/w/c/string/byte/strxfrm). *cppreference.com*. */
START_TEST(test_strxfrm)
END_TEST

/** @} */

TCase *tcase_bstr_man(void)
{
	TCase *tcase = tcase_create("bstr_man");

	tcase_add_test(tcase, test_strcpy);
	tcase_add_test(tcase, test_strncpy);

	tcase_add_test(tcase, test_strcat);
	tcase_add_test(tcase, test_strncat);

	tcase_add_test(tcase, test_strxfrm);

	return tcase;
}
