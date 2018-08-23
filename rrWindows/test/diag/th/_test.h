#pragma once

#include <check/check.h>

TCase *TCaseCntProc(void);

inline Suite *TSuiteTH(void)
{
    Suite *tsuite = suite_create("ToolHelp");
    suite_add_tcase(tsuite, TCaseCntProc());
    return tsuite;
}
