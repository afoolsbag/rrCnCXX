#include "tsuite_errhdl.h"

#include <check/check.h>

Suite *TSuiteErrHdl(void)
{
    Suite *tsuite = suite_create("ErrHdl");
    suite_add_tcase(tsuite, TCaseErrTxt());
    return tsuite;
}
