//===-- Processes and Threads -----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 进程和线程。
///
/// \sa <https://docs.microsoft.com/windows/win32/procthread/processes-and-threads>
///
/// \version 2019-07-08
/// \since 2018-05-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cstddef>
#include <filesystem>
#include <optional>
#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

constexpr std::size_t max_command_len {32768};
constexpr std::size_t max_path_len {260};
constexpr std::size_t max_args_len {max_command_len - max_path_len - 1};

/// \brief 运行可执行文件。
/// \param path     路径；
/// \param args     参数；
/// \param start_in 起始位置；
/// \param show     显示或隐藏。
/// \version 2019-07-05
/// \since 2018-05-07
RRWINDOWS_API void RRWINDOWS_CALL run_executable(const char *path, const char *args = nullptr, const char *start_in = nullptr, bool show = true);
inline void run_executable(const std::filesystem::path &path, const std::optional<std::string> &args = std::nullopt, const std::optional<std::filesystem::path> &start_in = std::nullopt, bool show = true) { return run_executable(path.string().c_str(), args.has_value() ? args.value().c_str() : nullptr, start_in.has_value() ? start_in->string().c_str() : nullptr, show); }
RRWINDOWS_API void RRWINDOWS_CALL run_executable(const wchar_t *path, const wchar_t *args = nullptr, const wchar_t *start_in = nullptr, bool show = true);
inline void run_executable(const std::filesystem::path &path, const std::optional<std::wstring> &args = std::nullopt, const std::optional<std::filesystem::path> &start_in = std::nullopt, bool show = true) { return run_executable(path.wstring().c_str(), args.has_value() ? args.value().c_str() : nullptr, start_in.has_value() ? start_in->wstring().c_str() : nullptr, show); }

/// \brief 以活动用户运行可执行文件。
/// \param path     路径；
/// \param args     参数；
/// \param start_in 起始位置；
/// \param show     显示或隐藏。
/// \version 2019-07-05
/// \since 2019-04-22
RRWINDOWS_API void RRWINDOWS_CALL run_executable_as_active(const char *path, const char *args = nullptr, const char *start_in = nullptr, bool show = true);
inline void run_executable_as_active(const std::filesystem::path &path, const std::optional<std::string> &args = std::nullopt, const std::optional<std::filesystem::path> &start_in = std::nullopt, bool show = true) { return run_executable_as_active(path.string().c_str(), args.has_value() ? args.value().c_str() : nullptr, start_in.has_value() ? start_in->string().c_str() : nullptr, show); }
RRWINDOWS_API void RRWINDOWS_CALL run_executable_as_active(const wchar_t *path, const wchar_t *args = nullptr, const wchar_t *start_in = nullptr, bool show = true);
inline void run_executable_as_active(const std::filesystem::path &path, const std::optional<std::wstring> &args = std::nullopt, const std::optional<std::filesystem::path> &start_in = std::nullopt, bool show = true) { return run_executable_as_active(path.wstring().c_str(), args.has_value() ? args.value().c_str() : nullptr, start_in.has_value() ? start_in->wstring().c_str() : nullptr, show); }

/// \brief 杀死可执行文件进程。
/// \details 尝试终止指定可执行文件的所有进程，不会因对单个进程的终止失败而中断。
/// \returns 残余的进程数。
RRWINDOWS_API std::size_t RRWINDOWS_CALL kill_executable(const char *executable_name);
inline std::size_t kill_executable(const std::string &executable_name) { return kill_executable(executable_name.c_str()); }
RRWINDOWS_API std::size_t RRWINDOWS_CALL kill_executable(const wchar_t *executable_name);
inline std::size_t kill_executable(const std::wstring &executable_name) { return kill_executable(executable_name.c_str()); }

}
