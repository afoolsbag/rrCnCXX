//===-- rrExeX --------------------------------------------------*- C++ -*-===//
///
/// \version 2019-06-20
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

TEST(rrLibC, version)
{
    ASSERT_EQ(rrlibc_success, rrlibc_get_version(nullptr, nullptr, nullptr, nullptr));
}

TEST(rrLibX, version)
{
    ASSERT_EQ(rrlibx_success, rrlibx_get_version(nullptr, nullptr, nullptr, nullptr));
}