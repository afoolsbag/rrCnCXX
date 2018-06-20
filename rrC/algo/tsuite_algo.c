#include "algo/tsuite_algo.h"

Suite *tsuite_algo(void)
{
	Suite *tsuite = suite_create("algo");
	suite_add_tcase(tsuite, tcase_bsrch());
	suite_add_tcase(tsuite, tcase_qsort());
	return tsuite;
}
