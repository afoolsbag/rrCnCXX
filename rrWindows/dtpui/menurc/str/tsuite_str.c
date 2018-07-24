#include "tsuite_str.h"

#include <check/check.h>

Suite *TSuiteStr(void)
{
	Suite *tsuite = suite_create("Str");
	suite_add_tcase(tsuite, TCaseStrCpy());
	suite_add_tcase(tsuite, TCaseToUpper());
	return tsuite;
}
