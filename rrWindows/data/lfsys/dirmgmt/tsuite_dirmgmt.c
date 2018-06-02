#include "tsuite_dirmgmt.h"

#include <check/check.h>

Suite *TSuiteDirMgmt(void)
{
    Suite *tsuite = suite_create("DirMgmt");
    suite_add_tcase(tsuite, TCaseRmFlr());
    return tsuite;
}
