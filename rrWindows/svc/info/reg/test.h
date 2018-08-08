#pragma once

#include <check/check.h>

TCase *TCaseIni(void);

inline Suite *TSuiteReg(void)
{
	Suite *tsuite = suite_create("Reg");
	suite_add_tcase(tsuite, TCaseIni());
	return tsuite;
}