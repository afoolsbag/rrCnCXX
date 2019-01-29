/*===-- C Language ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gLanguage C 语言
 * \ingroup gReference
 *
 * \sa ["C language"](http://en.cppreference.com/w/c/language). *cppreference.com*.
 *     *   [Basic concepts](http://en.cppreference.com/w/c/language/basic_concepts)
 *     *   [Keywords](http://en.cppreference.com/w/c/keyword)
 *     *   [Preprocessor](http://en.cppreference.com/w/c/preprocessor)
 *     *   [Statements](http://en.cppreference.com/w/c/language/statements)
 *     *   [Expressions](http://en.cppreference.com/w/c/language/expressions)
 *     *   [Initialization](http://en.cppreference.com/w/c/language/initialization)
 *     *   [Declarations](http://en.cppreference.com/w/c/language/declarations)
 *     *   [Functions](http://en.cppreference.com/w/c/language/functions)
 *     *   Miscellaneous
 *
 * \version 2018-10-15
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_LANGUAGE_TEST_H_
#define RRC_LANGUAGE_TEST_H_

#include <check/check.h>

TCase *tc_array(void);
TCase *tc_character(void);
TCase *tc_structure(void);

inline Suite *ts_language(void)
{
    Suite *const ts = suite_create("language");
    suite_add_tcase(ts, tc_array());
    suite_add_tcase(ts, tc_character());
    suite_add_tcase(ts, tc_structure());
    return ts;
}

#endif/*RRC_LANGUAGE_TEST_H_*/
