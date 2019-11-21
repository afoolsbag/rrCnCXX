//===-- System Information --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 错误处理。
///
/// \sa <https://docs.microsoft.com/windows/win32/sysinfo/system-information>
///
/// \version 2019-07-08
/// \since 2019-07-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <filesystem>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 系统目录路径。
/// \details 如 `C:\\Windows\\System32`
RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL system_directory_path();

/// \brief 系统 Windows 目录路径。
/// \details 如 `C:\\Windows`
RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL system_windows_directory_path();

/// \brief 私有 Windows 目录路径。
/// \details 如 `C:\\Windows`
RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL windows_directory_path();

}
