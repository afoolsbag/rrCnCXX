/// \copyright Unlicense

#include <filesystem>
#include <memory>
#include <vector>

#include <boost/dll.hpp>
#include <gtest/gtest.h>

#include <spdlog/common.h>
#ifdef SPDLOG_ACTIVE_LEVEL
#undef SPDLOG_ACTIVE_LEVEL
#endif
#ifdef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
constexpr auto spdlog_pattern = R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%n] %^%l: %v%$)";
constexpr auto spdlog_level = spdlog::level::info;
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
constexpr auto spdlog_pattern = R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%@] %^%l: %v%$)";
constexpr auto spdlog_level = spdlog::level::trace;
#endif
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

using namespace std;

namespace rrspdlog {

static void initialize_rrspdlog_as_default()
{
    static const auto logs_dir_path = [] {
        const auto path = boost::dll::program_location().replace_extension(".logs");
        create_directory(path);
        return path;
    }();

    vector<spdlog::sink_ptr> sinks;

    const auto rotating_log_path = (logs_dir_path / "rotating.log").string();
    constexpr size_t ten_megabyte {10 * 1024 * 1024};
    const auto rotating_sink = make_shared<spdlog::sinks::rotating_file_sink_mt>(rotating_log_path, ten_megabyte, 10);
    rotating_sink->set_level(spdlog::level::trace);
    sinks.push_back(rotating_sink);

    const auto daily_log_path = (logs_dir_path / "daily.log").string();
    const auto daily_sink = make_shared<spdlog::sinks::daily_file_sink_mt>(daily_log_path, 0, 0);
    daily_sink->set_level(spdlog::level::warn);
    sinks.push_back(daily_sink);

    auto const stderr_sink = make_shared<spdlog::sinks::stderr_color_sink_mt>();
    stderr_sink->set_level(spdlog::level::warn);
    sinks.push_back(stderr_sink);

    auto const logger = make_shared<spdlog::logger>("", sinks.cbegin(), sinks.cend());

    logger->set_pattern(spdlog_pattern);
    logger->set_level(spdlog_level);
    logger->flush_on(spdlog::level::warn);

    set_default_logger(logger);
}

/// \brief 样例。
TEST(sample, wow)
{
    try {
         initialize_rrspdlog_as_default();
    } catch (const exception &e) {
        FAIL() << "initialize_rrspdlog_as_default failed: " << e.what();
    }

    SPDLOG_TRACE("trace message");
    SPDLOG_DEBUG("debug message");
    SPDLOG_INFO("info message");
    SPDLOG_WARN("warn message");
    SPDLOG_ERROR("error message");
    SPDLOG_CRITICAL("critical message");
}

}
