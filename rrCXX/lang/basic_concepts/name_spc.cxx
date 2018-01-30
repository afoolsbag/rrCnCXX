/**
 * \file
 * \brief 命名空间
 * \sa ["Namespaces (命名空间)"](http://en.cppreference.com/w/cpp/language/namespace). *cppreference.com*.
 * \sa ["Namespace aliases (命名空间别名)"](http://en.cppreference.com/w/cpp/language/namespace_alias). *cppreference.com*.
 * \sa \ref p_cpp_lang
 * \author zhengrr
 * \date 2016-11-1 – 2018-1-24
 * \copyright The MIT License
 */

#include <gtest/gtest.h>

#include "cxx_std_ver.hxx"

#if CXX_N2535

/* 应用：提供默认版本。
 *
 * 参见：<https://stackoverflow.com/questions/11016220> */

namespace {

// 内联命名空间
namespace lib {

inline namespace ver67 {
int ver() { return 67; }
}

namespace ver66 {
int ver() { return 66; }
}

namespace ver65 {
int ver() { return 65; }
}

}// namespace lib

}// namespace

/// GoogleTest name_spc preliminary
TEST(name_spc, preliminary) {
  EXPECT_EQ(lib::ver(), 67);
  EXPECT_EQ(lib::ver67::ver(), 67);
  EXPECT_EQ(lib::ver66::ver(), 66);
  EXPECT_EQ(lib::ver65::ver(), 65);
}

#endif// CXX_N2535
