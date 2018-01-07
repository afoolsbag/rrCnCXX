/** \file
 *  \brief 枚举。
 *  \sa <http://en.cppreference.com/w/cpp/language/enum>
 *  \author zhengrr
 *  \date 2017-12-27 – 28
 *  \copyright The MIT License */

#include <gtest/gtest.h>

TEST(enumeration, unscoped_enumeration)
{
    enum RgbPrimaryColor {
        kRed, kGreen, kBlue
    } blue = kBlue;

    SUCCEED();
}

TEST(enumeration, scoped_enumerations)
{
    enum class RgbPrimaryColor {
        kRed, kGreen, kBlue
    } blue = RgbPrimaryColor::kBlue;

    SUCCEED();
}
