#include "tsuite_wnet.h"

#include <check/check.h>

Suite *TSuiteWNet(void)
{
    Suite *tsuite = suite_create("WNet");
    suite_add_tcase(tsuite, TCaseAcsShrFlr());
    return tsuite;
}
