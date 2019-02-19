/*===-- Menus and Other Resources ------------------------------*- C -*-===*//**
 *
 * \defgroup gMenuRc 菜单和其它资源
 * \ingroup gDevelop
 *
 * \sa ["Menus and Other Resources"](https://docs.microsoft.com/windows/desktop/MenuRc/). *Microsoft Docs*.
 *     *   Introduction to Resources
 *     *   Carets
 *     *   Cursors
 *     *   Icons
 *     *   Keyboard Accelerators
 *     *   Menus
 *     *   Strings
 *     *   Version Information
 *     *   Resource Compiler
 *
 * \version 2019-02-19
 * \since 2018-02-23
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcStrings(void);

inline Suite *tsMenuRc(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcStrings());
    return ts;
}
