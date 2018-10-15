#pragma once
#ifndef RRC_STRINGS_TEST_H_
#define RRC_STRINGS_TEST_H_

#include <check/check.h>

extern TCase *tc_byte_strings_conversion(void);
extern TCase *tc_byte_strings_examination(void);
extern TCase *tc_byte_strings_manipulation(void);

inline Suite *ts_strings(void)
{
    Suite *const ts = suite_create("strings");
    suite_add_tcase(ts, tc_byte_strings_conversion());
    suite_add_tcase(ts, tc_byte_strings_examination());
    suite_add_tcase(ts, tc_byte_strings_manipulation());
    return ts;
}

#endif/*RRC_STRINGS_TEST_H_*/
