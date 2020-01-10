/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \defgroup groupError 错误处理
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/error>
 *
 * \version 2020-01-09
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
