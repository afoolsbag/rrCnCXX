#pragma once
#ifndef RRSQLITE_TEST_H_
#define RRSQLITE_TEST_H_

#include <check/check.h>

TCase *tc_database(void);
TCase *tc_table(void);
TCase *tc_row(void);

inline Suite *ts_test(void)
{
    Suite *const ts = suite_create("test");
    suite_add_tcase(ts, tc_database());
    suite_add_tcase(ts, tc_table());
    suite_add_tcase(ts, tc_row());
    return ts;
}

#endif/*RRSQLITE_TEST_H_*/
