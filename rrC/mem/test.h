#pragma once
#ifndef RRC_MEM_TEST_H_
#define RRC_MEM_TEST_H_

#include <check/check.h>

TCase *tcase_mem(void);

inline Suite *tsuite_mem(void)
{
    Suite *tsuite = suite_create("mem");
    suite_add_tcase(tsuite, tcase_mem());
    return tsuite;
}

#endif/*RRC_MEM_TEST_H_*/
