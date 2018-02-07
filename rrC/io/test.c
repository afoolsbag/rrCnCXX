#include "io/test.h"

Suite *io_test_suite(void)
{
	Suite *ste = suite_create("io");
	suite_add_tcase(ste, dirio_test_case());
	suite_add_tcase(ste, errio_test_case());
	suite_add_tcase(ste, facs_test_case());
	suite_add_tcase(ste, fmtio_test_case());
	suite_add_tcase(ste, fop_test_case());
	suite_add_tcase(ste, fpos_test_case());
	suite_add_tcase(ste, unfmtio_test_case());
	return ste;
}
