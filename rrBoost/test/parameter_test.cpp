//===-- Parameter -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Parameter
/// \sa <https://www.boost.org/doc/libs/1_69_0/libs/parameter/doc/html/index.html>
///
/// \version 2019-07-10
/// \since 2019-01-11
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <boost/format.hpp>
#include <boost/parameter.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

#pragma warning(push)
#pragma warning(disable: 4003)

BOOST_PARAMETER_NAME(rp)
BOOST_PARAMETER_NAME(op1)
BOOST_PARAMETER_NAME(op2)
BOOST_PARAMETER_NAME(op3)
BOOST_PARAMETER_FUNCTION((void), pf, tag, (required(rp, *)) (optional(op1, *, "")(op2, *, "")(op3, *, "")))
{
    cout << boost::format("rp=%1%, op1=%2%, op2=%3%, op3=%4%.\n") % rp % op1 % op2 % op3;
}

#pragma warning(pop)

TEST(parameter, great_first_step)
{
    pf("rp");
    pf(_rp = "_rp");
    pf("rp", _op3 = "_op3");
}

}
