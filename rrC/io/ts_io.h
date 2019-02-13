/*===-- File Input/Output --------------------------------------*- C -*-===*//**
 *
 * \defgroup gFileIO 文件输入、输出
 * \ingroup gReference
 *
 * \sa ["文件输入、输出"](http://zh.cppreference.com/w/c/io). *cppreference.com*.
 *
 * \version 2019-02-13
 * \since 2016-11-14
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_IO_H_
#define RRC_TS_IO_H_

#include <check.h>

TCase *tc_access(void);
TCase *tc_io(void);
TCase *tc_positioning(void);

static inline Suite *ts_io(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_access());
    suite_add_tcase(ts, tc_io());
    suite_add_tcase(ts, tc_positioning());
    return ts;
}

#endif/*RRC_TS_IO_H_*/
