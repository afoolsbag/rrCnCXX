//===------------------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief `spdlog` 日志初始化包装
///
/// \version 2019-08-06
/// \since 2019-08-06
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRSPDLOG_HXX_
#define RRSPDLOG_HXX_

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

#include <spdlog/common.h>
#ifdef SPDLOG_H
#error This header must be included before other spdlog headers.
#endif
#ifdef SPDLOG_ACTIVE_LEVEL
#undef SPDLOG_ACTIVE_LEVEL
#endif
#ifdef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace rrspdlog {

#ifdef NDEBUG
constexpr auto pattern = R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%n] %^%l: %v%$)";
constexpr auto level = spdlog::level::info;
#else
constexpr auto pattern = R"([%Y-%m-%dT%H:%M:%S.%e%z|P.%P|T.%t|%@] %^%l: %v%$)";
constexpr auto level = spdlog::level::trace;
#endif

/// \brief 初始化 `spdlog` 日志器并设为默认日志器
/// \details 该日志器配置三个接收槽：
///          1. 轮转日志文件，以 10MiB 为限，轮转 10 个文件，接收所有等级消息
///          2. 每日日志文件，以每日零时分割，接收警告及以上等级消息
///          2. 标准错误流，接收警告及以上等级消息
///
/// \param logs_dir_path 日志文件目录路径
inline void initialize_as_default(const std::filesystem::path &logs_dir_path)
{
    if (!exists(logs_dir_path))
        create_directory(logs_dir_path);
    if (!is_directory(logs_dir_path))
        throw std::runtime_error {std::string {"the logs_dir_path must be a path to a directory: "}.append(logs_dir_path.string())};

    std::vector<spdlog::sink_ptr> sinks;

    const auto rotating_log_path = (logs_dir_path / "rotating.log").string();
    constexpr size_t ten_megabyte {10 * 1024 * 1024};
    const auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(rotating_log_path, ten_megabyte, 10);
    rotating_sink->set_level(spdlog::level::trace);
    sinks.push_back(rotating_sink);

    const auto daily_log_path = (logs_dir_path / "daily.log").string();
    const auto daily_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(daily_log_path, 0, 0);
    daily_sink->set_level(spdlog::level::warn);
    sinks.push_back(daily_sink);

    auto const stderr_sink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
    stderr_sink->set_level(spdlog::level::warn);
    sinks.push_back(stderr_sink);

    auto const logger = std::make_shared<spdlog::logger>("", sinks.cbegin(), sinks.cend());

    logger->set_pattern(pattern);
    logger->set_level(level);
    logger->flush_on(spdlog::level::warn);

    set_default_logger(logger);
}

}

#endif
