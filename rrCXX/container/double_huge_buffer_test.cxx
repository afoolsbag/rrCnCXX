/// \copyright Unlicense

#include <cstdint>

#include <gtest/gtest.h>

#include "double_huge_buffer.hxx"

using namespace std;

namespace rrcxx {

TEST(double_huge_buffer, test)
{
    double_huge_buffer::double_huge_buffer buffer {50};
    auto &&wref = buffer.get_reference_for_write_buffer();
    ASSERT_EQ(50, wref.item_max_count);
}

}
