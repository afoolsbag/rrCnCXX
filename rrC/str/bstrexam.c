/*===-- Byte String Examination --------------------------------*- C -*-===*//**
 *
 * \defgroup g_bstrexam 单字节字符串操作
 * \ingroup g_str
 *
 * \sa ["String manipulation"](http://en.cppreference.com/w/c/string/byte#String_manipulation). *cppreference.com*.
 *
 * \author zhengrr
 * \date 2018-1-5 – 2-2
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <string.h>

#include "str/test.h"

/**
 * \brief 字符串复制（String Copies）
 * \sa ["strcpy, strcpy_s"](http://en.cppreference.com/w/c/string/byte/strcpy). *cppreference.com*.
 */
START_TEST(bstrcpy)
	{
		char dst[4] = "";
		const char src[4] = "abc";

		strcpy(dst, src);

		ck_assert_str_eq(src, dst);
	}
END_TEST

/**
 * \brief 字符串复制（String N Copies）
 * \sa ["strncpy, strncpy_s"](http://en.cppreference.com/w/c/string/byte/strncpy). *cppreference.com*.
 */
START_TEST(bstrncpy)
	{
		char dst[4] = "";
		const char src[4] = "abc";

		strncpy(dst, src, sizeof(dst) - 1);
		dst[sizeof(dst) - 1] = '\0';

		ck_assert_str_eq(src, dst);
	}
END_TEST

/**
 * \brief 字符串链接（String Catenates）
 * \sa ["strcat, strcat_s"](http://en.cppreference.com/w/c/string/byte/strcat). *cppreference.com*.
 */
START_TEST(bstrcat)
	{
		char dst[7] = "abc";
		const char src[4] = "def";

		strcat(dst, src);

		ck_assert_str_eq(dst, "abcdef");
	}
END_TEST

/**
 * \brief 字符串链接（String N Catenates）
 * \sa ["strncat, strncat_s"](http://en.cppreference.com/w/c/string/byte/strncat). *cppreference.com*.
 */
START_TEST(bstrncat)
	{
		char dst[7] = "abc";
		const char src[4] = "def";

		strncat(dst, src, sizeof(dst) - strlen(dst) - 1);

		ck_assert_str_eq(dst, "abcdef");
	}
END_TEST

/**
 * \brief strxfrm
 * \sa ["strxfrm"](http://en.cppreference.com/w/c/string/byte/strxfrm). *cppreference.com*.
 */
START_TEST(bstrxfrm)
	{
	}
END_TEST

/** @} */

TCase *bstrexam_tcs(void)
{
	TCase *tcs = tcase_create("bstrexam");
	tcase_add_test(tcs, bstrcpy);
	tcase_add_test(tcs, bstrncpy);
	tcase_add_test(tcs, bstrcat);
	tcase_add_test(tcs, bstrncat);
	tcase_add_test(tcs, bstrxfrm);
	return tcs;
}
