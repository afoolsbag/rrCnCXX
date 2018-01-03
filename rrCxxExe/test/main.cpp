#include "gtest/gtest.h"

#include <cmath>

#include <iostream>

double cubic(double d)
{
    return pow(d,3);
}

TEST(testMath, demo)
{
    EXPECT_EQ(10001, cubic(10));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
