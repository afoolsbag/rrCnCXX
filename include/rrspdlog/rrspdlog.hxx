//===-- rrspdlog spdlog Wrapper ---------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2020-04-21
/// \since 2019-08-06
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRSPDLOG_HXX_
#define RRSPDLOG_HXX_

#if defined(__cpp_lib_filesystem) || defined(__has_include) && __has_include(<filesystem>)
#include <filesystem>
namespace rrspdlog { namespace filesystem = std::filesystem; }
#elif defined(__cpp_lib_experimental_filesystem) || defined(__has_include) && __has_include(<experimental/filesystem>)
#include <experimental/filesystem>
namespace rrspdlog { namespace filesystem = std::experimental::filesystem; }
#else
#include <boost/filesystem.hpp>
namespace rrspdlog { namespace filesystem = boost::filesystem; }
#endif

#ifdef SPDLOG_H
#error This header must be included before other spdlog headers.
#endif

#include <spdlog/common.h>

#ifdef SPDLOG_ACTIVE_LEVEL
#undef SPDLOG_ACTIVE_LEVEL
#endif

#ifdef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

namespace rrspdlog {

/// \brief 初始化 `spdlog` 日志器并设为默认日志器。
/// \details 该日志器配置四个接收槽：
///          1. 每日日志文件，以每日零时分割，接收信息及以上等级消息；
///          2. 轮转日志文件，以 10MiB 为限，轮转 10 个文件，接收所有等级消息；
///          3. 标准输出流，接收信息及以上等级消息；
///          4. 标准错误流，接收警告及以上等级消息。
///
/// \param logs_dir_path       日志文件目录路径
/// \param enable_stdout_log   启用标准输出
/// \param enable_stderr_log   启用错误输出
/// \param enable_rotating_log 启用轮转日志
/// \param enable_daily_log    启用每日日志
///
/// \warning 为了实时性，该配置使日志逐条清出而不缓存，若遭遇性能瓶颈可考虑对此优化。
inline void initialize_as_default(const filesystem::path &logs_dir_path,
                                  bool enable_stdout_log = true,
                                  bool enable_stderr_log = true,
                                  bool enable_rotating_log = true,
                                  bool enable_daily_log = true);

}

#include "rrspdlog.inl"

#endif
