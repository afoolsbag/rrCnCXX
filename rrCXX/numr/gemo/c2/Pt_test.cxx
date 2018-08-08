/// \copyright The MIT License

#include <gtest/gtest.h>
#include "rrCXX/numr/gemo/geom.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

TEST(Point, Comparison)
{
    ASSERT_EQ(Point(), Point::ORIGIN);
    ASSERT_NE(Point(-1, -1), Point(1, 1));
}

TEST(Point, area)
{
    ASSERT_EQ(Point(0, 0).area(), Area::ORIGIN);
    ASSERT_EQ(Point(1, 0).area(), Area::POSITIVE_X_AXIS);
    ASSERT_EQ(Point(1, 1).area(), Area::QUADRANT_I);
    ASSERT_EQ(Point(0, 1).area(), Area::POSITIVE_Y_AXIS);
    ASSERT_EQ(Point(-1, 1).area(), Area::QUADRANT_II);
    ASSERT_EQ(Point(-1, 0).area(), Area::NEGATIVE_X_AXIS);
    ASSERT_EQ(Point(-1, -1).area(), Area::QUADRANT_III);
    ASSERT_EQ(Point(0, -1).area(), Area::NEGATIVE_Y_AXIS);
    ASSERT_EQ(Point(1, -1).area(), Area::QUADRANT_IV);
}

}//namespace c2
}//namespace geom
}//namespace rrcxx
