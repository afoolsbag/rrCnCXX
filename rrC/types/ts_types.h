/*===-- Type Support -------------------------------------------*- C -*-===*//**
 *
 * \defgroup gTypes 类型支持
 * \ingroup gReference
 *
 * \sa ["类型支持"](http://zh.cppreference.com/w/c/types). *cppreference.com*.
 *     *   语言定义的基础类型
 *     *   附加基本类型及便利宏
 *     *   布尔类型支持
 *     *   定宽整数类型
 *     *   数值极限
 *
 * \version 2019-02-26
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

#endif/*RRC_TYPE_SUPPORT_TEST_H_*/
