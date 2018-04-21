//===-- Namespaces ----------------------------------------------*- C++ -*-===//
///
/// \defgroup g_namesp 命名空间
/// \ingroup g_lang
///
/// \sa ["Namespaces"](http://en.cppreference.com/w/cpp/language/namespace). *cppreference.com*.
/// \sa ["Namespace aliases"](http://en.cppreference.com/w/cpp/language/namespace_alias). *cppreference.com*.
///
/// \author zhengrr
/// \date 2016-11-1 – 2018-2-2
/// \copyright The MIT License
///
/// @{
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

#include "cxxstdver.hxx"

#if N2535
namespace {
namespace lib {
inline namespace ver67 { int ver() { return 67; }}
namespace ver66 { int ver() { return 66; }}
namespace ver65 { int ver() { return 65; }}
}// namespace lib
}// namespace
#endif// N2535

/// \brief 内联命名空间
/// \details 可用于指定默认版本。
/// \since C++11
/// \sa ["What are inline namespaces for?"](https://stackoverflow.com/questions/11016220). *Stack Overflow*.
TEST(namesp, inline_namespace) {
#if N2535
  EXPECT_EQ(lib::ver(), 67);
  EXPECT_EQ(lib::ver67::ver(), 67);
  EXPECT_EQ(lib::ver66::ver(), 66);
  EXPECT_EQ(lib::ver65::ver(), 65);
#endif// N2535
}



/// @}
