#pragma once
#ifndef RRC_DATE_AND_TIME_UTILITIES_TEST_H_
#define RRC_DATE_AND_TIME_UTILITIES_TEST_H_

#include <check/check.h>

extern TCase *tc_date_and_time_utilities(void);

inline Suite *ts_date_and_time_utilities(void)
{
    Suite *const ts = suite_create("date_and_time_utilities");
    suite_add_tcase(ts, tc_date_and_time_utilities());
    return ts;
}

#endif/*RRC_DATE_AND_TIME_UTILITIES_TEST_H_*/
