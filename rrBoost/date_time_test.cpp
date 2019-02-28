//===-- Date Time -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Date Time
/// \sa <https://boost.org/doc/libs/1_69_0/doc/html/date_time.html>
///
/// \version 2019-02-26
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

namespace posix_time = boost::posix_time;

namespace rrboost {

TEST(date_time, posix_time)
{
    {
        const auto pt {posix_time::second_clock::local_time()};
        cout << "lcl=" << to_iso_extended_string(pt) << "\n";
    }

    {
        const auto tt = time(nullptr);
        const auto pt {posix_time::from_time_t(tt)};
        cout << "utc=" << to_iso_extended_string(pt) << "\n";
    }
}

}//namespace rrboost
