/*===-- Character ----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gChar 字符
 * \ingroup gType
 *
 * \sa <https://zh.cppreference.com/w/c/language/arithmetic_types#Character_types>
 * \sa <https://zh.cppreference.com/w/c/language/character_constant>
 * \sa <https://zh.cppreference.com/w/c/language/escape>
 *
 * \version 2018-07-11
 * \since 2016-10-09
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include "rrc/ver.h"
#if C11
# include <uchar.h>
#endif/*C11*/
#if C95
# include <wchar.h>
#endif/*C95*/

#include <check/check.h>

#include "test.h"

START_TEST(test_char)
{
    char ch = 'z';
    ck_assert_int_eq(ch, '\172');  /* Octal */
    ck_assert_int_eq(ch, '\x7a');  /* Hexadecimal */

    wchar_t wch = L'喵';
    ck_assert_int_eq(wch, L'\u55B5');
}
END_TEST;

static char hex_digit_to_char(const int hexint)
{
    return "0123456789ABCDEF"[hexint % 16];
}

START_TEST(test_hex_digit_to_char)
{
    ck_assert_int_eq(hex_digit_to_char(0x7), '7');
    ck_assert_int_eq(hex_digit_to_char(0xA), 'A');
    ck_assert_int_eq(hex_digit_to_char(0xF), 'F');
}
END_TEST;

/** @} */

TCase *tcase_char(void)
{
    TCase *tcase = tcase_create("char");

    tcase_add_test(tcase, test_char);
    tcase_add_test(tcase, test_hex_digit_to_char);

    return tcase;
}
