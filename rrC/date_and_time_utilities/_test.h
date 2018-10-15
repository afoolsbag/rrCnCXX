#pragma once
#ifndef RRC_TIME_TEST_H_
#define RRC_TIME_TEST_H_

#include <check/check.h>

TCase *tcase_caltm(void);
TCase *tcase_clktm(void);
TCase *tcase_epotm(void);
TCase *tcase_spectm(void);

inline Suite *tsuite_time(void)
{
    Suite *tsuite = suite_create("time");
    suite_add_tcase(tsuite, tcase_caltm());
    suite_add_tcase(tsuite, tcase_clktm());
    suite_add_tcase(tsuite, tcase_epotm());
    suite_add_tcase(tsuite, tcase_spectm());
    return tsuite;
}

#endif/*RRC_TIME_TEST_H_*/
