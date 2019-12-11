#include <iostream>

#include <gtest/gtest.h>

using namespace std;

namespace {

template<typename T = string>
struct type {
    T data {};
    T &ref = data;

    type() = default;

    // explicit type(const type &) = default;
    type(const type &other)
    {
        data = other.data;
    }

    // explicit type(type &&) noexcept = default;
    type(type &&other) noexcept
    {
        data = move(other.data);
    }

    virtual ~type() noexcept = default;

    // type &operator=(const type &) = default;
    type &operator=(const type &other)
    {
        if (&other != this)
            data = other.data;
        return *this;
    }

    // type &operator=(type &&) noexcept = default;
    type &operator=(type &&other) noexcept
    {
        if (&other != this)
            data = move(other.data);
        return *this;
    }
};
}

namespace rrcxx {
/// \addtogroup gClasses
/// @{

TEST(classes, field_ref)
{
    type x;
    x.data = "field of y";
    type y = x;
    x.data = "field of x";

    ASSERT_STREQ(x.data.c_str(), "field of x");
    ASSERT_STREQ(x.ref.c_str(), "field of x");
    ASSERT_STREQ(y.data.c_str(), "field of y");
    ASSERT_STREQ(y.ref.c_str(), "field of y");
}

/// @}
}
