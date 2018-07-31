/// \copyright The MIT License

#include <gtest/gtest.h>

#include "rrcxx/gemo/c2lineseg.hxx"
using namespace rrcxx::geom::c2;
#include "rrcxx/gemo/nl1inr.hxx"
using namespace rrcxx::geom::nl1;

TEST(C2LineSegment, Comparison)
{
    ASSERT_EQ(LineSegment<>(1, 1, 2, 2), LineSegment<>(2, 2, 1, 1));
    ASSERT_NE(LineSegment<>(-1, 0, 0, 0), LineSegment<>(0, -1, 0, 1));
}

TEST(C2LineSegment, projection)
{
    ASSERT_EQ(LineSegment<>(0, 0, 1, 1).xProjection(), Interval<>(0, 1, Interval<>::Type::CLOSE));
    ASSERT_EQ(LineSegment<>(0, 0, 1, 1).yProjection(), Interval<>(0, 1, Interval<>::Type::CLOSE));
}

TEST(C2LineSegment, C2Vector)
{
    ASSERT_EQ(LineSegment<>(BoundVector<>(1, 1, 1, 1)), LineSegment<>(1, 1, 2, 2));
    ASSERT_EQ(BoundVector<>(LineSegment<>(1, 1, 2, 2)), BoundVector<>(1, 1, 1, 1));
}

TEST(C2LineSegment, Intersected)
{
    ASSERT_TRUE(Intersected(Point<>(1, 3), LineSegment<>(0, 4, 4, 0)));
    ASSERT_TRUE(Intersected(LineSegment<>(0, 4, 4, 0), Point<>(3, 1)));

    ASSERT_TRUE(Intersected(LineSegment<>(0, 0, 4, 4), LineSegment<>(0, 4, 4, 0)));
    ASSERT_FALSE(Intersected(LineSegment<>(0, 0, 1, 1), LineSegment<>(0, 4, 4, 0)));
}
