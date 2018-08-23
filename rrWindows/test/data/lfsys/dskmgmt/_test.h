#pragma once

#include <check/check.h>

TCase *TCaseDskFS(void);
TCase *TCaseFlrFS(void);

inline Suite *TSuiteDskMgmt(void)
{
    Suite *tsuite = suite_create("DskMgmt");
    suite_add_tcase(tsuite, TCaseDskFS());
    suite_add_tcase(tsuite, TCaseFlrFS());
    return tsuite;
}
