#pragma once
#ifndef RRC_TYPE_TEST_H_
#define RRC_TYPE_TEST_H_

#include <check/check.h>

TCase *tcase_array(void);
TCase *tcase_char(void);
TCase *tcase_struct(void);

inline Suite *tsuite_type(void)
{
    Suite *tsuite = suite_create("type");
    suite_add_tcase(tsuite, tcase_array());
    suite_add_tcase(tsuite, tcase_char());
    suite_add_tcase(tsuite, tcase_struct());
    return tsuite;
}

#endif/*RRC_TYPE_TEST_H_*/
