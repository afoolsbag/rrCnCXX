#pragma once

#include <check/check.h>

TCase *tcSynchronization(void);

inline Suite *tsSync(void)
{
    Suite *const ts = suite_create("Sync");
    suite_add_tcase(ts, tcSynchronization());
    return ts;
}
