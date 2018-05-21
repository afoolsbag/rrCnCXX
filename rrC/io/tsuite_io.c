#include "io/tsuite_io.h"

Suite *tsuite_io(void)
{
	Suite *ste = suite_create("io");
	//suite_add_tcase(ste, tcase_dirio());
	//suite_add_tcase(ste, tcase_errio());
	//suite_add_tcase(ste, tcase_facs());
	//suite_add_tcase(ste, tcase_fmtio());
	//suite_add_tcase(ste, tcase_fop());
	//suite_add_tcase(ste, tcase_fpos());
	//suite_add_tcase(ste, tcase_unfmtio());
	return ste;
}
