#include "tsuite_fmgmt.h"

#include <check/check.h>

Suite *TSuiteFMgmt(void)
{
    Suite *tsuite = suite_create("FMgmt");
    suite_add_tcase(tsuite, TCaseFAttr());
    suite_add_tcase(tsuite, TCaseTravFlr());
    return tsuite;
}
