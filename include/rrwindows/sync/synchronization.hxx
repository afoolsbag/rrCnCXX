//===-- Synchronization -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 服务。
///
/// \sa <https://docs.microsoft.com/windows/win32/sync/synchronization>
///
/// \version 2019-07-08
/// \since 2019-07-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

RRWINDOWS_API bool RRWINDOWS_CALL is_singleton_process(const char *identifier);
inline bool is_singleton_process(const std::string &identifier) { return is_singleton_process(identifier.c_str()); }
RRWINDOWS_API bool RRWINDOWS_CALL is_singleton_process(const wchar_t *identifier);
inline bool is_singleton_process(const std::wstring &identifier) { return is_singleton_process(identifier.c_str()); }


}
