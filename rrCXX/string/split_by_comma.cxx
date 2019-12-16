/// \copyright Unlicense

#include <array>
#include <sstream>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {

TEST(split_by_comma, float)
{
    constexpr char text[] {"1, 2, 3, 4, 5, 6, 7, 8, 9"};
    constexpr array<float, 9> expected {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<float> actual;

    stringstream ss {text};
    string tmp;
    while (getline(ss, tmp, ','))
        actual.push_back(stof(tmp));

    ASSERT_EQ(expected.size(), actual.size());
    for (size_t i = 0; i < expected.size(); ++i)
        ASSERT_FLOAT_EQ(expected[i], actual[i]);
}

}
