#include "str/tsuite.h"

Suite *tsuite_str(void)
{
	Suite *tsuite = suite_create("str");
	suite_add_tcase(tsuite, tcase_str_cnv());
	suite_add_tcase(tsuite, tcase_str_man());
	return tsuite;
}
