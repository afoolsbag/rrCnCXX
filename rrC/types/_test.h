#pragma once
#ifndef RRC_TYPE_SUPPORT_TEST_H_
#define RRC_TYPE_SUPPORT_TEST_H_

#include <check/check.h>

inline Suite *ts_type_support(void)
{
    Suite *const ts = suite_create("type_support");
    return ts;
}

#endif/*RRC_TYPE_SUPPORT_TEST_H_*/
