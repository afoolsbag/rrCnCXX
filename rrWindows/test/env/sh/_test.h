#pragma once

#include <check/check.h>

TCase *TCaseFExists(void);
TCase *TCaseFOp(void);

inline Suite *TSuiteSh(void)
{
    Suite *tsuite = suite_create("Sh");
    suite_add_tcase(tsuite, TCaseFExists());
    suite_add_tcase(tsuite, TCaseFOp());
    return tsuite;
}
