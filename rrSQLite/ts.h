/**
 * \copyright Unlicense
 */

#pragma once
#ifndef RRSQLITE_TS_H_
#define RRSQLITE_TS_H_

#include <check.h>

TCase *tc_database(void);
TCase *tc_table(void);
TCase *tc_row(void);

inline Suite *ts(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_database());
    suite_add_tcase(ts, tc_table());
    suite_add_tcase(ts, tc_row());
    return ts;
}

#endif/*RRSQLITE_TS_H_*/
