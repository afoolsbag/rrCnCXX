//===-- Thread --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Thread
/// \sa <https://boost.org/doc/libs/1_68_0/libs/uuid/doc/index.html>
///
/// \version 2019-01-10
/// \since 2019-01-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/thread/thread.hpp>
#include <gtest/gtest.h>

namespace rrboost {

TEST(thread, sleep_for)
{
    boost::this_thread::sleep_for(boost::chrono::seconds(1));
}

}//namespace rrboost
