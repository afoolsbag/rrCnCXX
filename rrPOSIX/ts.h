#pragma once
#ifndef RRPOSIX_TS_H_
#define RRPOSIX_TS_H_

#include <check.h>

TCase *tc_berkeley_sockets(void);
TCase *tc_posix_threads(void);

static inline Suite *ts_all(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc_berkeley_sockets());
    suite_add_tcase(ts, tc_posix_threads());
    return ts;
}

#endif/*RRPOSIX_TS_H_*/
