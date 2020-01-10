/*===-- Type Support -------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupTypes 类型支持
 * \ingroup groupRrC
 *
 * \sa <http://zh.cppreference.com/w/c/types>
 *
 * \version 2020-01-09
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_TYPES_H_
#define RRC_TS_TYPES_H_

#include <check.h>

TCase *tc_array(void);
TCase *tc_enum(void);
TCase *tc_char(void);
TCase *tc_struct(void);

static inline Suite *ts_types(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_array());
    suite_add_tcase(ts, tc_enum());
    suite_add_tcase(ts, tc_char());
    suite_add_tcase(ts, tc_struct());
    return ts;
}

#endif
