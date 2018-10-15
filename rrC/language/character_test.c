/*===-- Character ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gChar 字符
 * \ingroup gLang
 *
 * \sa <https://zh.cppreference.com/w/c/language/arithmetic_types#Character_types>
 * \sa <https://zh.cppreference.com/w/c/language/character_constant>
 * \sa <https://zh.cppreference.com/w/c/language/escape>
 *
 * \version 2018-10-15
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright The Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check/check.h>

#include "_test.h"
#include "c_versions.h"

#if C11
# include <uchar.h>
#endif
#if C95
# include <wchar.h>
#endif

START_TEST(tf_char)
{
    const char ch = 'z';
    ck_assert_int_eq(ch, '\172');  /* Octal */
    ck_assert_int_eq(ch, '\x7a');  /* Hexadecimal */

    const wchar_t wch = L'喵';
    ck_assert_int_eq(wch, L'\u55B5');
}
END_TEST;

static char hex_digit_to_char(const int hex)
{
    return "0123456789ABCDEF"[hex % 16];
}

START_TEST(tf_hex_digit_to_char)
{
    ck_assert_int_eq(hex_digit_to_char(0x7), '7');
    ck_assert_int_eq(hex_digit_to_char(0xA), 'A');
    ck_assert_int_eq(hex_digit_to_char(0xF), 'F');
}
END_TEST;

/** @} */

TCase *tc_character(void)
{
    TCase *const tc = tcase_create("character");

    tcase_add_test(tc, tf_char);
    tcase_add_test(tc, tf_hex_digit_to_char);

    return tc;
}
