//===-- rrlxtest ------------------------------------------------*- C++ -*-===//
///
/// \version 2019-07-18
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>

#include "rrlc/rrlc.h"
#include "rrlx/rrlx.h"

using namespace std;

TEST(rrlc, version)
{
    ASSERT_EQ(rrlc_success, rrlc_get_version(nullptr, nullptr, nullptr, nullptr));
}

TEST(rrlx, version)
{
    ASSERT_EQ(rrlx_success, rrlx_get_version(nullptr, nullptr, nullptr, nullptr));
}
