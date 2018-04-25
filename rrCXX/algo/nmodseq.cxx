//===-- Non-Static Data Members ---------------------------------*- C++ -*-===//
///
/// \defgroup nmod_seq 不修改序列的操作
/// \ingroup g_algo
///
/// \sa ["Non-modifying sequence operations"](http://en.cppreference.com/w/cpp/algorithm#Non-modifying_sequence_operations). *cppreference.com*.
///
/// \author zhengrr
/// \date 2018-1-29 – 2-2
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <numeric>

#include <gtest/gtest.h>

#include "cxxver.hxx"

/// \brief all_of, any_of, none_of
/// \sa ["all_of, any_of, none_of"](http://en.cppreference.com/w/cpp/algorithm/all_any_none_of). *cppreference.com*.
TEST(nmod_seq, all_any_none_of) {
#if CXX11
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
#endif// CXX11
}

/// \brief for_each
/// \sa ["for_each"](http://en.cppreference.com/w/cpp/algorithm/for_each). *cppreference.com*.
TEST(nmod_seq, for_each) {}

/// \brief for_each_n
/// \sa ["for_each_n"](http://en.cppreference.com/w/cpp/algorithm/for_each_n). *cppreference.com*.
TEST(nmod_seq, for_each_n) {
#if CXX17
#endif// CXX17
}

/// \brief count, count_if
/// \sa ["for_each"](http://en.cppreference.com/w/cpp/algorithm/count). *cppreference.com*.
TEST(nmod_seq, count) {}

/// \brief mismatch
/// \sa ["mismatch"](http://en.cppreference.com/w/cpp/algorithm/mismatch). *cppreference.com*.
TEST(nmod_seq, mismatch) {}

/// \brief find, find_if, find_if_not
/// \sa ["find, find_if, find_if_not"](http://en.cppreference.com/w/cpp/algorithm/find). *cppreference.com*.
TEST(nmod_seq, find) {}

/// \brief find_end
/// \sa ["find_end"](http://en.cppreference.com/w/cpp/algorithm/find_end). *cppreference.com*.
TEST(nmod_seq, find_end) {}

/// \brief find_first_of
/// \sa ["find_first_of"](http://en.cppreference.com/w/cpp/algorithm/find_first_of). *cppreference.com*.
TEST(nmod_seq, find_first_of) {}

/// \brief adjacent_find
/// \sa ["adjacent_find"](http://en.cppreference.com/w/cpp/algorithm/adjacent_find). *cppreference.com*.
TEST(nmod_seq, adjacent_find) {}

/// \brief search
/// \sa ["search"](http://en.cppreference.com/w/cpp/algorithm/search). *cppreference.com*.
TEST(nmod_seq, search) {}

/// \brief search_n
/// \sa ["adjacent_find"](http://en.cppreference.com/w/cpp/algorithm/search_n). *cppreference.com*.
TEST(nmod_seq, search_n) {}

/** @} */
