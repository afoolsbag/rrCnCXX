#pragma once
#ifndef RRC_ALGO_TEST_H_
#define RRC_ALGO_TEST_H_

#include <check/check.h>

extern TCase *tcase_bsrch(void);
extern TCase *tcase_qsort(void);

inline Suite *tsuite_algo(void)
{
    Suite *tsuite = suite_create("algo");
    suite_add_tcase(tsuite, tcase_bsrch());
    suite_add_tcase(tsuite, tcase_qsort());
    return tsuite;
}

#endif/*RRC_ALGO_TEST_H_*/
