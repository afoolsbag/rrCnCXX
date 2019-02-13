/*===-- Atomic Operations --------------------------------------*- C -*-===*//**
 *
 * \defgroup gAtomic 原子操作
 * \ingroup gReference
 *
 * \sa ["原子操作库"](https://zh.cppreference.com/w/c/atomic). *cppreference.com*.
 *
 * \version 2019-02-13
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_ATOMIC_H_
#define RRC_TS_ATOMIC_H_

#include <check.h>

TCase *tc_atomic(void);

static inline Suite *ts_atomic(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_atomic());
    return ts;
}

#endif/*RRC_TS_ATOMIC_H_*/
