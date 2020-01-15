//===-- Boost.Process -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Boost.Process
/// \details Library to create processes in a portable way.
///
/// \sa <https://boost.org/doc/libs/master/libs/process/>
///
/// \version 2020-01-15
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

namespace rrboost {

TEST(process, named_pipe)
{
#if 0
    namespace ba = boost::asio;
    namespace bp = boost::process;
    namespace bs = boost::system;

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

TEST(process, system)
{
    const auto ffmpeg_path = boost::process::search_path("ffmpeg");
    if (ffmpeg_path.empty())
        FAIL() << "The FFmpeg program not found.";

    boost::process::ipstream ips; // input pipe stream
    const int rc = boost::process::system(
        ffmpeg_path,
        "--help", "param2", "param3", "param...",
        boost::process::std_in < boost::process::null,
        boost::process::std_out > boost::process::null,
        boost::process::std_err > ips);

    string text, line;
    while (std::getline(ips, line) && !line.empty())
        text += line.append("\r\n");

    if (rc != EXIT_SUCCESS)
        FAIL() << text;
}

}
