#include "tsuite_rpc.h"

#include <check/check.h>

Suite *TSuiteRPC(void)
{
    Suite *tsuite = suite_create("RPC");
    suite_add_tcase(tsuite, TCaseGenUuid());
    return tsuite;
}
