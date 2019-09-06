//===-- Thread --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Thread
/// \sa <https://boost.org/doc/libs/master/libs/uuid/doc/index.html>
///
/// \version 2019-01-11
/// \since 2019-01-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/thread/thread.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(thread, sleep_for)
{
    boost::this_thread::sleep_for(boost::chrono::milliseconds(10));
}

}//namespace rrboost
