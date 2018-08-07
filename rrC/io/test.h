#pragma once
#ifndef RRC_IO_TEST_H_
#define RRC_IO_TEST_H_

#include <check/check.h>

TCase *tcase_facs(void);

inline Suite *tsuite_io(void)
{
    Suite *ste = suite_create("io");
    suite_add_tcase(ste, tcase_facs());
    return ste;
}

#endif/*RRC_IO_TEST_H_*/
