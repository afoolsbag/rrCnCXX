/// \copyright Unlicense

#include <cstdint>

#include <gtest/gtest.h>

#include "double_buffer.hxx"

using namespace std;

namespace rrcxx {

TEST(double_huge_buffer, test)
{
    double_buffer::double_buffer buffer {50};
    auto &&write_token = buffer.get_write_token();
    ASSERT_EQ(50, write_token.item_max());
}

}
