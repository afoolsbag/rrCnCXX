#pragma once

#include <check/check.h>

TCase *tcErrorHandling(void);

inline Suite *tsDebug(void)
{
    Suite *const ts = suite_create("Debug");
    suite_add_tcase(ts, tcErrorHandling());
    return ts;
}
