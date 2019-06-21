//===-- Vector --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVector 向量
/// \ingroup gContainer
///
/// \sa ["std::vector"](https://zh.cppreference.com/w/cpp/container/vector). *cppreference.com*.
///
/// \version 2019-02-22
/// \since 2018-01-22
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

/// \addtogroup gVector
/// @{

/// \brief 向量的遍历
TEST(vector, traverse)
{
    const vector<int> v {9, 5, 2, 7};

    {
        int s {};
        for_each(cbegin(v), cend(v), [&](const int &x) {
            s += x;
        });
        ASSERT_EQ(s, 23);
    }

#if FEATURE_N2930
    {
        int s {};
        for (const auto &x : v)
            s += x;
        ASSERT_EQ(s, 23);
    }
#endif

    {
        int s {};
        for (auto it = cbegin(v); it != cend(v); ++it)
            s += *it;
        ASSERT_EQ(s, 23);
    }

    {
        int s {};
        for (index i {}; i < static_cast<index>(size(v)); ++i)
            s += v[static_cast<size_t>(i)];
        ASSERT_EQ(s, 23);
    }
}

/// @}

}
