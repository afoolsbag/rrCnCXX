#include <iostream>

#include <gtest/gtest.h>

using namespace std;

namespace {

template<typename T = string>
struct type {
    T data {"null"};
    static const type<T> nullval;
};

template<typename T>
const type<T> type<T>::nullval {};

}

namespace rrcxx {
/// \addtogroup gClasses
/// @{

TEST(classes, field_nullval)
{
    ASSERT_STREQ("null", type<>::nullval.data.c_str());
}

/// @}
}
