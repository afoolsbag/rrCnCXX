#pragma once
#ifndef TS_ISSUE6_H_
#define TS_ISSUE6_H_

#include <check.h>

TCase *tc_sys_socket(void);

static inline Suite *ts_issue6(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_sys_socket());
    return ts;
}

#endif/*TS_ISSUE6_H_*/
