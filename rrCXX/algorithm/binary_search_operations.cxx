//===-- Binary Search Operations --------------------------------*- C++ -*-===//
///
/// \defgroup gBinarySearchOperations 二分搜索操作
/// \ingroup gAlgorithm
///
/// \brief 二分搜索，边界下沿和上沿
/// \details 边界下沿：在升序排列中，找到首个大于等于指定值的元素\n
///          边界上沿：在升序排列中，找到首个大于指定值的元素
///
/// \version 2019-08-01
/// \since 2019-08-01
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <vector>
#include <gsl/gsl>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {
/// \addtogroup gBinarySearchOperations
/// @{

/// \brief 边界存在于序列
TEST(binary_search_operations, lower_upper_bound_eq)
{
    const vector<int> vec {3, 5, 5, 5, 7, /*end*/};
    const auto it_3 = vec.cbegin() + 0;
    const auto it_5_1 = vec.cbegin() + 1;
    const auto it_5_2 = vec.cbegin() + 2;
    const auto it_5_3 = vec.cbegin() + 3;
    const auto it_7 = vec.cbegin() + 4;
    ASSERT_TRUE(is_sorted(vec.cbegin(), vec.cend()));

    const auto it_lower = lower_bound(vec.cbegin(), vec.cend(), 5);
    ASSERT_EQ(it_5_1, it_lower);

    const auto it_upper = upper_bound(vec.cbegin(), vec.cend(), 5);
    ASSERT_EQ(it_7, it_upper);
}

/// \brief 边界不存在于序列
TEST(binary_search_operations, lower_upper_bound_ne)
{
    const vector<int> vec {3, 7, /*end*/};
    const auto it_3 = vec.cbegin() + 0;
    const auto it_7 = vec.cbegin() + 1;
    ASSERT_TRUE(is_sorted(vec.cbegin(), vec.cend()));

    const auto it_lower = lower_bound(vec.cbegin(), vec.cend(), 5);
    ASSERT_EQ(it_7, it_lower);

    const auto it_upper = upper_bound(vec.cbegin(), vec.cend(), 5);
    ASSERT_EQ(it_7, it_upper);
}

/// @}
}
