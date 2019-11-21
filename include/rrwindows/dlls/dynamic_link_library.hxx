//===-- Dynamic-Link Libraries ----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 动态链接库。
///
/// \sa <https://docs.microsoft.com/windows/win32/dlls/dynamic-link-libraries>
///
/// \version 2019-07-08
/// \since 2018-05-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <filesystem>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 当前进程可执行文件路径。
/// \details 形如 `path\\to\\folder\\file.exe`。
RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL executable_path();

/// \brief `rrWindows.dll` 路径。
RRWINDOWS_API std::filesystem::path RRWINDOWS_CALL rrwindows_path();

}
