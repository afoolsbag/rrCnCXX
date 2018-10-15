#pragma once
#ifndef RRC_ATOM_TEST_H_
#define RRC_ATOM_TEST_H_

#include <check/check.h>

TCase *tcase_atom(void);

inline Suite *tsuite_atom(void)
{
    Suite *tsuite = suite_create("atom");
    suite_add_tcase(tsuite, tcase_atom());
    return tsuite;
}

#endif/*RRC_ATOM_TEST_H_*/
