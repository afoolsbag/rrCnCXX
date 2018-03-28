#include "mem/tsuite_mem.h"

Suite *tsuite_mem(void)
{
	Suite *tsuite = suite_create("mem");
	suite_add_tcase(tsuite, tcase_mem());
	return tsuite;
}
