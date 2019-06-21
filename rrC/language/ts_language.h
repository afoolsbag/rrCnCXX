/*===-- C Language ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gLanguage C 语言
 * \ingroup gReference
 *
 * \sa ["C 语言"](http://zh.cppreference.com/w/c/language). *cppreference.com*.
 *     *   基本概念
 *     *   关键词
 *     *   预处理器
 *     *   语句
 *     *   表达式
 *     *   初始化
 *     *   声明
 *     *   函数
 *     *   杂项
 *
 * \version 2019-06-21
 * \since 2018-01-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_LANGUAGE_H_
#define RRC_TS_LANGUAGE_H_

#include <check.h>

static inline Suite *ts_language(void)
{
    Suite *const ts = suite_create(__func__);
    return ts;
}

#endif
