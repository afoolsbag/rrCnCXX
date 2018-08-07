#include "tsuite_reg.h"

#include <check/check.h>

Suite *TSuiteReg(void)
{
	Suite *tsuite = suite_create("Reg");
	suite_add_tcase(tsuite, TCaseIni());
	return tsuite;
}
