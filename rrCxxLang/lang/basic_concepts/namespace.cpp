/**
 * \file
 * \brief 命名空间
 * \sa <http://en.cppreference.com/w/cpp/language/namespace>
 * \author zhengrr
 * \date 2016-11-1 – 2018-1-22
 * \copyright The MIT License
 */

#include "cxx_std_ver.hpp"

#if CXX_N2535

/* 应用：提供默认版本。
 *
 * 参见：<https://stackoverflow.com/questions/11016220> */

namespace {

// 内联命名空间
namespace lib {

inline namespace ver67 {
int version() { return 67; }
}

namespace ver66 {
int version() { return 66; }
}

namespace ver65 {
int version() { return 66; }
}

}// namespace lib

}// namespace

TEST(inline_namespace, inline_namespace
)
{
EXPECT_EQ(lib::version(),
67);
}

#endif// CXXN2535
