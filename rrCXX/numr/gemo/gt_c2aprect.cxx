/// \copyright The MIT License

#include <gtest/gtest.h>

#include "rrcxx/gemo/c2aprect.hxx"
using namespace rrcxx::geom::c2;

TEST(C2AxisParallelRectangle, Comparison)
{
    ASSERT_EQ(AxisParallelRectangle<>(-1, 1, -1, 1), AxisParallelRectangle<>(1, -1, 1, -1));
    ASSERT_NE(AxisParallelRectangle<>(0, 0, 0, 0), AxisParallelRectangle<>(1, 1, 1, 1));
}

TEST(C2AxisParallelRectangle, Intersected)
{
    ASSERT_TRUE(Intersected(LineSegment<>(2, 1, 0.5, -0.5), AxisParallelRectangle<>(-1, 1, -1, 1)));
}
