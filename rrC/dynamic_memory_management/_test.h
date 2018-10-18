#pragma once
#ifndef RRC_DYNAMIC_MEMORY_MANAGEMENT_TEST_H_
#define RRC_DYNAMIC_MEMORY_MANAGEMENT_TEST_H_

#include <check/check.h>

TCase *tc_dynamic_memory_management(void);

inline Suite *ts_dynamic_memory_management(void)
{
    Suite *const ts = suite_create("dynamic_memory_management");
    suite_add_tcase(ts, tc_dynamic_memory_management());
    return ts;
}

#endif/*RRC_DYNAMIC_MEMORY_MANAGEMENT_TEST_H_*/
