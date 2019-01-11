//===-- Log -----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Log
///
/// \sa [Boost.Log使用文档](http://www.wanguanglu.com/2016/07/28/boost-log-document/)
/// \sa <https://boost.org/doc/libs/1_69_0/libs/log/doc/html/index.html>
///
/// \version 2019-01-11
/// \since 2019-01-11
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

//#include <boost/log/core.hpp>
//#include <boost/log/expressions.hpp>
#include <boost/dll.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <gtest/gtest.h>

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
    namespace log = boost::log;
    const auto base_name {boost::dll::program_location().filename().stem().string()};

    const auto &file_sink = log::add_file_log(
        log::keywords::file_name = "log/" + base_name + "_%Y-%m-%d_%N.log",
        log::keywords::max_files = 256,
        log::keywords::min_free_space = 100 * 1024 * 1024,
        log::keywords::open_mode = std::ios::out | std::ios::app,
        log::keywords::rotation_size = 5 * 1024 * 1024,
        log::keywords::time_based_rotation = log::sinks::file::rotation_at_time_point(0, 0, 0)
    );

    BOOST_LOG_TRIVIAL(trace) << "trace message";
    BOOST_LOG_TRIVIAL(debug) << "debug message";
    BOOST_LOG_TRIVIAL(info) << "info message";
    BOOST_LOG_TRIVIAL(warning) << "warning message";
    BOOST_LOG_TRIVIAL(error) << "error message";
    BOOST_LOG_TRIVIAL(fatal) << "fatal message";

    log::core::get()->remove_sink(file_sink);
}

TEST(log, filter)
{
    namespace log = boost::log;

    const auto &console_sink = log::add_console_log();

    // 全局过滤器
    log::core::get()->set_filter(
        log::trivial::debug <= log::trivial::severity
    );

    // 槽过滤器
    console_sink->set_filter(
        log::trivial::info <= log::trivial::severity
    );

    BOOST_LOG_TRIVIAL(trace) << "trace message";
    BOOST_LOG_TRIVIAL(debug) << "debug message";
    BOOST_LOG_TRIVIAL(info) << "info message";
    BOOST_LOG_TRIVIAL(warning) << "warning message";
    BOOST_LOG_TRIVIAL(error) << "error message";
    BOOST_LOG_TRIVIAL(fatal) << "fatal message";

    log::core::get()->remove_sink(console_sink);
}

}//namespace rrboost
