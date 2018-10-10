//===-- Common Vocabulary Types ---------------------------------*- C++ -*-===//
///
/// \defgroup gCmnVocTypes 通用词汇类型
/// \ingroup gGen
///
/// \sa "通用词汇类型". *cppreference.com*.
/// + [`std::variant`](https://zh.cppreference.com/w/cpp/utility/variant)
///
/// \version 2018-10-10
/// \since 2018-10-08
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <any>
#include <optional>
#include <tuple>
#include <variant>
using namespace std;

#include <gtest/gtest.h>
#include "rrcxx/cxx_versions.hxx"

namespace rrcxx::test {

/// \addtogroup gCmnVocTypes
/// @{

/// \brief 任意包装器。
TEST(common_vocabulary_types, any)
{
#if P0220R1
    any any;
    ASSERT_FALSE(any.has_value());

    any = 1;
    [[maybe_unused]] const auto cast_int {any_cast<int>(any)};
    ASSERT_THROW([[maybe_unused]] const auto failed {any_cast<double>(any)}, bad_any_cast);

    any.reset();
    ASSERT_FALSE(any.has_value());
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

    ASSERT_THROW([[maybe_unused]] const auto failed {get<int>(variant)}, bad_variant_access);
#endif
}

/// @}

}//namespace rrcxx::test
