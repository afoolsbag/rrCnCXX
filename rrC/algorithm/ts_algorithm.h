/*===-- Algorithms ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupAlgorithm 算法
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/algorithm>
 *
 * \version 2020-01-09
 * \since 2018-06-20
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_ALGORITHM_H_
#define RRC_TS_ALGORITHM_H_

#include <check.h>

TCase *tc_algorithm(void);

static inline Suite *ts_algorithm(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_algorithm());
    return ts;
}

#endif
