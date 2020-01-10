/*===-- Date and Time Utilities --------------------------------*- C -*-===*//**
 *
 * \defgroup groupChrono 日期和时间工具
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/chrono>
 *
 * \version 2020-01-09
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_CHRONO_H_
#define RRC_TS_CHRONO_H_

#include <check.h>

TCase *tc_chrono(void);

static inline Suite *ts_chrono(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_chrono());
    return ts;
}

#endif
