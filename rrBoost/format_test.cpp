//===-- Format --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Format
/// \sa <https://boost.org/doc/libs/master/libs/format/index.html>
///
/// \version 2019-07-10
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

TEST(format, gfs)
{
    cout << boost::format("Hello, %1%.\n") % "Aoi";
}

}
