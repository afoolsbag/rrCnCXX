//===-- Vector --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVec 向量
/// \ingroup gCont
///
/// \sa ["std::vector"](https://zh.cppreference.com/w/cpp/container/vector). *cppreference.com*.
///
/// \version 2018-09-18
/// \since 2018-01-22
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <vector>
#include <gsl/gsl>

#include <gtest/gtest.h>
#include "rrcxx/cxx_versions.hxx"

namespace rrcxx::test {

/// @addtogroup gVec
/// @{

/// \brief 向量的遍历
TEST(vector, traverse)
{
    const std::vector<int> numbers {9, 5, 2, 7};

#if N2930
    int sum1 {};
    for (const auto &number : numbers)
        sum1 += number;
    ASSERT_EQ(sum1, 23);
#endif

    int sum2 {};
    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it)
        sum2 += *it;
    ASSERT_EQ(sum2, 23);

    int sum3 {};
    for (gsl::index i {}; i < numbers.size(); ++i)
        sum3 += numbers[i];
    ASSERT_EQ(sum3, 23);
}

/// @}

}//namespace rrcxx::test
