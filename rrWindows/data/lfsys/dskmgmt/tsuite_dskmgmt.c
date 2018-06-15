#include "tsuite_dskmgmt.h"

#include <check/check.h>

Suite *TSuiteDskMgmt(void)
{
    Suite *tsuite = suite_create("DskMgmt");
    suite_add_tcase(tsuite, TCaseDskFS());
    suite_add_tcase(tsuite, TCaseFlrFS());
    return tsuite;
}
