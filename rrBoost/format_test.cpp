//===-- Format --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Format
/// \sa <https://boost.org/doc/libs/1_69_0/libs/format/index.html>
///
/// \version 2019-01-11
/// \since 2019-01-11
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <boost/format.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(format, first_step)
{
    using boost::format;

    cout << format("Hello, %1%.\n") % "Aoi";
}

}//namespace rrboost
