#pragma once
#ifndef RRC_LANGUAGE_TEST_H_
#define RRC_LANGUAGE_TEST_H_

#include <check/check.h>

extern TCase *tc_array(void);
extern TCase *tc_character(void);
extern TCase *tc_structure(void);

inline Suite *ts_language(void)
{
    Suite *const ts = suite_create("language");
    suite_add_tcase(ts, tc_array());
    suite_add_tcase(ts, tc_character());
    suite_add_tcase(ts, tc_structure());
    return ts;
}

#endif/*RRC_LANGUAGE_TEST_H_*/
