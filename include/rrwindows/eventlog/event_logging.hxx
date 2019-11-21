//===-- Event Logging -------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 事件记录。
///
/// \sa <https://docs.microsoft.com/windows/win32/eventlog/event-logging>
///
/// \version 2019-07-08
/// \since 2019-07-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cstdint>
#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

#ifndef EVENTLOG_SUCCESS
constexpr std::uint16_t EVENTLOG_SUCCESS = 0x0000;
#endif
#ifndef EVENTLOG_ERROR_TYPE 
constexpr std::uint16_t EVENTLOG_ERROR_TYPE = 0x0001;
#endif
#ifndef EVENTLOG_WARNING_TYPE 
constexpr std::uint16_t EVENTLOG_WARNING_TYPE = 0x0002;
#endif
#ifndef EVENTLOG_INFORMATION_TYPE 
constexpr std::uint16_t EVENTLOG_INFORMATION_TYPE = 0x0004;
#endif
#ifndef EVENTLOG_AUDIT_SUCCESS 
constexpr std::uint16_t EVENTLOG_AUDIT_SUCCESS = 0x0008;
#endif
#ifndef EVENTLOG_AUDIT_FAILURE 
constexpr std::uint16_t EVENTLOG_AUDIT_FAILURE = 0x0010;
#endif

RRWINDOWS_API void RRWINDOWS_CALL log_event(const char *src, std::uint16_t type, const char *msg);
inline void log_event(const std::string &src, std::uint16_t type, const std::string &msg) { return log_event(src.c_str(), type, msg.c_str()); }

RRWINDOWS_API void RRWINDOWS_CALL log_event(const wchar_t *src, uint16_t type, const wchar_t *msg);
inline void log_event(const std::wstring &src, std::uint16_t type, const std::wstring &msg) { return log_event(src.c_str(), type, msg.c_str()); }

}
