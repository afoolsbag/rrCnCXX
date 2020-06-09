//===-- rrxtest -------------------------------------------------*- C++ -*-===//
///
/// \version 2020-06-03
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>

#include "rrc/rrc.h"
#include "rrx/rrx.h"

using namespace std;

TEST(rrc, version)
{
    ASSERT_EQ(rrc_success, rrc_get_version(nullptr, nullptr, nullptr, nullptr));
}

TEST(rrx, version)
{
    ASSERT_EQ(rrx_success, rrx_get_version(nullptr, nullptr, nullptr, nullptr));
}
