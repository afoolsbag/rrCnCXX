#include "tsuite_dbg.h"

#include <check/check.h>

Suite *TSuiteDbg(void)
{
    Suite *tsuite = suite_create("Dbg");
    suite_add_tcase(tsuite, TCaseErrHdl());
    return tsuite;
}
