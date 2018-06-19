#include "time/tsuite_time.h"

Suite *tsuite_time(void)
{
	Suite *tsuite = suite_create("time");
	suite_add_tcase(tsuite, tcase_caltm());
	suite_add_tcase(tsuite, tcase_clktm());
	suite_add_tcase(tsuite, tcase_epotm());
	suite_add_tcase(tsuite, tcase_spectm());
	return tsuite;
}
