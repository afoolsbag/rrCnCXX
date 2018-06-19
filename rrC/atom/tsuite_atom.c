#include "tsuite_atom.h"

Suite *tsuite_atom(void)
{
	Suite *tsuite = suite_create("atomic");
	suite_add_tcase(tsuite, tcase_atom());
	return tsuite;
}
