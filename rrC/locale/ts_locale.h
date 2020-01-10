/*===-- Localization Support -----------------------------------*- C -*-===*//**
 *
 * \defgroup groupLocale 本地化支持
 * \ingroup groupRrC
 *
 * \sa <https://zh.cppreference.com/w/c/locale>
 *
 * \version 2020-01-09
 * \since 2019-06-21
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_TS_LOCALE_H_
#define RRC_TS_LOCALE_H_

#include <check.h>

static inline Suite *ts_locale(void)
{
    Suite *const ts = suite_create(__func__);
    return ts;
}

#endif
