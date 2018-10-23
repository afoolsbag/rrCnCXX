#pragma once

#include <check/check.h>

TCase *tcNationalLanguageSupport(void);
TCase *tcUnicodeAndCharacterSets(void);

inline Suite *tsIntl(void)
{
    Suite *const ts = suite_create("Intl");
    suite_add_tcase(ts, tcNationalLanguageSupport());
    suite_add_tcase(ts, tcUnicodeAndCharacterSets());
    return ts;
}
