/// \copyright The MIT License

#include <gtest/gtest.h>

#include "rrcxx/geom.hxx"

TEST(C2Point, ToPlaneArea)
{
    using namespace rrcxx::geom::c2;

    ASSERT_EQ(PlaneArea(Point<>(0, 0)), PlaneArea::ORIGIN);
    ASSERT_EQ(PlaneArea(Point<>(1, 0)), PlaneArea::POSITIVE_X_AXIS);
    ASSERT_EQ(PlaneArea(Point<>(1, 1)), PlaneArea::QUADRANT_I);
    ASSERT_EQ(PlaneArea(Point<>(0, 1)), PlaneArea::POSITIVE_Y_AXIS);
    ASSERT_EQ(PlaneArea(Point<>(-1, 1)), PlaneArea::QUADRANT_II);
    ASSERT_EQ(PlaneArea(Point<>(-1, 0)), PlaneArea::NEGATIVE_X_AXIS);
    ASSERT_EQ(PlaneArea(Point<>(-1, -1)), PlaneArea::QUADRANT_III);
    ASSERT_EQ(PlaneArea(Point<>(0, -1)), PlaneArea::NEGATIVE_Y_AXIS);
    ASSERT_EQ(PlaneArea(Point<>(1, -1)), PlaneArea::QUADRANT_IV);

    //LineSegment<double> ls1054(Point<double>(1, 0), Point<double>(5, 4));
    //LineSegment<double> ls0145(Point<double>(0, 1), Point<double>(4, 5));
    //ASSERT_FALSE(Intersected(ls1054, ls0145));

    //LineSegment<double> ls1011(Point<double>(1, 0), Point<double>(1, 1));
    //LineSegment<double> ls0121(Point<double>(0, 1), Point<double>(2, 1));
    //ASSERT_TRUE(Intersected(ls1011, ls0121));
}
