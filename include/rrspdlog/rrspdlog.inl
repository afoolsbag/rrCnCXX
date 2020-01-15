/// \copyright Unlicense

#pragma once
#ifndef RRSPDLOG_INL_
#define RRSPDLOG_INL_

#include "rrspdlog.hxx"

#include <memory>
#include <string>
#include <vector>

#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace rrspdlog {

/// \var default_pattern
/// \details 日志格式形如 `[时间|P.进程|T.线程|来源] 级别: 消息`，其中：\n
///          *   “时间”采用 ISO 8601 标准\n
///          *   “进程”和“线程”取对应进程号和线程号\n
///          *   “来源”在调试模式下为源文件名及行号，在发布模式下为日志器名\n
///          *   “级别”和“消息”在具高亮输出中高亮
/// \sa <https://github.com/gabime/spdlog/wiki/3.-Custom-formatting#pattern-flags>
#ifdef NDEBUG
constexpr auto default_pattern = R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%n] %^%l: %v%$)";
#else
constexpr auto default_pattern = R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%@] %^%l: %v%$)";
#endif

#if SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_TRACE
constexpr auto default_level = spdlog::level::trace;
#elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_DEBUG
constexpr auto default_level = spdlog::level::debug;
#elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_INFO
constexpr auto default_level = spdlog::level::info;
#elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_WARN
constexpr auto default_level = spdlog::level::warn;
#elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_ERROR
constexpr auto default_level = spdlog::level::err;
#elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_CRITICAL
constexpr auto default_level = spdlog::level::critical;
#else
constexpr auto default_level = spdlog::level::off;
#endif

inline void initialize_as_default(const filesystem::path &logs_dir_path,
                                  bool enable_stdout_log,
                                  bool enable_stderr_log,
                                  bool enable_rotating_log,
                                  bool enable_daily_log)
{
    if (!exists(logs_dir_path))
        create_directory(logs_dir_path);
    if (!is_directory(logs_dir_path))
        throw std::runtime_error {std::string {"the logs_dir_path must be a path to a directory: "}.append(logs_dir_path.string())};

    std::vector<spdlog::sink_ptr> sinks;

    if (enable_stdout_log) {
        auto const stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        stdout_sink->set_level(spdlog::level::trace);
        sinks.push_back(stdout_sink);
    }

    if (enable_stderr_log) {
        auto const stderr_sink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
        stderr_sink->set_level(spdlog::level::warn);
        sinks.push_back(stderr_sink);
    }

    if (enable_rotating_log) {
        const auto rotating_log_path = (logs_dir_path / "rotating.log").string();
        constexpr size_t ten_megabyte {10 * 1024 * 1024};
        auto const rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(rotating_log_path, ten_megabyte, 10);
        rotating_sink->set_level(spdlog::level::trace);
        sinks.push_back(rotating_sink);
    }

    if (enable_daily_log) {
        const auto daily_log_path = (logs_dir_path / "daily-info.log").string();
        auto const daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(daily_log_path, 0, 0);
        daily_sink->set_level(spdlog::level::info);
        sinks.push_back(daily_sink);
    }

    auto const logger = std::make_shared<spdlog::logger>("", sinks.cbegin(), sinks.cend());
    logger->set_pattern(default_pattern);
    logger->set_level(default_level);
    logger->flush_on(default_level);

    set_default_logger(logger);
}

}

#endif
