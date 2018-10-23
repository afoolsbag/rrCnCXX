#pragma once

#include <check/check.h>

TCase *tcDynamicLinkLibrary(void);

inline Suite *tsDlls(void)
{
    Suite *const ts = suite_create("Dlls");
    suite_add_tcase(ts, tcDynamicLinkLibrary());
    return ts;
}
