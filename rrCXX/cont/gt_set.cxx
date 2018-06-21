//===-- Set -----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gSet 集合
/// \ingroup gCont
///
/// \sa ["std::set"](http://en.cppreference.com/w/cpp/container/set). *cppreference.com*.
///
/// \version 2018-06-21
/// \since 2018-06-21
/// \authors zhengrr
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <set>

#include <gtest/gtest.h>

#include "cxxver.hxx"

///
/// \brief 集合的查找。
/// \details 时间复杂度\f$\mathcal{O}(\log size)\f$。
///
TEST(Set, Lookup) {
  const std::set<int> numSet{9, 5, 2, 7};

  // count
  ASSERT_EQ(numSet.count(4), 0);
  ASSERT_EQ(numSet.count(5), 1);

  // find
  ASSERT_EQ(numSet.find(8), numSet.cend());
  ASSERT_NE(numSet.find(9), numSet.cend());

#if CXX20
  // contains
  ASSERT_FALSE(numSet.contains(6));
  ASSERT_TRUE(numSet.contains(7));
#endif
}

/// @}
