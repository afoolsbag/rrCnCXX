/*===-- Type Support -------------------------------------------*- C -*-===*//**
 *
 * \defgroup gType 类型支持
 * \ingroup gRef
 *
 * \sa ["Type support"](http://en.cppreference.com/w/c/types). *cppreference.com*.
 *     + [Fundamental types defined by the language](http://en.cppreference.com/w/c/language/types)
 *     + Additional basic types and convenience macros
 *     + [Boolean type support](http://en.cppreference.com/w/c/types/boolean)
 *     + [Fixed width integer types](http://en.cppreference.com/w/c/types/integer)
 *     + [Numeric limits](http://en.cppreference.com/w/c/types/limits)
 *
 * \version 2018-10-15
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright CC0 1.0
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TYPE_SUPPORT_TEST_H_
#define RRC_TYPE_SUPPORT_TEST_H_

#include <check.h>

static inline Suite *ts_type_support(void)
{
    Suite *const ts = suite_create("type_support");
    return ts;
}

#endif/*RRC_TYPE_SUPPORT_TEST_H_*/
