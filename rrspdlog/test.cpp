/// \copyright Unlicense

#include <filesystem>
#include <memory>
#include <vector>

#include <boost/dll.hpp>
#include <gtest/gtest.h>

#include <spdlog/common.h>
#ifndef NDEBUG
# ifdef SPDLOG_ACTIVE_LEVEL
#  undef SPDLOG_ACTIVE_LEVEL
# endif
# define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

using namespace std;

namespace rrspdlog {

/// \var pattern
/// \details 日志格式形如 `[时间|P.进程|T.线程|来源] 级别: 消息`，其中：\n
///          *   “时间”采用 ISO 8601 标准\n
///          *   “进程”和“线程”取对应进程号和线程号\n
///          *   “来源”在调试模式下为源文件名及行号，在发布模式下为日志器名\n
///          *   “级别”和“消息”在具高亮输出中高亮
/// \sa <https://github.com/gabime/spdlog/wiki/3.-Custom-formatting#pattern-flags>
#ifdef NDEBUG
constexpr auto pattern {R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%n] %^%l: %v%$)"};
#else
constexpr auto pattern {R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%@] %^%l: %v%$)"};
#endif

/// \brief 默认日志器。
TEST(test, default_logger)
{
#if 0
    // 变更默认日志器
    spdlog::set_default_logger();
#endif

    // 配置默认日志器
    spdlog::set_pattern(pattern);
    spdlog::set_level(spdlog::level::trace);
    spdlog::flush_on(spdlog::level::warn);

    // 使用默认日志器
    SPDLOG_TRACE("trace message");
    SPDLOG_DEBUG("debug message");
    SPDLOG_INFO("info message");
    SPDLOG_WARN("warn message");
    SPDLOG_ERROR("error message");
    SPDLOG_CRITICAL("critical message");
}

/// \brief 基础文件日志器。
TEST(test, basic_file_logger)
{
    // 日志
    const auto logs_name = [] {
        const auto logs_dir = boost::dll::program_location().parent_path() / "logs";
        create_directory(logs_dir);
        return (logs_dir / "basic.log").string();
    }();

    // 配置
    try {
        const auto logger = spdlog::basic_logger_mt("basic_logger", logs_name);
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);

    } catch (const exception &e) {
        FAIL() << "init log failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("basic_logger");
        ASSERT_TRUE(logger);

        SPDLOG_LOGGER_TRACE(logger, "trace message.");
        SPDLOG_LOGGER_DEBUG(logger, "debug message.");
        SPDLOG_LOGGER_INFO(logger, "info message.");
        SPDLOG_LOGGER_WARN(logger, "warn message.");
        SPDLOG_LOGGER_ERROR(logger, "error message.");
        SPDLOG_LOGGER_CRITICAL(logger, "critical message.");

    } catch (const exception &e) {
        FAIL() << "log failed: " << e.what();
    }

}

/// \brief 标准流日志器。
TEST(test, stdout_logger)
{
    // 配置
    try {
        auto const stdout_sink = make_shared<spdlog::sinks::stdout_color_sink_mt>();
        stdout_sink->set_level(spdlog::level::trace);

        auto const stderr_sink = make_shared<spdlog::sinks::stderr_color_sink_mt>();
        stderr_sink->set_level(spdlog::level::warn);

        vector<spdlog::sink_ptr> sinks;
        sinks.push_back(stdout_sink);
        sinks.push_back(stderr_sink);

        auto const logger = make_shared<spdlog::logger>("stdio_logger", sinks.begin(), sinks.end());
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);

        register_logger(logger);

    } catch (const exception &e) {
        FAIL() << "init sink or logger failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("stdio_logger");
        ASSERT_TRUE(logger);

        SPDLOG_LOGGER_TRACE(logger, "trace message.");
        SPDLOG_LOGGER_DEBUG(logger, "debug message.");
        SPDLOG_LOGGER_INFO(logger, "info message.");
        SPDLOG_LOGGER_WARN(logger, "warn message.");
        SPDLOG_LOGGER_ERROR(logger, "error message.");
        SPDLOG_LOGGER_CRITICAL(logger, "critical message.");

    } catch (const exception &e) {
        FAIL() << "log failed: " << e.what();
    }
}

/// \brief 旋转文件日志器。
TEST(test, rotating_file_logger)
{
    // 日志
    const auto logs_name = [] {
        const auto logs_dir = boost::dll::program_location().parent_path() / "logs";
        create_directory(logs_dir);
        return (logs_dir / "rotating.log").string();
    }();

    // 配置
    try {
        const auto logger = spdlog::rotating_logger_mt("rotating_logger",
                                                       logs_name,
                                                       5 * 1024 * 1024,
                                                       5);
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);

    } catch (const exception &e) {
        FAIL() << "init log failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("rotating_logger");
        ASSERT_TRUE(logger);

        SPDLOG_LOGGER_TRACE(logger, "trace message.");
        SPDLOG_LOGGER_DEBUG(logger, "debug message.");
        SPDLOG_LOGGER_INFO(logger, "info message.");
        SPDLOG_LOGGER_WARN(logger, "warn message.");
        SPDLOG_LOGGER_ERROR(logger, "error message.");
        SPDLOG_LOGGER_CRITICAL(logger, "critical message.");

    } catch (const exception &e) {
        FAIL() << "log failed: " << e.what();
    }
}

/// \brief 每日文件日志器。
TEST(test, daily_file_logger)
{
    // 日志
    const auto logs_name = [] {
        const auto logs_dir = boost::dll::program_location().parent_path() / "logs";
        create_directory(logs_dir);
        return (logs_dir / "daily.log").string();
    }();

    // 配置
    try {
        const auto logger = spdlog::daily_logger_mt("daily_logger", logs_name);
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);

    } catch (const exception &e) {
        FAIL() << "Log init failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("daily_logger");
        ASSERT_TRUE(logger);

        SPDLOG_LOGGER_TRACE(logger, "trace message.");
        SPDLOG_LOGGER_DEBUG(logger, "debug message.");
        SPDLOG_LOGGER_INFO(logger, "info message.");
        SPDLOG_LOGGER_WARN(logger, "warn message.");
        SPDLOG_LOGGER_ERROR(logger, "error message.");
        SPDLOG_LOGGER_CRITICAL(logger, "critical message.");

    } catch (const exception &e) {
        FAIL() << "Log use failed: " << e.what();
    }
}

}
