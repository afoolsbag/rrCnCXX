//===-- Tool Help Library ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 工具帮助库。
///
/// \sa <https://docs.microsoft.com/windows/win32/toolhelp/tool-help-library>
///
/// \version 2019-07-08
/// \since 2018-04-28
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cstddef>
#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 按可执行文件名计数进程。
/// \param executable_name 可执行文件名，如 `foobar.exe`。
RRWINDOWS_API std::size_t RRWINDOWS_CALL count_processes_by_name(const char *executable_name);
inline std::size_t count_processes_by_name(const std::string &executable_name) { return count_processes_by_name(executable_name.c_str()); }
RRWINDOWS_API std::size_t RRWINDOWS_CALL count_processes_by_name(const wchar_t *executable_name);
inline std::size_t count_processes_by_name(const std::wstring &executable_name) { return count_processes_by_name(executable_name.c_str()); }

}
