/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gError 错误处理
 * \ingroup gReference
 *
 * \sa ["错误处理"](https://zh.cppreference.com/w/c/error). *cppreference.com*.
 *
 * \version 2019-06-21
 * \since 2019-02-19
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_ERROR_H_
#define RRC_TS_ERROR_H_

#include <check.h>

TCase *tc_error(void);

static inline Suite *ts_error(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_error());
    return ts;
}

#endif
