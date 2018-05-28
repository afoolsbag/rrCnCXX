#include "tsuite_basdbg.h"

#include <check/check.h>

Suite *TSuiteBasDbg(void)
{
    Suite *tsuite = suite_create("BasDbg");
    suite_add_tcase(tsuite, TCaseDbgPrt());
    return tsuite;
}
