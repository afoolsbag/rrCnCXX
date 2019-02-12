//===-- P.1 -----------------------------------------------------*- C++ -*-===//
///
/// \defgroup gP1 在代码中直接表达你的想法
/// \ingroup gAlgorithm
///
/// \version 2019-01-24
/// \since 2018-06-21
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <vector>
#include <gsl/gsl>

#include <gtest/gtest.h>

using namespace std;
using namespace gsl;

namespace rrcxx {

/// \addtogroup gP1
/// @{

TEST(p1, find)
{
    const vector<int> val {1,2,3,4,5};
    const int tgt {3};

    // 不太好
    index t = -1;
    for (index i = 0; i < static_cast<index>(val.size()); ++i) {
        if (val[static_cast<size_t>(i)] == tgt) {
            t = i;
            break;
        }
    }
    ASSERT_EQ(val[static_cast<size_t>(t)], tgt);

    // 好
    auto const p {find(begin(val), end(val), tgt)};
    ASSERT_EQ(*p, tgt);
}

/// @}

}//namespace rrcxx
