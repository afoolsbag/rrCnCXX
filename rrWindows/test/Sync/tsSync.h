/*===-- Synchronization ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gSync 同步
 * \ingroup gDevelop
 *
 * \sa ["Synchronization"](https://docs.microsoft.com/windows/desktop/Sync/). *Microsoft Docs*.
 *
 * \version 2019-02-19
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcSynchronization(void);

inline Suite *tsSync(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcSynchronization());
    return ts;
}
