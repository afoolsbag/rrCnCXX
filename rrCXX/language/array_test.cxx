//===-- Array Type ----------------------------------------------*- C++ -*-===//
///
/// \defgroup gArray 数组类型
/// \ingroup gLanguage
///
/// \version 2018-11-27
/// \since 2018-10-08
/// \author zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4514 4571 4623 4625 4626 4668 4710 4774 4820 5026 5027)

#include <array>
#include <gsl/gsl>

#include <gtest/gtest.h>

#pragma warning(pop)

using namespace std;
using namespace gsl;

namespace rrcxx {

/// \addtogroup gArray
/// @{

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
    for (index i {0}; i < static_cast<index>(std_array.size()); ++i) {
        ASSERT_EQ(std_array[static_cast<size_t>(i)], i + 1);     // 不进行边界检查，不安全。
        ASSERT_EQ(std_array.at(static_cast<size_t>(i)), i + 1);  // 进行边界检查，安全。
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

    const auto count {[](const not_null<czstring<>> &str) -> index {
        return static_cast<index>(strlen(str));
    }};
    ASSERT_EQ(count(not_null {string}), 12);
}

/// @}

}//namespace rrcxx
