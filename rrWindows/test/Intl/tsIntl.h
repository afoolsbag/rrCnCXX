/*===-- Internationalization for Windows Applications ----------*- C -*-===*//**
 *
 * \defgroup gIntl Windows 应用程序国际化
 * \ingroup gDevelop
 *
 * \sa ["Internationalization for Windows Applications"](https://docs.microsoft.com/windows/desktop/Intl/). *Microsoft Docs*.
 *     *   Getting Started with International Windows Development
 *     *   Globalization Services
 *         *   Extended Linguistic Services
 *         *   International Components for Unicode (ICU)
 *         *   Spell Checking API
 *         *   National Language Support
 *     *   Input Method Manager
 *     *   International Fonts and Text Display
 *     *   Multilingual User Interface
 *     *   Unicode and Character Sets
 *     *   Security Considerations: International Features
 *
 * \version 2019-02-19
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcNationalLanguageSupport(void);
TCase *tcUnicodeAndCharacterSets(void);

inline Suite *tsIntl(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcNationalLanguageSupport());
    suite_add_tcase(ts, tcUnicodeAndCharacterSets());
    return ts;
}
