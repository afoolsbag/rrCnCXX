/*===-- Consoles -----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gConsole 控制台
 * \ingroup gDevelop
 *
 * \sa ["Consoles"](https://docs.microsoft.com/windows/console/). *Microsoft Docs*.
 *
 * \version 2019-02-19
 * \since 2018-05-03
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcConsoleVirtualTerminalSequences(void);

inline Suite *tsConsole(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcConsoleVirtualTerminalSequences());
    return ts;
}
