/*===-- Windows System Information -----------------------------*- C -*-===*//**
 *
 * \defgroup gSysInfo Windows系统信息
 * \ingroup gDevelop
 *
 * \sa ["Windows System Information"](https://docs.microsoft.com/windows/desktop/SysInfo/). *Microsoft Docs*
 *     *   Handles and Objects
 *     *   Registry
 *     *   System Information
 *     *   Time
 *     *   Time Provider
 *     *   WaaS Assessment Platform
 *
 * \version 2019-02-19
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcRegistry(void);

inline Suite *tsSysInfo(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcRegistry());
    return ts;
}
