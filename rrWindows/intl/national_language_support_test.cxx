/// \copyright Unlicense

#include <gtest/gtest.h>

#include "rrwindows/rrwindows.hxx"

namespace rrwindows {

constexpr char str1[] = "1234567";
constexpr char str2[] = "1234567";

TEST(national_language_support, compare_string_invariant)
{
    ASSERT_EQ(0, compare_string_invariant(str1, str2));
}

TEST(national_language_support, compare_string_system_default)
{
    ASSERT_EQ(0, compare_string_system_default(str1, str2));
}

TEST(national_language_support, compare_string_user_default)
{
    ASSERT_EQ(0, compare_string_user_default(str1, str2));
}

}
