/// \copyright The MIT License

#include <gtest/gtest.h>
#include "rrCXX/numr/gemo/c2/ApRect.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

TEST(AxisParallelRectangle, Comparison)
{
    ASSERT_EQ(AxisParallelRectangle<>(-1, 1, -1, 1), AxisParallelRectangle<>(1, -1, 1, -1));
    ASSERT_NE(AxisParallelRectangle<>(0, 0, 0, 0), AxisParallelRectangle<>(1, 1, 1, 1));
}

TEST(AxisParallelRectangle, Intersected)
{
    ASSERT_TRUE(Intersected(LineSegment<>(2, 1, 0.5, -0.5), AxisParallelRectangle<>(-1, 1, -1, 1)));
}

}//namespace c2
}//namespace geom
}//namespace rrcxx
