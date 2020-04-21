//===-- Locale --------------------------------------------------*- C++ -*-===//
///
/// \version 2020-04-21
/// \since 2020-04-21
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {
/// \addtogroupg groupLocale
/// @{

TEST(locale, print_locale)
{
    cout << "locale: " << locale {}.name() << '\n';
}

/// @}
}
