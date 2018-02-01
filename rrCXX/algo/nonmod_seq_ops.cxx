/**
 * \defgroup g_nonmod_seq_ops 不修改序列的操作
 * \ingroup g_algos_lib
 *
 * \sa ["Non-modifying sequence operations (不修改序列的操作)"](http://en.cppreference.com/w/cpp/algorithm#Non-modifying_sequence_operations). *cppreference.com*.
 * \author zhengrr
 * \date 2018-1-29
 * \copyright The MIT License
 *
 * @{
 */

#include <algorithm>
#include <numeric>

#include <gtest/gtest.h>

#include "std.hxx"

#if CXX_STD_11
/**
 * \brief all_of, any_of, none_of
 * \sa ["all_of, any_of, none_of"](http://en.cppreference.com/w/cpp/algorithm/all_any_none_of)
 */
TEST(nonmod_seq_ops, all_any_none_of) {
  std::array<int, 10> ints{};
  std::iota(ints.begin(), ints.end(), 1);

  EXPECT_TRUE(
      std::all_of(ints.cbegin(), ints.cend(), [](int n) { return 0 < n; })
  );

  EXPECT_TRUE(
      std::any_of(ints.cbegin(), ints.cend(), [](int n) { return 5 < n; })
  );

  EXPECT_FALSE(
      std::none_of(ints.cbegin(), ints.cend(), [](int n) { return 5 < n; })
  );
}
#endif// CXX_STD_11

/** @} */
