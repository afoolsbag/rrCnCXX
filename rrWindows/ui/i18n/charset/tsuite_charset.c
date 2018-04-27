#include "tsuite_charset.h"

#include <check/check.h>

Suite *TSuiteCharSet(void)
{
	Suite *tsuite = suite_create("CharSet");
	suite_add_tcase(tsuite, TCaseStrXc());
	return tsuite;
}
