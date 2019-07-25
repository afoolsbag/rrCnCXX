//===-- Common Vocabulary Types ---------------------------------*- C++ -*-===//
///
/// \defgroup gCommonVocabularyTypes 通用词汇类型
/// \ingroup gUtility
///
/// \version 2019-02-28
/// \since 2018-10-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cfloat>
#include <climits>
#include <any>
#include <optional>
#include <tuple>
#include <variant>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;

namespace rrcxx {
/// \addtogroup gCommonVocabularyTypes
/// @{

/// \brief 任意包装器。
/// \sa <https://zh.cppreference.com/w/cpp/utility/any>
TEST(common_vocabulary_types, any)
{
#if FEATURE_P0220R1
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
#if FEATURE_P0220R1
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
    constexpr auto get_two_zero = []() -> tuple<int, double> {
        return make_tuple(INT_MAX, DBL_MAX);
    };

    // C++98
    {
        const auto tup = get_two_zero();
        [[maybe_unused]] const auto int_var = get<0>(tup);
        [[maybe_unused]] const auto dbl_var = get<1>(tup);
    }

    // C++11
    {
        int int_var;
        double dbl_var;
        tie(int_var, dbl_var) = get_two_zero();
    }

#if FEATURE_P0217R3
    // C++17
    {
        [[maybe_unused]] const auto[int_var, dbl_var] = get_two_zero();
    }
#endif
}

/// \brief 变体包装器。
///
/// \note
/// *   `union` - 使用 `variant`（C++17 提供）
/// *   强制转换 - 尽可能减少其使用；使用模板有助于这点
/// *   数组衰退 - 使用 `span`（来自 GSL）
/// *   范围错误 - 使用 `span`
/// *   窄化转换 - 尽可能减少其使用，必须使用时则使用 `narrow` 或者 `narrow_cast`（来自 GSL）
///
/// \remarks P.4: 理想情况下，程序应当是静态类型安全的
///
/// \sa <https://zh.cppreference.com/w/cpp/utility/variant>
TEST(common_vocabulary_types, variant)
{
#if FEATURE_P0088R3
    variant<int, double> variant {};

    variant = 1;
    [[maybe_unused]] const auto as_int = get<int>(variant);

    variant = 0.0;
    [[maybe_unused]] const auto as_double = get<double>(variant);

    try {
        [[maybe_unused]] const auto failed = get<int>(variant);
    } catch (const bad_variant_access &) {
        SUCCEED();
    }
#endif
}

/// @}
}
