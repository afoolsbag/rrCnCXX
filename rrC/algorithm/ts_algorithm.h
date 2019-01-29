/*===-- Algorithms ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gAlgorithm 算法
 * \ingroup gReference
 *
 * \sa ["算法"](https://zh.cppreference.com/w/c/algorithm). *cppreference.com*.
 *
 * \version 2019-01-28
 * \since 2018-06-20
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_ALGORITHM_TEST_H_
#define RRC_ALGORITHM_TEST_H_

#include <check/check.h>

TCase *tc_algorithm(void);

inline Suite *ts_algorithm(void)
{
    Suite *const ts = suite_create("algorithm");
    suite_add_tcase(ts, tc_algorithm());
    return ts;
}

#endif/*RRC_ALGORITHM_TEST_H_*/
