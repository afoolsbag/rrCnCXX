//===-- Process -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Process
/// \sa <https://boost.org/doc/libs/master/doc/html/process.html>
///
/// \version 2019-09-04
/// \since 2019-09-04
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <gsl/gsl>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4189 4244 4267 4996)
#endif
#include <boost/asio.hpp>
#include <boost/process.hpp>
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include <gtest/gtest.h>

using namespace std;
using namespace gsl;
namespace ba = boost::asio;
namespace bp = boost::process;
namespace bs = boost::system;

namespace rrboost {

TEST(process, named_pipe)
{
#if 0
    // BUG: https://github.com/boostorg/process/issues/83

    ba::io_service ios;
    bp::async_pipe ap {ios, R"(\\.\pipe\rrBoostTest)"};
    ASSERT_TRUE(ap.is_open());

    array<char, 256> buf {};
    ba::async_read(ap, ba::buffer(buf), [&](const bs::error_code &ec, size_t bytes_transferred) {
        (void)ec;
        (void)bytes_transferred;
        cout << &buf.front() << '\n';
    });
    ios.run_for(1min);
#endif
}

}
