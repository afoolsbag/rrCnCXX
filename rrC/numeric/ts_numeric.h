/*===-- Numerics -----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gNumeric 数值
 * \ingroup gReference
 *
 * \sa ["数值"](http://zh.cppreference.com/w/c/numeric). *cppreference.com*.
 *     *   常用数学函数
 *     *   浮点环境
 *     *   伪随机数生成
 *     *   复数算术
 *     *   泛型数学
 *
 * \version 2019-01-29
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_NUMERIC_TEST_H_
#define RRC_NUMERIC_TEST_H_

#include <check/check.h>

TCase *tc_math_nearest(void);
TCase *tc_random(void);

inline Suite *ts_numeric(void)
{
    Suite *const ts = suite_create("numeric");
    suite_add_tcase(ts, tc_math_nearest());
    suite_add_tcase(ts, tc_random());
    return ts;
}

#endif/*RRC_NUMERIC_TEST_H_*/
