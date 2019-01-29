/*===-- File Input/Output --------------------------------------*- C -*-===*//**
 *
 * \defgroup gIO 文件输入、输出
 * \ingroup gReference
 *
 * \sa ["文件输入、输出"](http://zh.cppreference.com/w/c/io). *cppreference.com*.
 *
 * \version 2019-01-28
 * \since 2016-11-14
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_IO_TEST_H_
#define RRC_IO_TEST_H_

#include <check/check.h>

TCase *tc_file_access(void);

inline Suite *ts_io(void)
{
    Suite *const ts = suite_create("io");
    suite_add_tcase(ts, tc_file_access());
    return ts;
}

#endif/*RRC_IO_TEST_H_*/
