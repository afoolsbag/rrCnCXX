#pragma once

#include <check/check.h>

TCase *tcConsoleVirtualTerminalSequences(void);

inline Suite *tsConsole(void)
{
    Suite *const ts = suite_create("Console");
    suite_add_tcase(ts, tcConsoleVirtualTerminalSequences());
    return ts;
}
