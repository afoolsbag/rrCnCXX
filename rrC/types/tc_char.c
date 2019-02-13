/*===-- Character ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gCharacter 字符
 * \ingroup gTypes
 *
 * \sa <https://zh.cppreference.com/w/c/language/arithmetic_types>
 * \sa <https://zh.cppreference.com/w/c/language/character_constant>
 * \sa <https://zh.cppreference.com/w/c/language/escape>
 *
 * \version 2019-02-13
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <check.h>

#include "ts_types.h"
#include "c_versions.h"

#if STANDARD_C11
#include <uchar.h>
#endif
#if STANDARD_C94
#include <wchar.h>
#endif

START_TEST(tf_char)
{
    const char ch = 'z';
    ck_assert_int_eq(ch, '\172');  /* Octal */
    ck_assert_int_eq(ch, '\x7a');  /* Hexadecimal */
}
END_TEST;

START_TEST(tf_wchar_t)
{
    const wchar_t wch = L'喵';
    ck_assert_uint_eq(wch, L'喵');
}
END_TEST;

START_TEST(tf_char1632_t)
{
#if STANDARD_C11
    const char16_t ch16 = u'喵';
    ck_assert_uint_eq(ch16, u'\u55B5');

    const char32_t ch32 = U'喵';
    ck_assert_uint_eq(ch32, U'\U000055B5');
#endif
}
END_TEST;

static char hex_digit_to_char(const int hex)
{
    return "0123456789ABCDEF"[hex & 0xF];
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
    TCase *const tc = tcase_create(__func__);

    tcase_add_test(tc, tf_char);
    tcase_add_test(tc, tf_wchar_t);
    tcase_add_test(tc, tf_char1632_t);
    tcase_add_test(tc, tf_hex_digit_to_char);

    return tc;
}
