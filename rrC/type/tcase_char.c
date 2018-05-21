/*===-- Character ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gChar 字符
 * \ingroup gType
 *
 * \sa ["Character types"](http://en.cppreference.com/w/c/language/arithmetic_types#Character_types). *cppreference.com*.
 * \sa ["character constant"](http://en.cppreference.com/w/c/language/character_constant). *cppreference.com*.
 * \sa ["Escape sequences"](http://en.cppreference.com/w/c/language/escape). *cppreference.com*.
 *
 * \version 2018-04-25
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include "cver.h"

#if N1040
# include <uchar.h>
#endif/*N1040*/
#if C95
# include <wchar.h>
#endif/*C95*/

#include <check/check.h>
#include "type/tsuite_type.h"

START_TEST(test_char)
	char c = 'z';
	ck_assert_int_eq(c, '\172');  /* Octal */
	ck_assert_int_eq(c, '\x7a');  /* Hexadecimal */

	wchar_t wc = L'喵';
	ck_assert_int_eq(wc, L'\u55B5');
END_TEST

static char hex_digit_to_char(const int hexint)
{
	return "0123456789ABCDEF"[hexint % 16];
}

START_TEST(test_hex_digit_to_char)
	ck_assert_int_eq(hex_digit_to_char(0x7), '7');
	ck_assert_int_eq(hex_digit_to_char(0xA), 'A');
	ck_assert_int_eq(hex_digit_to_char(0xF), 'F');
END_TEST

/** @} */

TCase *tcase_char(void)
{
	TCase *tcase = tcase_create("char");

	tcase_add_test(tcase, test_char);
	tcase_add_test(tcase, test_hex_digit_to_char);

	return tcase;
}