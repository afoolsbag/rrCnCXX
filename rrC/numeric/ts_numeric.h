/*===-- Numeric ------------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupNumeric 数值
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/numeric>
 *
 * \version 2020-01-09
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_NUMERIC_H_
#define RRC_TS_NUMERIC_H_

#include <check.h>

TCase *tc_math_nearest(void);
TCase *tc_random(void);

static inline Suite *ts_numeric(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_math_nearest());
    suite_add_tcase(ts, tc_random());
    return ts;
}

#endif
