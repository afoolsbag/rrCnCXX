#pragma once
#ifndef TS_ISSUE5_H_
#define TS_ISSUE5_H_

#include <check.h>

TCase *tc_pthread(void);

static inline Suite *ts_issue5(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_pthread());
    return ts;
}

#endif/*TS_ISSUE5_H_*/
