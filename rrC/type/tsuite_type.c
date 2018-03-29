#include "type/tsuite_type.h"

Suite *tsuite_type(void)
{
	Suite *tsuite = suite_create("type");
	suite_add_tcase(tsuite, tcase_array());
	suite_add_tcase(tsuite, tcase_char());
	suite_add_tcase(tsuite, tcase_struct());
	return tsuite;
}
