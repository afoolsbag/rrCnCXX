//===-- Vector --------------------------------------------------*- C++ -*-===//
///
/// \defgroup g_vector 向量
/// \ingroup g_cont
///
/// \sa ["vector"](http://en.cppreference.com/w/cpp/container/vector). *cppreference.com*.
///
/// \author zhengrr
/// \date 2018-1-22 – 2-7
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <vector>

#include <gtest/gtest.h>

#include "cxxver.hxx"

/// \brief 向量的遍历
TEST(vector, traverse) {
  const std::vector<int> nums{9, 5, 2, 7};
  int sum{};

#if N2930
  for (auto num: nums)
    sum += num;
#elif CXX11
  for (auto it = nums.cbegin(); it != nums.cend(); it++)
    sum += *it;
#else// !CXX11
  for (std::size_t idx = 0; idx < nums.size(); idx++)
    sum += nums[idx];
#endif// N2930

  GTEST_ASSERT_EQ(sum, 23);
}

/// @}
