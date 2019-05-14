//===-- Executable ----------------------------------------------*- C++ -*-===//
///
/// \version 2019-05-13
/// \since 2016-10-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>

#include "rrdllc/lib.h"
#include "rrdllx/rrdllx.hxx"

using namespace std;

TEST(rrdllc, version)
{
    rrdllc_version_t v {};
    ASSERT_TRUE(rrdllc_get_version(&v) == rrdllc_success);
}

TEST(rrdllx, version)
{
    ASSERT_NO_THROW(rrdllx::version());
}
