/// \copyright Unlicense

#include <filesystem>
#include <memory>
#include <vector>

#include <gtest/gtest.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

using namespace std;

namespace rrspdlog {

/// \sa <https://github.com/gabime/spdlog/wiki/3.-Custom-formatting#pattern-flags>
constexpr auto pattern {"[%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t] %^\"%n\" %l: %v%$"};

/// \brief 默认日志器。
TEST(spdlog, default_logger)
{
    // 配置默认日志器
    spdlog::set_pattern(pattern);
    spdlog::set_level(spdlog::level::trace);
    spdlog::flush_on(spdlog::level::warn);

    // 使用默认日志器
    spdlog::trace("trace message");
    spdlog::debug("debug message");
    spdlog::info("info message");
    spdlog::warn("warn message");
    spdlog::error("error message");
    spdlog::critical("critical message");

#if 0
    // 更换默认日志器
    spdlog::set_default_logger();
#endif
}

/// \brief 基础文件日志器。
TEST(spdlog, basic_file_logger)
{
    // 日志
    const auto logs_name = [] {
        const filesystem::path exe_path = __argv[0];
        const auto logs_dir = exe_path.parent_path() / "logs";
        create_directory(logs_dir);
        return (logs_dir / "basic.log").string();
    }();

    // 配置
    try {
        const auto logger = spdlog::basic_logger_mt("basic logger", logs_name);
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);
    } catch (const exception &e) {
        FAIL() << "Log init failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("basic logger");
        ASSERT_TRUE(logger);
        logger->trace("trace message.");
        logger->debug("debug message.");
        logger->info("info message.");
        logger->warn("warn message.");
        logger->error("error message.");
        logger->critical("critical message.");
    } catch (const exception &e) {
        FAIL() << "Log use failed: " << e.what();
    }

}

/// \brief 标准流日志器。
TEST(spdlog, stdout_logger)
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

        auto const logger = make_shared<spdlog::logger>("stdout logger", sinks.begin(), sinks.end());
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);

        register_logger(logger);

    } catch (const exception &e) {
        FAIL() << "Sink or logger init failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("stdout logger");
        ASSERT_TRUE(logger);

        logger->trace("trace message.");
        logger->debug("debug message.");
        logger->info("info message.");
        logger->warn("warn message.");
        logger->error("error message.");
        logger->critical("critical message.");

    } catch (const exception &e) {
        FAIL() << "Log failed: " << e.what();
    }
}

static constexpr size_t operator"" _KiB(size_t s) { return s * 1'024ull; }
static constexpr size_t operator"" _KiB(long double s) { return static_cast<size_t>(s * 1'024ull); }
static constexpr size_t operator"" _MiB(size_t s) { return s * 1'048'576ull; }
static constexpr size_t operator"" _MiB(long double s) { return static_cast<size_t>(s * 1'048'576ull); }
static constexpr size_t operator"" _GiB(size_t s) { return s * 1'073'741'824ull; }
static constexpr size_t operator"" _GiB(long double s) { return static_cast<size_t>(s * 1'073'741'824ull); }
static constexpr size_t operator"" _TiB(size_t s) { return s * 1'099'511'627'776ull; }
static constexpr size_t operator"" _TiB(long double s) { return static_cast<size_t>(s * 1'099'511'627'776ull); }
static constexpr size_t operator"" _PiB(size_t s) { return s * 1'125'899'906'842'624ull; }
static constexpr size_t operator"" _PiB(long double s) { return static_cast<size_t>(s * 1'125'899'906'842'624ull); }

/// \brief 旋转文件日志器。
TEST(spdlog, rotating_file_logger)
{
    // 日志
    const auto logs_name = [] {
        const filesystem::path exe_path = __argv[0];
        const auto logs_dir = exe_path.parent_path() / "logs";
        create_directory(logs_dir);
        return (logs_dir / "rotating.log").string();
    }();

    // 配置
    try {
        const auto logger = spdlog::rotating_logger_mt("rotating logger",
                                                       logs_name,
                                                       5_MiB,
                                                       5);
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);
    } catch (const exception &e) {
        FAIL() << "Log init failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("rotating logger");
        ASSERT_TRUE(logger);
        logger->trace("trace message.");
        logger->debug("debug message.");
        logger->info("info message.");
        logger->warn("warn message.");
        logger->error("error message.");
        logger->critical("critical message.");
    } catch (const exception &e) {
        FAIL() << "Log use failed: " << e.what();
    }
}

/// \brief 每日文件日志器。
TEST(spdlog, daily_file_logger)
{
    // 日志
    const auto logs_name = [] {
        const filesystem::path exe_path = __argv[0];
        const auto logs_dir = exe_path.parent_path() / "logs";
        create_directory(logs_dir);
        return (logs_dir / "daily.log").string();
    }();

    // 配置
    try {
        const auto logger = spdlog::daily_logger_mt("daily logger", logs_name);
        logger->set_pattern(pattern);
        logger->set_level(spdlog::level::trace);
        logger->flush_on(spdlog::level::warn);
    } catch (const exception &e) {
        FAIL() << "Log init failed: " << e.what();
    }

    // 使用
    try {
        const auto logger = spdlog::get("daily logger");
        ASSERT_TRUE(logger);
        logger->trace("trace message.");
        logger->debug("debug message.");
        logger->info("info message.");
        logger->warn("warn message.");
        logger->error("error message.");
        logger->critical("critical message.");
    } catch (const exception &e) {
        FAIL() << "Log use failed: " << e.what();
    }
}

}//namespace rrspdlog
