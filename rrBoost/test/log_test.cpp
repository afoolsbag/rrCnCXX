//===-- Log -----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Log
///
/// \sa [Boost.Log使用文档](http://www.wanguanglu.com/2016/07/28/boost-log-document/)
/// \sa <https://boost.org/doc/libs/master/libs/log/doc/html/index.html>
///
/// \version 2019-07-10
/// \since 2019-01-11
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <boost/dll.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <gtest/gtest.h>

using namespace std;

namespace rrboost {

TEST(log, trivial)
{
    BOOST_LOG_TRIVIAL(trace) << "trace message";
    BOOST_LOG_TRIVIAL(debug) << "debug message";
    BOOST_LOG_TRIVIAL(info) << "info message";
    BOOST_LOG_TRIVIAL(warning) << "warning message";
    BOOST_LOG_TRIVIAL(error) << "error message";
    BOOST_LOG_TRIVIAL(fatal) << "fatal message";
}

TEST(log, file_sink)
{
    const auto log_path = boost::dll::program_location().replace_extension(".log") / "%Y-%m-%d_%N.log";

    const auto &file_sink = boost::log::add_file_log(
        boost::log::keywords::file_name = log_path,
        boost::log::keywords::max_files = 256,
        boost::log::keywords::min_free_space = 100 * 1024 * 1024,
        boost::log::keywords::open_mode = ios::out | ios::app,
        boost::log::keywords::rotation_size = 5 * 1024 * 1024,
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0));

    BOOST_LOG_TRIVIAL(trace) << "trace message";
    BOOST_LOG_TRIVIAL(debug) << "debug message";
    BOOST_LOG_TRIVIAL(info) << "info message";
    BOOST_LOG_TRIVIAL(warning) << "warning message";
    BOOST_LOG_TRIVIAL(error) << "error message";
    BOOST_LOG_TRIVIAL(fatal) << "fatal message";

    boost::log::core::get()->remove_sink(file_sink);
}

TEST(log, filter)
{
    const auto &console_sink = boost::log::add_console_log();

    // 全局过滤器
    boost::log::core::get()->set_filter(
        boost::log::trivial::debug <= boost::log::trivial::severity
    );

    // 槽过滤器
    console_sink->set_filter(
        boost::log::trivial::info <= boost::log::trivial::severity
    );

    BOOST_LOG_TRIVIAL(trace) << "trace message";
    BOOST_LOG_TRIVIAL(debug) << "debug message";
    BOOST_LOG_TRIVIAL(info) << "info message";
    BOOST_LOG_TRIVIAL(warning) << "warning message";
    BOOST_LOG_TRIVIAL(error) << "error message";
    BOOST_LOG_TRIVIAL(fatal) << "fatal message";

    boost::log::core::get()->remove_sink(console_sink);
}

}
