#pragma once

#include <check/check.h>

TCase *TCaseFAttr(void);
TCase *TCaseTravFlr(void);

inline Suite *TSuiteFMgmt(void)
{
    Suite *tsuite = suite_create("FMgmt");
    suite_add_tcase(tsuite, TCaseFAttr());
    suite_add_tcase(tsuite, TCaseTravFlr());
    return tsuite;
}
