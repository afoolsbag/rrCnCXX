#include "test.h"

Suite *str_ste(void)
{
	Suite *ste = suite_create("str");
	suite_add_tcase(ste, bstrcnv_tcs());
	suite_add_tcase(ste, bstrexam_tcs());
	return ste;
}