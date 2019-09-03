//===-- Stacktrace ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Stacktrace
/// \sa <https://boost.org/doc/libs/1_71_0/doc/html/stacktrace.html>
///
/// \version 2019-09-03
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

namespace bst = boost::stacktrace;

namespace rrboost {

TEST(stacktrace, gft)
{
    cout << bst::stacktrace {};
}

}
