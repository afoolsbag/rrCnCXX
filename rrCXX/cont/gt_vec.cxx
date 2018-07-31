//===-- Vector --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVec 向量
/// \ingroup gCont
///
/// \sa ["std::vector"](https://zh.cppreference.com/w/cpp/container/vector). *cppreference.com*.
///
/// \version 2018-07-31
/// \since 2018-01-22
/// \author zhengrr
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <vector>

#include <gtest/gtest.h>

#include "rrcxx/ver.hxx"

///
/// \brief 向量的遍历
///
TEST(vector, traverse)
{
    const std::vector<int> nums {9, 5, 2, 7};
    int sum {};

#if N2930

    for (auto num : nums)
        sum += num;

#elif CXX11

    for (auto it = nums.cbegin(); it != nums.cend(); it++)
        sum += *it;

#else

    for (std::size_t idx = 0; idx < nums.size(); idx++)
        sum += nums[idx];

#endif

    GTEST_ASSERT_EQ(sum, 23);
}

/// @}
