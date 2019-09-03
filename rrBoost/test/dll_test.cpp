//===-- DLL -----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief DLL
/// \sa <https://boost.org/doc/libs/1_71_0/doc/html/boost_dll.html>
///
/// \version 2019-07-10
/// \since 2019-01-10
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
    const auto program_path = boost::dll::program_location();
}

}
