#include "algo/tsuite_algo.h"

Suite *tsuite_algo(void)
{
	Suite *tsuite = suite_create("algo");
	suite_add_tcase(tsuite, tcase_algo());
	return tsuite;
}
