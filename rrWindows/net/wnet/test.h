#pragma once

#include <check/check.h>

TCase *TCaseAcsShrFlr(void);

inline Suite *TSuiteWNet(void)
{
    Suite *tsuite = suite_create("WNet");
    suite_add_tcase(tsuite, TCaseAcsShrFlr());
    return tsuite;
}
