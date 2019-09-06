//===-- Date Time -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Date Time
/// \sa <https://boost.org/doc/libs/master/doc/html/date_time.html>
///
/// \version 2019-07-10
/// \since 2019-02-25
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <string>

#include <boost/date_time.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(date_time, posix_time_local)
{
    const auto pt = boost::posix_time::second_clock::local_time();
    cout << "local time: " << to_iso_extended_string(pt) << '\n';
}

TEST(date_time, posix_time_utc)
{
    const auto ct = time(nullptr);
    const auto pt = boost::posix_time::from_time_t(ct);
    cout << "UTC time: " << to_iso_extended_string(pt) << '\n';
}

}
