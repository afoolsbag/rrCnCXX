#include "tsuite_ver.h"

#include <check/check.h>

Suite *TSuiteVer(void)
{
	Suite *tsuite = suite_create("Ver");
	suite_add_tcase(tsuite, TCaseExeVer());
	return tsuite;
}
