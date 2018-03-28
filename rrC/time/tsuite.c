#include "time/tsuite.h"

Suite *tsuite_time(void)
{
	Suite *tsuite = suite_create("time");
	suite_add_tcase(tsuite, tcase_time());
	return tsuite;
}
