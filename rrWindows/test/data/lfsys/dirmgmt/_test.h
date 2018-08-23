#pragma once

#include <check/check.h>

TCase *TCaseCr8Flr(void);
TCase *TCaseRmFlr(void);

inline Suite *TSuiteDirMgmt(void)
{
    Suite *tsuite = suite_create("DirMgmt");
    suite_add_tcase(tsuite, TCaseCr8Flr());
    suite_add_tcase(tsuite, TCaseRmFlr());
    return tsuite;
}
