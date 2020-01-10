/*===-- Thread Support -----------------------------------------*- C -*-===*//**
 *
 * \defgroup groupThread 线程支持
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/thread>
 *
 * \version 2020-01-09
 * \since 2019-02-19
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_THREAD_H_
#define RRC_TS_THREAD_H_

#include <check.h>

TCase *tc_thread(void);

static inline Suite *ts_thread(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_thread());
    return ts;
}

#endif
