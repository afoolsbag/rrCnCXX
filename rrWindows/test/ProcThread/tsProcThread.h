/*===-- Processes and Threads ----------------------------------*- C -*-===*//**
 *
 * \defgroup gProcThread 进程和线程
 * \ingroup gDevelop
 *
 * \sa ["Processes and Threads"](https://docs.microsoft.com/windows/desktop/ProcThread/). *Microsoft Docs*.
 *
 * \version 2018-10-18
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcProcessesAndThreads(void);

inline Suite *tsProcThread(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcProcessesAndThreads());
    return ts;
}
