/** \file
 *  \brief 内联命名空间。
 *  \sa <http://en.cppreference.com/w/cpp/language/namespace>
 *  \author zhengrr
 *  \date 2016-11-1 – 2017-12-27
 *  \copyright The MIT License */

#include <gtest/gtest.h>

#include "cxx_standard_version.hpp"

#if CXXN2535

/* 应用：提供默认版本。
 *
 * 参见：<https://stackoverflow.com/questions/11016220> */

namespace {

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

TEST(inline_namespace, inline_namespace)
{
    EXPECT_EQ(lib::version(), 67);
}

#endif// CXXN2535
