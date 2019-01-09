#pragma once

#include <check/check.h>

TCase *tcWindowsShell(void);

inline Suite *tsShell(void)
{
    Suite *const ts = suite_create("Shell");
    suite_add_tcase(ts, tcWindowsShell());
    return ts;
}
