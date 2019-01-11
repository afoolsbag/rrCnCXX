//===-- DLL -----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief DLL
/// \sa <https://www.boost.org/doc/libs/1_69_0/doc/html/boost_dll.html>
///
/// \version 2019-01-11
/// \since 2018-01-10
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/dll.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(dll, program_location)
{
    const auto program_path {boost::dll::program_location()};
}

}//namespace rrboost
