//===-- Operator Overloading -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gOperators 运算符重载
/// \ingroup gLanguage
///
/// \version 2019-03-01
/// \since 2019-03-01
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cmath>
#include <gsl/gsl>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;
using namespace gsl;

namespace rrcxx {

/// \addtogroupg Operators
/// @{

/// \brief 用户定义字面量
///
/// \remarks P.1: 在代码中直接表达你的想法
///
/// \sa <https://zh.cppreference.com/w/cpp/language/user_literal>
/// \sa [*C++C.G. P.1*](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rp-direct)
namespace {
#if STANDARD_CXX11 || NORMALIZED_MSC_VERSION
struct length_t { long double scalar; };
struct time_t { long double scalar; };
struct speed_t { long double scalar; };

constexpr length_t operator"" _m(unsigned long long m) { return length_t {narrow_cast<long double>(m)}; }
constexpr length_t operator"" _m(long double m) { return length_t {m}; }
constexpr time_t operator"" _s(unsigned long long s) { return time_t {narrow_cast<long double>(s)}; }
constexpr time_t operator"" _s(long double s) { return time_t {s}; }

constexpr speed_t operator/(length_t length, time_t time) { if (time.scalar == 0) return speed_t {HUGE_VALL}; return speed_t {length.scalar / time.scalar}; }

TEST(operators, user_literal)
{
    // 不好
    const auto change_speed_1 = [](long double s) -> void { (void)s; };
    change_speed_1(5);

    // 好
    const auto change_speed_2 = [](speed_t s) -> void { (void)s; };
    change_speed_2(5_m / 1_s);
}

#endif
}

/// @}

}
