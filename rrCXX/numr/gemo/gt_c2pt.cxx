/// \copyright The MIT License

#include <gtest/gtest.h>

#include "rrcxx/gemo/c2pt.hxx"
using namespace rrcxx::geom::c2;

TEST(C2Point, Comparison)
{
    ASSERT_EQ(Point<>(0, 0), Point<>::ORIGIN);
    ASSERT_NE(Point<>(-1, -1), Point<>(1, 1));
}

TEST(C2Point, area)
{
    ASSERT_EQ(Point<>(0, 0).area(), Area::ORIGIN);
    ASSERT_EQ(Point<>(1, 0).area(), Area::POSITIVE_X_AXIS);
    ASSERT_EQ(Point<>(1, 1).area(), Area::QUADRANT_I);
    ASSERT_EQ(Point<>(0, 1).area(), Area::POSITIVE_Y_AXIS);
    ASSERT_EQ(Point<>(-1, 1).area(), Area::QUADRANT_II);
    ASSERT_EQ(Point<>(-1, 0).area(), Area::NEGATIVE_X_AXIS);
    ASSERT_EQ(Point<>(-1, -1).area(), Area::QUADRANT_III);
    ASSERT_EQ(Point<>(0, -1).area(), Area::NEGATIVE_Y_AXIS);
    ASSERT_EQ(Point<>(1, -1).area(), Area::QUADRANT_IV);
}
