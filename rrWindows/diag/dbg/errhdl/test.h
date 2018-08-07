#pragma once

#include <check/check.h>

TCase *TCaseErrTxt(void);

inline Suite *TSuiteErrHdl(void)
{
    Suite *tsuite = suite_create("ErrHdl");
    suite_add_tcase(tsuite, TCaseErrTxt());
    return tsuite;
}
