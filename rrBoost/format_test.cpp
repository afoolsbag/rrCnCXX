//===-- Boost.Format --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Boost.Format
/// \details The format library provides a type-safe mechanism for formatting arguments according to a printf-like format-string.
///
/// \sa <https://boost.org/doc/libs/master/libs/format/>
///
/// \version 2019-12-31
/// \since 2019-01-11
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <boost/format.hpp>
#include <gtest/gtest.h>

using namespace std;
using boost::format;

namespace rrboost {

/// \brief 旧式 `%spec` 风格
/// \details 与 `std::printf` 兼容
/// \sa <https://zh.cppreference.com/w/cpp/io/c/fprintf>
/// \sa <https://zh.cppreference.com/w/c/io/fprintf>
TEST(format, legacy_printf_style)
{
    cout << format("%5s, %-5s\n") % "hello" % "world";
}

/// \brief 竖线 `%|spec|` 风格
/// \details 相较于旧式风格，竖线风格不需要指定参数类型
TEST(format, pipe_style)
{
    cout << format("%|5|, %|-5|\n") % "hello" % "world";
}

/// \brief 位置 `%N%` 风格
/// \details 位置风格可以任意调换、重复使用参数，但没有格式化选项
TEST(format, position_style)
{
    cout << format("%2%, %1%\n") % "world" % "hello";

    // 旧式和竖线风格也可以指定位置
    cout << format("%2$5s, %1$-5s\n") % "world" % "hello";
    cout << format("%|2$5|, %|1$-5|\n") % "world" % "hello";
}

}
