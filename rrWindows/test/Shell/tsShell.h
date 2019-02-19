/*===-- Windows Shell ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gShell Windows 壳
 * \ingroup gDevelop
 *
 * \sa ["Windows Shell"](https://docs.microsoft.com/windows/desktop/shell/shell-entry). *Microsoft Docs*.
 *
 * \version 2019-02-19
 * \since 2018-05-08
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcWindowsShell(void);

inline Suite *tsShell(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcWindowsShell());
    return ts;
}
