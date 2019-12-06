//===-- Thread --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Thread
/// \sa <https://boost.org/doc/libs/master/libs/uuid/>
///
/// \version 2019-12-05
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

}
