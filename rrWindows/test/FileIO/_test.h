#pragma once

#include <check/check.h>

TCase *tcDirectoryManagement(void);

inline Suite *tsFileIO(void)
{
    Suite *const ts = suite_create("FileIO");
    suite_add_tcase(ts, tcDirectoryManagement());
    return ts;
}
