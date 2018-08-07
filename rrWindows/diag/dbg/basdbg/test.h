#pragma once

#include <check/check.h>

TCase *TCaseDbgPrt(void);

Suite *TSuiteBasDbg(void)
{
    Suite *tsuite = suite_create("BasDbg");
    suite_add_tcase(tsuite, TCaseDbgPrt());
    return tsuite;
}
