#pragma once

#include <check/check.h>

TCase *tcStrings(void);

inline Suite *tsMenuRc(void)
{
    Suite *const ts = suite_create("MenuRc");
    suite_add_tcase(ts, tcStrings());
    return ts;
}
