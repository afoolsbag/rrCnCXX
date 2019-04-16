#pragma once
#ifndef RRZOOKEEPER_TS_H_
#define RRZOOKEEPER_TS_H_

#include <check.h>

static const char host[] = "172.16.0.122:2181";
static const int timeout = 10 * 1000 /*ms*/;

TCase *tc_async_crud(void);
TCase *tc_eph_seq(void);
TCase *tc_sync_crud(void);
TCase *tc_watch(void);

static inline Suite *ts(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_async_crud());
    suite_add_tcase(ts, tc_eph_seq());
    suite_add_tcase(ts, tc_sync_crud());
    suite_add_tcase(ts, tc_watch());
    return ts;
}

#endif/*RRZOOKEEPER_TS_H_*/
