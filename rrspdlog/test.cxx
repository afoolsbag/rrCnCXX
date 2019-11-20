/// \copyright Unlicense

#include <filesystem>

#include <boost/dll.hpp>
#include <gtest/gtest.h>

#include "rrspdlog/rrspdlog.hxx"

using namespace std;

namespace rrspdlog {

/// \brief 样例。
TEST(sample, wow)
{
    try {
         initialize_as_default(boost::dll::program_location().replace_extension("logs").string());
    } catch (const exception &e) {
        FAIL() << "initialize_as_default failed: " << e.what();
    }

    SPDLOG_TRACE("trace message");
    SPDLOG_DEBUG("debug message");
    SPDLOG_INFO("info message");
    SPDLOG_WARN("warn message");
    SPDLOG_ERROR("error message");
    SPDLOG_CRITICAL("critical message");
}

}
