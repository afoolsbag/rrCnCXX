/*===-- Localization Support -----------------------------------*- C -*-===*//**
 *
 * \defgroup gLocale 本地化支持
 * \ingroup gReference
 *
 * \version 2019-06-21
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
