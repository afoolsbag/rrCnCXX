/**
 * \file
 * \brief 枚举
 * \sa ["Type"](http://en.cppreference.com/w/cpp/language/type). *cppreference.com*.
 * \sa ["enumeration declaration"](http://en.cppreference.com/w/cpp/language/enum). *cppreference.com*.
 * \author zhengrr
 * \date 2017-12-27 – 2018-1-22
 * \copyright The MIT License
 */

namespace {

enum RgbPrimaryColor {
  kRed, kGreen, kBlue
};// enum RgbPrimaryColor

enum class CmykPrimaryColor {
  kCyan, kMagenta, kYellow, kKey, kBlack = static_cast<int>(kKey)
};// enum class CmykPrimaryColor

}// namespace

int main() {
  RgbPrimaryColor red = kRed;

  CmykPrimaryColor cyan = CmykPrimaryColor::kCyan;
}
