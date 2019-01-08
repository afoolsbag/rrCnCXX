//===-- Asio --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Asio
/// \sa <https://boost.org/doc/libs/1_69_0/doc/html/boost_asio.html>
///
/// \version 2019-01-08
/// \since 2019-01-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma warning(push)
#pragma warning(disable: 4996)

#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <gtest/gtest.h>

using namespace std;

#pragma warning(pop)

namespace rrboost::test {

TEST(asio, wait)
{
    boost::asio::io_context io;

    boost::asio::steady_timer timer(io, boost::asio::chrono::milliseconds(10));
    timer.wait();
}

TEST(asio, async_wait)
{
    const auto callback = [](const boost::system::error_code &/*e*/) {
        cout << "time out.\n";
    };

    boost::asio::io_context io;

    boost::asio::steady_timer timer(io, boost::asio::chrono::milliseconds(10));
    timer.async_wait(callback);

    io.run();
}

TEST(asio, async_wait_with_arg)
{
    const auto callback = [](const boost::system::error_code &/*e*/, const string &arg) -> void {
        cout << "time out with " << arg << ".\n";
    };

    boost::asio::io_context io;

    boost::asio::steady_timer timer(io, boost::asio::chrono::milliseconds(10));
    timer.async_wait(boost::bind<void>(callback, boost::asio::placeholders::error, "aoishigure"));

    io.run();
}

}//namespace rrboost::test
