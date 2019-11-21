//===-- Strings -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 字符串。
///
/// \sa <https://docs.microsoft.com/windows/win32/menurc/strings>
///
/// \version 2019-07-08
/// \since 2018-05-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 比较字符串：string compare
/// \param lhs 左侧字符串；
/// \param rhs 右侧字符串。
/// \returns `(-, 0)` 左侧小于右侧；\n
///          `[0, 0]` 两侧相等；\n
///          `(0, +)` 左侧大于右侧。
RRWINDOWS_API int RRWINDOWS_CALL strcmp(const char *lhs, const char *rhs);
inline int strcmp(const std::string &lhs, const char *rhs) { return strcmp(lhs.c_str(), rhs); }
inline int strcmp(const char *lhs, const std::string &rhs) { return strcmp(lhs, rhs.c_str()); }
inline int strcmp(const std::string &lhs, const std::string &rhs) { return strcmp(lhs.c_str(), rhs.c_str()); }
RRWINDOWS_API int RRWINDOWS_CALL strcmp(const wchar_t *lhs, const wchar_t *rhs);
inline int strcmp(const std::wstring &lhs, const wchar_t *rhs) { return strcmp(lhs.c_str(), rhs); }
inline int strcmp(const wchar_t *lhs, const std::wstring &rhs) { return strcmp(lhs, rhs.c_str()); }
inline int strcmp(const std::wstring &lhs, const std::wstring &rhs) { return strcmp(lhs.c_str(), rhs.c_str()); }

/// \brief 计算字符串长度：string length
/// \param str 字符串。
/// \returns 长度。
RRWINDOWS_API std::size_t RRWINDOWS_CALL strlen(const char *str);
inline std::size_t strlen(const std::string &str) { return strlen(str.c_str()); }
RRWINDOWS_API std::size_t RRWINDOWS_CALL strlen(const wchar_t *str);
inline std::size_t strlen(const std::wstring &str) { return strlen(str.c_str()); }

}
