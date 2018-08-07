#pragma once

#include <check/check.h>

TCase *TCaseStrXc(void);

inline Suite *TSuiteCharSet(void)
{
	Suite *tsuite = suite_create("CharSet");
	suite_add_tcase(tsuite, TCaseStrXc());
	return tsuite;
}
