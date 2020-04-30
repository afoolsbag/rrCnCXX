//===-- rrexex --------------------------------------------------*- C++ -*-===//
///
/// \version 2020-04-30
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>

#include "rrlibc/rrlibc.h"
#include "rrlibx/rrlibx.h"

using namespace std;

TEST(rrlibc, version)
{
    ASSERT_EQ(rrlibc_success, rrlibc_get_version(nullptr, nullptr, nullptr, nullptr));
}

TEST(rrlibx, version)
{
    ASSERT_EQ(rrlibx_success, rrlibx_get_version(nullptr, nullptr, nullptr, nullptr));
}
