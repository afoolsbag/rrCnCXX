//===-- Stacktrace ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Stacktrace
/// \sa <https://boost.org/doc/libs/1_69_0/doc/html/stacktrace.html>
///
/// \version 2019-07-22
/// \since 2019-03-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <csignal>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/stacktrace.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace stacktrace = boost::stacktrace;

namespace rrboost {

TEST(stacktrace, getting_started)
{
    cout << stacktrace::stacktrace {};
}

}//namespace rrboost
