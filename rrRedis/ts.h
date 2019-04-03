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

static const char host_addr[] = "127.0.0.1";
static const int host_port = 6379;
static const struct timeval timeout = {1, 500000};

TCase *tc(void);

static inline Suite *ts(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc());
    return ts;
}

#endif/*RRREDIS_TS_H_*/
