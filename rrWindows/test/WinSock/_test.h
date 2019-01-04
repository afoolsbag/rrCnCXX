#pragma once

#include <check/check.h>

TCase *tcWindowsSockets2(void);

inline Suite *tsWinSock(void)
{
    Suite *const ts = suite_create("WinSock");
    suite_add_tcase(ts, tcWindowsSockets2());
    return ts;
}
