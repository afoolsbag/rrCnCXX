#pragma once
#ifndef RRC_INPUT_OUTPUT_SUPPORT_TEST_H_
#define RRC_INPUT_OUTPUT_SUPPORT_TEST_H_

#include <check/check.h>

TCase *tc_file_access(void);

inline Suite *ts_input_output_support(void)
{
    Suite *const ts = suite_create("input_output_support");
    suite_add_tcase(ts, tc_file_access());
    return ts;
}

#endif/*RRC_INPUT_OUTPUT_SUPPORT_TEST_H_*/
