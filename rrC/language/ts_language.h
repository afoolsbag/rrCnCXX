/*===-- C Language ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup groupLanguage C 语言
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/language>
 *
 * \version 2020-01-09
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
