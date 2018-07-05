//===-- GoogleTest Main Function --------------------------------*- C++ -*-===//
//!
//! \version 2018-07-05
//! \since 2018-07-05
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
