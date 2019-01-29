/*===-- Strings Library ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gStr 字符串库
 * \ingroup gRef
 *
 * \sa ["Strings library"](https://zh.cppreference.com/w/c/string). *cppreference.com*.
 *     *   [Null-terminated byte string management](http://en.cppreference.com/w/c/string/byte)
 *         *   [Character classification](http://en.cppreference.com/w/c/string/byte#Character_classification)
 *         *   [Character manipulation](http://en.cppreference.com/w/c/string/byte#Character_manipulation)
 *         *   [Conversions to numeric formats](http://en.cppreference.com/w/c/string/byte#Conversions_to_numeric_formats)
 *         *   [String manipulation](http://en.cppreference.com/w/c/string/byte#String_manipulation)
 *         *   [String examination](http://en.cppreference.com/w/c/string/byte#String_examination)
 *         *   [Character array manipulation](http://en.cppreference.com/w/c/string/byte#Character_array_manipulation)
 *         *   [Miscellaneous](http://en.cppreference.com/w/c/string/byte#Miscellaneous)
 *     *   [Null-terminated multibyte string management](http://en.cppreference.com/w/c/string/multibyte)
 *         *   [Multibyte/wide character conversions](http://en.cppreference.com/w/c/string/multibyte#Multibyte.2Fwide_character_conversions)
 *     *   [Null-terminated wide string management](http://en.cppreference.com/w/c/string/wide)
 *         *   [Character classification](http://en.cppreference.com/w/c/string/wide#Character_classification)
 *         *   [Character manipulation](http://en.cppreference.com/w/c/string/wide#Character_manipulation)
 *         *   [Conversions to numeric formats](http://en.cppreference.com/w/c/string/wide#Conversions_to_numeric_formats)
 *         *   [String manipulation](http://en.cppreference.com/w/c/string/wide#String_manipulation)
 *         *   [String examination](http://en.cppreference.com/w/c/string/wide#String_examination)
 *         *   [Wide character array manipulation](http://en.cppreference.com/w/c/string/wide#Character_array_manipulation)
 *
 * \version 2018-10-15
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_STRINGS_TEST_H_
#define RRC_STRINGS_TEST_H_

#include <check/check.h>

TCase *tc_byte_strings_conversion(void);
TCase *tc_byte_strings_examination(void);
TCase *tc_byte_strings_manipulation(void);

inline Suite *ts_strings(void)
{
    Suite *const ts = suite_create("strings");
    suite_add_tcase(ts, tc_byte_strings_conversion());
    suite_add_tcase(ts, tc_byte_strings_examination());
    suite_add_tcase(ts, tc_byte_strings_manipulation());
    return ts;
}

#endif/*RRC_STRINGS_TEST_H_*/
