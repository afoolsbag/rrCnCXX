//===-- Common Vocabulary Types ---------------------------------*- C++ -*-===//
///
/// \defgroup gCommonVocabularyTypes 通用词汇类型
/// \ingroup gGeneralUtilities
///
/// \sa "通用词汇类型". *cppreference.com*.
///     *   [`std::variant`](https://zh.cppreference.com/w/cpp/utility/variant)
///
/// \version 2018-11-27
/// \since 2018-10-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4514 4571 4623 4625 4626 4668 4710 4774 4820 5026 5027)
#pragma warning(disable: 4582)

#include <any>
#include <optional>
#include <tuple>
#include <variant>

#include <gtest/gtest.h>

#pragma warning(pop)

#include "cxx_versions.hxx"

using namespace std;

namespace rrcxx {

/// \addtogroup gCommonVocabularyTypes
/// @{

/// \brief 任意包装器。
TEST(common_vocabulary_types, any)
{
#if P0220R1
    any any;
    ASSERT_FALSE(any.has_value());

    any = 1;
    [[maybe_unused]] const auto cast_int {any_cast<int>(any)};

    any.reset();
    ASSERT_FALSE(any.has_value());

    any = true;
    try {
        [[maybe_unused]] const auto failed {any_cast<double>(any)};
    } catch (const bad_any_cast &) {
        SUCCEED();
    }

#endif
}

/// \brief 可选包装器。
TEST(common_vocabulary_types, optional)
{
#if P0220R1
    const auto create {[](const bool notnull) -> optional<int> {
        if (notnull)
            return 666;
        else
            return nullopt;
    }};

    const auto notnull {create(true)};
    ASSERT_TRUE(notnull);
    ASSERT_EQ(*notnull, 666);

    const auto null {create(false)};
    ASSERT_FALSE(null);
#endif
}

/// \brief 元组包装器。
TEST(common_vocabulary_types, tuple)
{
    const auto get_two_zero {[]() -> tuple<int, double> {
        return make_tuple(0, 0.0);
    }};

    // C++98
    const auto cxx98 {get_two_zero()};
    [[maybe_unused]] const auto cxx98int {get<0>(cxx98)};
    [[maybe_unused]] const auto cxx98double {get<1>(cxx98)};

    // C++11
    int cxx11int;
    double cxx11double;
    tie(cxx11int, cxx11double) = get_two_zero();

#if P0217R3
    // C++17
    const auto [cxx17int, cxx17double] {get_two_zero()};
#endif
}

/// \brief 变体包装器。
TEST(common_vocabulary_types, variant)
{
#if P0088R3
    variant<int, double> variant {0};
    [[maybe_unused]] const auto as_int {get<int>(variant)};

    variant = 0.0;
    [[maybe_unused]] const auto as_double {get<double>(variant)};

    try {
        [[maybe_unused]] const auto failed {get<int>(variant)};
    } catch (const bad_variant_access &) {
        SUCCEED();
    }
#endif
}

/// @}

}//namespace rrcxx
