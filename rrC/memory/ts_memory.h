/*===-- C Memory Management Library ----------------------------*- C -*-===*//**
 *
 * \defgroup gMemory C 内存管理库
 * \ingroup gReference
 *
 * \sa ["C 内存管理库"](https://zh.cppreference.com/w/c/memory). *cppreference.com*.
 *
 * \version 2019-01-28
 * \since 2016-12-02
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_MEMORY_TEST_H_
#define RRC_MEMORY_TEST_H_

#include <check.h>

TCase *tc_memory(void);

static inline Suite *ts_memory(void)
{
    Suite *const ts = suite_create("memory");
    suite_add_tcase(ts, tc_memory());
    return ts;
}

#endif/*RRC_MEMORY_TEST_H_*/
