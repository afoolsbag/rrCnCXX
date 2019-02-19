/*===-- Debugging and Error Handling ---------------------------*- C -*-===*//**
 *
 * \defgroup gDebug 调试和错误处理
 * \ingroup gDevelop
 *
 * \sa ["Debugging and Error Handling"](https://docs.microsoft.com/windows/desktop/Debug/). *Microsoft Docs*.
 *     *   Application Recovery and Restart
 *     *   Error Handling
 *     *   Basic Debugging
 *     *   Debug Help Library
 *     *   Structured Exception Handling
 *     *   Wait Chain Traversal
 *     *   Intel AVX
 *
 * \version 2019-02-19
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcErrorHandling(void);

inline Suite *tsDebug(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcErrorHandling());
    return ts;
}
