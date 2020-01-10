/*===-- Strings Library ----------------------------------------*- C -*-===*//**
 *
 * \defgroup groupString 字符串库
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/string>
 *
 * \version 2020-01-09
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_STRING_H_
#define RRC_TS_STRING_H_

#include <check.h>

TCase *tc_string_conversion(void);
TCase *tc_string_examination(void);
TCase *tc_string_manipulation(void);

static inline Suite *ts_string(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_string_conversion());
    suite_add_tcase(ts, tc_string_examination());
    suite_add_tcase(ts, tc_string_manipulation());
    return ts;
}

#endif
