/// \copyright Unlicense

#include <sstream>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {

TEST(split_by_comma, float)
{
    constexpr char raw_data[] {"1, 2, 3, 4, 5, 6, 7, 8, 9"};
    constexpr float expected[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const auto expected_size {sizeof(expected) / sizeof(*expected)};

    stringstream ss {raw_data};

    float actual[expected_size];
    float tmp;
    for (size_t i = 0; ss >> tmp; ++i) {
        actual[i] = tmp;
        for (auto c = ss.peek(); c == ' ' || c == ','; c = ss.peek())
            ss.ignore();
    }

    for (size_t i = 0; i < expected_size; ++i)
        ASSERT_EQ(expected[i], actual[i]);
}

}
