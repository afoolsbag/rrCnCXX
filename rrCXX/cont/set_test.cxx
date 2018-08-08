//===-- Set -----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gSet 集合
/// \ingroup gCont
///
/// \sa ["std::set"](https://zh.cppreference.com/w/cpp/container/set). *cppreference.com*.
///
/// \version 2018-08-07
/// \since 2018-06-21
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <set>

#include <gtest/gtest.h>

#include "rrCXX/ver.hxx"

namespace rrcxx {

/// @addtogroup gSet
/// @{

/// \brief 集合的查找。
/// \details 时间复杂度 \f$ \mathcal{O}(\log size) \f$。
TEST(set, lookup)
{
    const std::set<int> numSet {9, 5, 2, 7};

    // count
    ASSERT_TRUE(numSet.count(5));
    ASSERT_FALSE(numSet.count(6));

    // find
    ASSERT_TRUE(numSet.find(5) != numSet.cend());
    ASSERT_FALSE(numSet.find(6) != numSet.cend());

    // contains
#if CXX20
    ASSERT_TRUE(numSet.contains(5));
    ASSERT_FALSE(numSet.contains(6));
#endif
}

/// @}

}//namespace rrcxx
