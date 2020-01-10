/*===-- Atomic Operations --------------------------------------*- C -*-===*//**
 *
 * \defgroup groupAtomic 原子操作
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/atomic>
 *
 * \version 2020-01-09
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

#endif
