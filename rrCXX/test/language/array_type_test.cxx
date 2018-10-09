//===-- Array Type ----------------------------------------------*- C++ -*-===//
///
/// \defgroup gArr 数组类型
/// \ingroup gLang
///
/// \version 2018-10-08
/// \since 2018-10-08
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstddef>
#include <gsl/gsl>

#include <gtest/gtest.h>

namespace rrcxx::test {

/// \addtogroup gArr
/// @{

/// \brief 范围视图。
/// \details `gsl::span` 不持所有权。
TEST(array, gsl_span)
{
    static constexpr std::byte bytes[] {static_cast<std::byte>(0b00000000), static_cast<std::byte>(0b11110000), static_cast<std::byte>(0b00001111)};

    const auto count {[](const gsl::span<const std::byte> bytes) -> gsl::index {
        return bytes.size();
    }};
    ASSERT_EQ(count(bytes), 3);
}

/// \brief C 风格字符串视图。
/// \details `gsl::zstring` 不持所有权。
TEST(array, gsl_zstring)
{
    static constexpr char string[] {"666"};

    const auto count {[](gsl::not_null<gsl::czstring<>> string)->gsl::index {
        return std::strlen(string);
    }};
    ASSERT_EQ(count(gsl::not_null(string)), 3);
}

/// @}

}//namespace rrcxx::test
