/// \copyright The MIT License

#define _USE_MATH_DEFINES
#include <cmath>

#include <gtest/gtest.h>
#include "rrCXX/numr/gemo/geom.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

TEST(Vector, Comparison)
{
    ASSERT_EQ(Vector(0, 0), Vector::ZERO);
    ASSERT_NE(Vector::XUNIT, Vector::YUNIT);
}

TEST(Vector, opposite)
{
    ASSERT_EQ(Vector(1, 1).opposite(), Vector(-1, -1));
    ASSERT_EQ(-Vector(1, 1), Vector(-1, -1));
}

TEST(Vector, norm)
{
    ASSERT_EQ(Vector(3, 4).norm(), 5);
}

TEST(Vector, unit)
{
    ASSERT_EQ(Vector(5, 0).unit(), Vector::XUNIT);
}

TEST(Vector, perpendicular)
{
    ASSERT_EQ(Vector(1, 2).perpendicular(), Vector(-2, 1));
    ASSERT_EQ(Vector(1, 2).perpendicular(false), Vector(2, -1));

    ASSERT_EQ(Vector(1, 2).perpendicular(Vector(-1, 0)), Vector(-2, 1));
    ASSERT_EQ(Vector(1, 2).perpendicular(Vector(1, 0)), Vector(2, -1));
    ASSERT_EQ(Vector(1, 2).perpendicular(Vector(2, 4)), Vector::ZERO);
}

TEST(Vector, Point)
{
    ASSERT_EQ(Vector(Point(1, 1)), Vector(1, 1));
    ASSERT_EQ(Point(Vector(1, 1)), Point(1, 1));

    ASSERT_EQ(Point::ORIGIN + Vector(3, 3), Point(3, 3));
    ASSERT_EQ(Point::ORIGIN - Vector(3, 3), Point(-3, -3));
}

TEST(Vector, add)
{
    ASSERT_EQ(Vector(1, 3) + Vector(3, 1), Vector(4, 4));
}

TEST(Vector, subtract)
{
    ASSERT_EQ(Vector(1, 3) - Vector(3, 1), Vector(-2, 2));
}

TEST(Vector, DotProduct)
{
    ASSERT_EQ(DotProduct(Vector(1, 2), Vector(2, 1)), 4);
}

TEST(Vector, CrossProduct)
{
    ASSERT_EQ(CrossProduct(Vector(3, 0), Vector(0, 3)), 9);
}

TEST(Vector, ScalarMultiplication)
{
    ASSERT_EQ(3. * Vector(1, 1), Vector(3, 3));
    ASSERT_EQ(Vector(1, 1) * 3., Vector(3, 3));
}

TEST(Vector, IncludedAngle)
{
    ASSERT_EQ(IncludedAngle(Vector::XUNIT, Vector::YUNIT), M_PI_2);
}

}//namespace c2
}//namespace geom
}//namespace rrcxx
