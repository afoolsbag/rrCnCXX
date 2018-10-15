//===-- Set -----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gSet 集合
/// \ingroup gCont
///
/// \sa ["std::set"](https://zh.cppreference.com/w/cpp/container/set). *cppreference.com*.
///
/// \version 2018-10-10
/// \since 2018-06-21
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <set>
using namespace std;

#include <gtest/gtest.h>
#include "rrcxx/cxx_versions.hxx"

namespace rrcxx::test {

/// @addtogroup gSet
/// @{

/// \brief 集合的查找。
/// \details 时间复杂度 \f$ \mathcal{O}(\log size) \f$。
TEST(set, lookup)
{
    const set<int> numbers {9, 5, 2, 7};

    // count
    ASSERT_TRUE(numbers.count(5));
    ASSERT_FALSE(numbers.count(6));

    // find
    ASSERT_TRUE(numbers.find(5) != numbers.cend());
    ASSERT_FALSE(numbers.find(6) != numbers.cend());

    // contains
#if CXX20
    ASSERT_TRUE(numSet.contains(5));
    ASSERT_FALSE(numSet.contains(6));
#endif
}

/// @}

}//namespace rrcxx::test
