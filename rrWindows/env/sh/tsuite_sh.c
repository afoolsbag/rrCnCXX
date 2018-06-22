#include "tsuite_sh.h"

#include <check/check.h>

Suite *TSuiteSh(void)
{
    Suite *tsuite = suite_create("Sh");
    suite_add_tcase(tsuite, TCaseFExists());
    suite_add_tcase(tsuite, TCaseFOp());
    return tsuite;
}
