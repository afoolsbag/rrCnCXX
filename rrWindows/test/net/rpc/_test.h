#pragma once

#include <check/check.h>

TCase *TCaseGenUuid(void);

inline Suite *TSuiteRPC(void)
{
    Suite *tsuite = suite_create("RPC");
    suite_add_tcase(tsuite, TCaseGenUuid());
    return tsuite;
}
