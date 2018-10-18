#pragma once
#ifndef RRC_ALGORITHMS_TEST_H_
#define RRC_ALGORITHMS_TEST_H_

#include <check/check.h>

TCase *tc_algorithms(void);

inline Suite *ts_algorithms(void)
{
    Suite *const ts = suite_create("algorithms");
    suite_add_tcase(ts, tc_algorithms());
    return ts;
}

#endif/*RRC_ALGORITHMS_TEST_H_*/
