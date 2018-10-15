#pragma once
#ifndef RRC_NUMERICS_TEST_H_
#define RRC_NUMERICS_TEST_H_

#include <check/check.h>

extern TCase *tc_nearest_integer_floating_point_operations(void);
extern TCase *tc_pseudo_random_number(void);

inline Suite *ts_numerics(void)
{
    Suite *const ts = suite_create("numerics");
    suite_add_tcase(ts, tc_nearest_integer_floating_point_operations());
    suite_add_tcase(ts, tc_pseudo_random_number());
    return ts;
}

#endif/*RRC_NUMERICS_TEST_H_*/
