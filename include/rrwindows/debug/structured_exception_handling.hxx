//===-- Structured Exception Handling ---------------------------*- C++ -*-===//
///
/// \file
/// \brief 结构化异常处理。
///
/// \sa <https://docs.microsoft.com/windows/win32/debug/structured-exception-handling>
///
/// \version 2019-11-28
/// \since 2018-06-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrwindows {

/// \brief 设定崩溃转储过滤器。
/// \details 生成转储文件：\n
///          首先尝试存储在 `%TEMP%\\dump\\ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss.dmp`，\n
///          其次尝试存储在 `StartIn\\crash.dmp`。
inline void set_crash_dump_filter();

inline void reset_unhandled_exception_filter();

}

#include "structured_exception_handling.inl"
