#pragma once

#include <check/check.h>

TCase *TCaseSglInstApp(void);

inline Suite *TSuiteSync(void)
{
    Suite *tsuite = suite_create("Sync");
    suite_add_tcase(tsuite, TCaseSglInstApp());
    return tsuite;
}
