//===-- Array Type ----------------------------------------------*- C++ -*-===//
///
/// \defgroup gArr 数组类型
/// \ingroup gLang
///
/// \version 2018-10-10
/// \since 2018-10-08
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <array>
using namespace std;
#include <gsl/gsl>
using namespace gsl;

#include <gtest/gtest.h>

namespace rrcxx::test {

/// \addtogroup gArr
/// @{

namespace {
}//namespace

/// \brief 原始数组。
/// \remarks ES.107: 不要对下标使用 `unsigned`，优先使用 `gsl::index`
TEST(array, raw_array)
{
    static constexpr int raw_array[] {1, 2, 3, 4, 5, 6};
    for (index i {0}; i < 6; ++i) {
        ASSERT_EQ(raw_array[i], i + 1);      // 不进行边界检查，不安全。
        ASSERT_EQ(at(raw_array, i), i + 1);  // 进行边界检查，安全。
    }
    for (const auto &e : raw_array)
        ASSERT_GE(e, 0);
}

/// \brief 容器数组。
/// \remarks ES.107: 不要对下标使用 `unsigned`，优先使用 `gsl::index`
TEST(array, std_array)
{
    static constexpr array<const int, 6> std_array {1, 2, 3, 4, 5, 6};
    for (index i {0}; i < std_array.size(); ++i) {
        ASSERT_EQ(std_array[i], i + 1);     // 不进行边界检查，不安全。
        ASSERT_EQ(std_array.at(i), i + 1);  // 进行边界检查，安全。
    }
    for (const auto &e : std_array)
        ASSERT_GE(e, 0);
}

/// \brief 范围视图。
TEST(array, gsl_span)
{
    {
        static constexpr int raw_array[] {1, 2, 3, 4, 5, 6};
        static constexpr span raw_array_span {raw_array};
        for (index i {0}; i < raw_array_span.size(); ++i) {
            ASSERT_EQ(raw_array_span[i], i + 1);     // 进行边界检查，安全。
            ASSERT_EQ(raw_array_span.at(i), i + 1);  // 进行边界检查，安全。
        }
        for (const auto &e : raw_array_span)
            ASSERT_GE(e, 0);
    }

    {
        static constexpr array<const int, 6> std_array {1, 2, 3, 4, 5, 6};
        static const span<const int> std_array_span {std_array};
        for (index i {0}; i < std_array_span.size(); ++i) {
            ASSERT_EQ(std_array_span[i], i + 1);     // 进行边界检查，安全。
            ASSERT_EQ(std_array_span.at(i), i + 1);  // 进行边界检查，安全。
        }
        for (const auto &e : std_array_span)
            ASSERT_GE(e, 0);
    }
}

/// \brief C 风格字符串。
TEST(array, gsl_zstring)
{
    static constexpr char string[] {"hello, world"};

    const auto count {[](not_null<czstring<>> str)->index {
        return strlen(str);
    }};
    ASSERT_EQ(count(not_null {string}), 12);
}

/// @}

}//namespace rrcxx::test
