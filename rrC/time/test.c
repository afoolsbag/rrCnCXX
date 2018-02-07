#include "test.h"

Suite *time_ste(void)
{
	Suite *ste = suite_create("time");
	suite_add_tcase(ste, time_tcs());
	return ste;
}
