//===-- System Information --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 错误处理。
///
/// \sa <https://docs.microsoft.com/windows/win32/sysinfo/system-information>
///
/// \version 2019-11-28
/// \since 2019-07-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <filesystem>

namespace rrwindows {

/// \brief 系统目录路径。
/// \details 如 `C:\\Windows\\System32`
inline std::filesystem::path system_directory_path();

/// \brief 系统 Windows 目录路径。
/// \details 如 `C:\\Windows`
inline std::filesystem::path system_windows_directory_path();

/// \brief 私有 Windows 目录路径。
/// \details 如 `C:\\Windows`
inline std::filesystem::path windows_directory_path();

}

#include "system_information.inl"
