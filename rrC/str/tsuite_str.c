#include "str/tsuite_str.h"

Suite *tsuite_str(void)
{
	Suite *tsuite = suite_create("str");
	suite_add_tcase(tsuite, tcase_bstr_cnv());
	suite_add_tcase(tsuite, tcase_bstr_exam());
	suite_add_tcase(tsuite, tcase_bstr_man());
	return tsuite;
}
