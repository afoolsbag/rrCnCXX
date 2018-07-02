#include "tsuite_th.h"

#include <check/check.h>

Suite *TSuiteTH(void)
{
    Suite *tsuite = suite_create("ToolHelp");
    suite_add_tcase(tsuite, TCaseCntProc());
    return tsuite;
}
