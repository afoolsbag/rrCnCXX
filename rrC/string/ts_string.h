/*===-- Strings Library ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gString 字符串库
 * \ingroup gReference
 *
 * \sa ["字符串库"](https://zh.cppreference.com/w/c/string). *cppreference.com*.
 *     *   空终止字节字符串管理
 *         *   字符分类
 *         *   字符操作
 *         *   转换成数值格式
 *         *   字符串操作
 *         *   字符串检验
 *         *   字符数组操作
 *         *   杂项
 *     *   空终止多字节字符串管理
 *     *   空终止宽字符串管理
 *
 * \version 2019-02-13
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_STRING_H_
#define RRC_TS_STRING_H_

#include <check.h>

TCase *tc_string_conversion(void);
TCase *tc_string_examination(void);
TCase *tc_string_manipulation(void);

static inline Suite *ts_string(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_string_conversion());
    suite_add_tcase(ts, tc_string_examination());
    suite_add_tcase(ts, tc_string_manipulation());
    return ts;
}

#endif/*RRC_TS_STRING_H_*/
