//===-- Vector --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVec 向量
/// \ingroup gCont
///
/// \sa ["std::vector"](https://zh.cppreference.com/w/cpp/container/vector). *cppreference.com*.
///
/// \version 2018-11-06
/// \since 2018-01-22
/// \author zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <vector>
using namespace std;
#include <gsl/gsl>
using namespace gsl;

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

namespace rrcxx::test {

/// @addtogroup gVec
/// @{

/// \brief 向量的遍历
TEST(vector, traverse)
{
    const vector<int> numbers {9, 5, 2, 7};

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
    for (index i {}; i < static_cast<index>(numbers.size()); ++i)
        sum3 += numbers[i];
    ASSERT_EQ(sum3, 23);
}

/// @}

}//namespace rrcxx::test
