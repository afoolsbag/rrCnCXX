/*===-- Dynamic-Link Libraries ---------------------------------*- C -*-===*//**
 *
 * \defgroup gDlls 动态链接库
 * \ingroup gDevelop
 *
 * \sa ["Dynamic-Link Libraries"](https://docs.microsoft.com/windows/desktop/Dlls/). *Microsoft Docs*.
 *
 * \version 2019-02-19
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcDynamicLinkLibrary(void);

inline Suite *tsDlls(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcDynamicLinkLibrary());
    return ts;
}
