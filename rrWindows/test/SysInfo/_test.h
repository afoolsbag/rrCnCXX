#pragma once

#include <check/check.h>

TCase *tcRegistry(void);

inline Suite *tsSysInfo(void)
{
    Suite *const ts = suite_create("SysInfo");
    suite_add_tcase(ts, tcRegistry());
    return ts;
}
