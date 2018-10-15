#pragma once
#ifndef RRC_STR_TEST_H_
#define RRC_STR_TEST_H_

#include <check/check.h>

TCase *tcase_bstr_cnv(void);
TCase *tcase_bstr_exam(void);
TCase *tcase_bstr_man(void);

inline Suite *tsuite_str(void)
{
    Suite *tsuite = suite_create("str");
    suite_add_tcase(tsuite, tcase_bstr_cnv());
    suite_add_tcase(tsuite, tcase_bstr_exam());
    suite_add_tcase(tsuite, tcase_bstr_man());
    return tsuite;
}

#endif/*RRC_STR_TEST_H_*/
