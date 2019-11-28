//===-- Dynamic-Link Libraries ----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 动态链接库。
///
/// \sa <https://docs.microsoft.com/windows/win32/dlls/dynamic-link-libraries>
///
/// \version 2019-11-28
/// \since 2018-05-08
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <filesystem>

namespace rrwindows {

/// \brief 当前进程可执行文件路径。
/// \details 形如 `path\\to\\folder\\file.exe`。
inline std::filesystem::path executable_path();

/// \brief `image` 路径。
inline std::filesystem::path image_path();

}

#include "dynamic_link_library.inl"
