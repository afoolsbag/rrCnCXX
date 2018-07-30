/// \copyright The MIT License

#include <gtest/gtest.h>

#include "rrcxx/nl1pt.hxx"
using namespace rrcxx::geom::nl1;

TEST(Nl1Point, area)
{
    ASSERT_EQ(Point<>().area(), Area::ORIGIN);
    ASSERT_EQ(Point<>(1).area(), Area::POSITIVE_AXIS);
    ASSERT_EQ(Point<>(-1).area(), Area::NEGATIVE_AXIS);
}

TEST(Nl1Point, Comparison)
{
    ASSERT_EQ(Point<>(0), Point<>(0));
    ASSERT_NE(Point<>(-1), Point<>(1));
    ASSERT_LT(Point<>(-1), Point<>(0));
    ASSERT_GE(Point<>(1), Point<>(0));
    ASSERT_GT(Point<>(1), Point<>(0));
    ASSERT_LE(Point<>(-1), Point<>(0));
}
