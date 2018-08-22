#pragma once

#include <check/check.h>

TCase *TCaseConCtrlHdl(void);

inline Suite *TSuiteCons(void)
{
    Suite *tsuite = suite_create("Cons");
    suite_add_tcase(tsuite, TCaseConCtrlHdl());
    return tsuite;
}
