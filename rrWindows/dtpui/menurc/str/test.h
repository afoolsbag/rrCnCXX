#pragma once

#include <check/check.h>

TCase *TCaseStrCpy(void);
TCase *TCaseToUpper(void);

inline Suite *TSuiteStr(void)
{
	Suite *tsuite = suite_create("Str");
	suite_add_tcase(tsuite, TCaseStrCpy());
	suite_add_tcase(tsuite, TCaseToUpper());
	return tsuite;
}
