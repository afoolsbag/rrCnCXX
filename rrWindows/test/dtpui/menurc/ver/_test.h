#pragma once

#include <check/check.h>

TCase *TCaseExeVer(void);

inline Suite *TSuiteVer(void)
{
    Suite *tsuite = suite_create("Ver");
    suite_add_tcase(tsuite, TCaseExeVer());
    return tsuite;
}
