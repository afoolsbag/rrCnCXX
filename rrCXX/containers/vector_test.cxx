//===-- Vector --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVector 向量
/// \ingroup gContainers
///
/// \sa ["std::vector"](https://zh.cppreference.com/w/cpp/container/vector). *cppreference.com*.
///
/// \version 2018-11-22
/// \since 2018-01-22
/// \authors zhengrr
/// \copyright Unlicense
//===----------------------------------------------------------------------===//

#include <vector>
#include <gsl/gsl>

#include <gtest/gtest.h>

#include "cxx_versions.hxx"

using namespace std;
using namespace gsl;

namespace rrcxx {

/// \addtogroup gVector
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

}//namespace rrcxx
