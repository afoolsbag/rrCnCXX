//===-- Array ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gArray 数组
/// \ingroup gLanguage
///
/// \sa [数组声明](https://zh.cppreference.com/w/cpp/language/array)
///
/// \version 2019-08-06
/// \since 2018-10-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <array>
#include <gsl/gsl>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;
using namespace gsl;

#if NORMALIZED_GNUC_VERSION
#define index gsl::index
#endif

namespace rrcxx {

/// \addtogroup gArray
/// @{

/// \brief 原始数组。
///
/// \remarks ES.107: 不要对下标使用 `unsigned`，优先使用 `gsl::index`
///
/// \sa <https://zh.cppreference.com/w/cpp/language/array>
/// \sa [*C++C.G. ES.107*](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-subscripts)
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
/// \remarks ES.107: 不要对下标使用 `unsigned`，优先使用 `gsl::gsl::index`
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

}
