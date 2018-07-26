/// \copyright The MIT License

#include <gtest/gtest.h>

#include "rrcxx/geom.hxx"

using namespace rrcxx::geom::c2;

TEST(Geom, LineSegment_LineSegment_Intersected)
{
    LineSegment<double> ls1054(Point<double>(1, 0), Point<double>(5, 4));
    LineSegment<double> ls0145(Point<double>(0, 1), Point<double>(4, 5));
    ASSERT_FALSE(Intersected(ls1054, ls0145));

    LineSegment<double> ls1011(Point<double>(1, 0), Point<double>(1, 1));
    LineSegment<double> ls0121(Point<double>(0, 1), Point<double>(2, 1));
    ASSERT_TRUE(Intersected(ls1011, ls0121));
}
