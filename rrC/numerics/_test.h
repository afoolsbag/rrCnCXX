#pragma once
#ifndef RRC_NUMR_TEST_H_
#define RRC_NUMR_TEST_H_

#include <check/check.h>

TCase *tcase_prn(void);
TCase *tcase_rnd(void);

inline Suite *tsuite_numr(void)
{
    Suite *tsuite = suite_create("numr");
    suite_add_tcase(tsuite, tcase_prn());
    suite_add_tcase(tsuite, tcase_rnd());
    return tsuite;
}

#endif/*RRC_NUMR_TEST_H_*/
