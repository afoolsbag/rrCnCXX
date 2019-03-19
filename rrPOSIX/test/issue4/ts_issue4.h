#pragma once
#ifndef TS_ISSUE4_H_
#define TS_ISSUE4_H_

#include <check.h>

TCase *tc_stropts(void);

static inline Suite *ts_issue4(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_stropts());
    return ts;
}

#endif/*TS_ISSUE4_H_*/
