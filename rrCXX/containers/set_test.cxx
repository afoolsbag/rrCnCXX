//===-- Set -----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gSet 集合
/// \ingroup gContainers
///
/// \sa ["std::set"](https://zh.cppreference.com/w/cpp/container/set). *cppreference.com*.
///
/// \version 2018-11-27
/// \since 2018-06-21
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4514 4571 4623 4625 4626 4668 4710 4774 4820 5026 5027)

#include <set>

#include <gtest/gtest.h>

#pragma warning(pop)

#include "cxx_versions.hxx"

using namespace std;

namespace rrcxx {

/// \addtogroup gSet
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

}//namespace rrcxx
