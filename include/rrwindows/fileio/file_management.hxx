//===-- File Management -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 文件管理。
///
/// \sa <https://docs.microsoft.com/windows/win32/fileio/file-management>
///
/// \version 2019-07-08
/// \since 2019-07-01
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <filesystem>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 系统临时文件目录路径。
/// \details 依次查找以下环境变量：
///          1. `%TMP%`
///          2. `%TEMP%`
///          3. `%USERPROFILE%`
///          4. `%WINDIR%`
RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL temp_path();

}
