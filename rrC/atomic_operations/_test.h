#pragma once
#ifndef RRC_ATOMIC_OPERATIONS_TEST_H_
#define RRC_ATOMIC_OPERATIONS_TEST_H_

#include <check/check.h>

TCase *tc_atomic_operations(void);

inline Suite *ts_atomic_operations(void)
{
    Suite *const ts = suite_create("atomic_operations");
    suite_add_tcase(ts, tc_atomic_operations());
    return ts;
}

#endif/*RRC_ATOMIC_OPERATIONS_TEST_H_*/
