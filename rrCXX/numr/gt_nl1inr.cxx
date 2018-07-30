/// \copyright The MIT License

#include <gtest/gtest.h>

#include "rrcxx/nl1inr.hxx"
using namespace rrcxx::geom::nl1;

TEST(Nl1Interval, diameter)
{
    ASSERT_EQ(Interval<>(-1, 1, Interval<>::Type::CLOSE).diameter(), 2);
}
