/// \copyright The MIT License

#include <gtest/gtest.h>
#include "rrCXX/numr/gemo/nl1/Inr.hxx"

namespace rrcxx {
namespace geom {
namespace nl1 {

TEST(Interval, diameter)
{
    ASSERT_EQ(Interval<>(-1, 1, Interval<>::Type::CLOSE).diameter(), 2);
}

}//namespace nl1
}//namespace geom
}//namespace rrcxx
