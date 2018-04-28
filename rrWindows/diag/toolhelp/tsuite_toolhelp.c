#include "tsuite_toolhelp.h"

#include <check/check.h>

Suite *TSuiteToolHelp(void)
{
    Suite *tsuite = suite_create("ToolHelp");
    suite_add_tcase(tsuite, TCaseCkProcRun());
    return tsuite;
}
