//===-- Sorting Operations --------------------------------------*- C++ -*-===//
///
/// \defgroup gSortingOperations 排序操作
/// \ingroup gAlgorithm
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

#include "cxx_versions.hxx"

using namespace std;
using namespace gsl;

#if NORMALIZED_GNUC_VERSION
#define index gsl::index
#endif

namespace rrcxx {
/// \addtogroup gSortingOperations
/// @{

/// \brief 检查是否符合升序排列
TEST(sorting_operations, is_sorted)
{
    const vector<int> a1 {1, 2, 4, 8, 9};
    ASSERT_TRUE(is_sorted(a1.cbegin(), a1.cend()));

    const vector<int> a2 {7, 3, 2, 4, 9};
    ASSERT_FALSE(is_sorted(a2.cbegin(), a2.cend()));
}

/// @}
}
