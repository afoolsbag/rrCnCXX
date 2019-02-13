/*===-- C Memory Management Library ----------------------------*- C -*-===*//**
 *
 * \defgroup gMemory C 内存管理库
 * \ingroup gReference
 *
 * \sa ["C 内存管理库"](https://zh.cppreference.com/w/c/memory). *cppreference.com*.
 *
 * \version 2019-02-13
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_MEMORY_H_
#define RRC_TS_MEMORY_H_

#include <check.h>

TCase *tc_memory(void);

static inline Suite *ts_memory(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_memory());
    return ts;
}

#endif/*RRC_TS_MEMORY_H_*/
