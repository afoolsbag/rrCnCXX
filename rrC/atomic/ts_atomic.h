/*===-- Atomic Operations --------------------------------------*- C -*-===*//**
 *
 * \defgroup gAtomic 原子操作
 * \ingroup gReference
 *
 * \sa ["原子操作库"](https://zh.cppreference.com/w/c/atomic). *cppreference.com*.
 *
 * \version 2019-01-28
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_ATOMIC_TEST_H_
#define RRC_ATOMIC_TEST_H_

#include <check/check.h>

TCase *tc_atomic(void);

inline Suite *ts_atomic(void)
{
    Suite *const ts = suite_create("atomic");
    suite_add_tcase(ts, tc_atomic());
    return ts;
}

#endif/*RRC_ATOMIC_TEST_H_*/
