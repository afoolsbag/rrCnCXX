#include "numr/tsuite_numr.h"

Suite *tsuite_numr(void)
{
	Suite *tsuite = suite_create("numr");
	suite_add_tcase(tsuite, tcase_lseg1d());
	suite_add_tcase(tsuite, tcase_prn());
	return tsuite;
}
