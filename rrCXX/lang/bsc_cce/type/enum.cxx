/**
 * \file
 * \brief 枚举
 * \sa ["Type (类型)"](http://en.cppreference.com/w/cpp/language/type). *cppreference.com*.
 * \sa ["enumeration declaration (枚举声明)"](http://en.cppreference.com/w/cpp/language/enum). *cppreference.com*.
 * \author zhengrr
 * \date 2017-12-27 – 2018-1-24
 * \copyright The MIT License
 */

#include <gtest/gtest.h>

namespace {

enum RgbPrimaryColor {
  kRed, kGreen, kBlue
};// enum RgbPrimaryColor

enum struct CmykPrimaryColor {
  kCyan, kMagenta, kYellow, kKey, kBlack = static_cast<int>(kKey)
};// enum struct CmykPrimaryColor

}// namespace

TEST(enumeration, preliminary) {

  RgbPrimaryColor red = kRed;

  CmykPrimaryColor cyan = CmykPrimaryColor::kCyan;

  GTEST_ASSERT_EQ(red, kRed);
  GTEST_ASSERT_EQ(cyan, CmykPrimaryColor::kCyan);
}
