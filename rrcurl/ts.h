/**
 * \copyright Unlicense
 */

#pragma once
#ifndef TS_H_
#define TS_H_

#include <check.h>

TCase *tc(void);

static inline Suite *ts(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tc());
    return ts;
}

#endif/*TS_H_*/
