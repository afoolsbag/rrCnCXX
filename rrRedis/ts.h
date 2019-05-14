/**
 * \copyright Unlicense
 */

#pragma once
#ifndef RRREDIS_TS_H_
#define RRREDIS_TS_H_

#ifdef __unix__

#endif
#ifdef _WIN32
#include <WinSock2.h>
#endif

#include <check.h>

static const char host_address[] = "127.0.0.1";
static const int host_port = 6379;
static const struct timeval timeout = {1, 500 * 000};

TCase *tc(void);
TCase *tc_key(void);
TCase *tc_string(void);
TCase *tc_list(void);
TCase *tc_hash(void);

static inline Suite *ts(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc());
    suite_add_tcase(ts, tc_key());
    suite_add_tcase(ts, tc_string());
    suite_add_tcase(ts, tc_list());
    suite_add_tcase(ts, tc_hash());
    return ts;
}

#endif/*RRREDIS_TS_H_*/
