//===-- National Language Support -------------------------------*- C++ -*-===//
///
/// \file
/// \brief 国家语言支持。
///
/// \sa <https://docs.microsoft.com/windows/win32/intl/national-language-support>
///
/// \version 2019-07-08
/// \since 2018-10-19
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

RRWINDOWS_API int RRWINDOWS_CALL compare_string_invariant(const char *lhs, const char *rhs);
inline int compare_string_invariant(const std::string &lhs, const char *rhs) { return compare_string_invariant(lhs.c_str(), rhs); }
inline int compare_string_invariant(const char *lhs, const std::string &rhs) { return compare_string_invariant(lhs, rhs.c_str()); }
inline int compare_string_invariant(const std::string &lhs, const std::string &rhs) { return compare_string_invariant(lhs.c_str(), rhs.c_str()); }
RRWINDOWS_API int RRWINDOWS_CALL compare_string_invariant(const wchar_t *lhs, const wchar_t *rhs);
inline int compare_string_invariant(const std::wstring &lhs, const wchar_t *rhs) { return compare_string_invariant(lhs.c_str(), rhs); }
inline int compare_string_invariant(const wchar_t *lhs, const std::wstring &rhs) { return compare_string_invariant(lhs, rhs.c_str()); }
inline int compare_string_invariant(const std::wstring &lhs, const std::wstring &rhs) { return compare_string_invariant(lhs.c_str(), rhs.c_str()); }

RRWINDOWS_API int RRWINDOWS_CALL compare_string_system_default(const char *lhs, const char *rhs);
inline int compare_string_system_default(const std::string &lhs, const char *rhs) { return compare_string_system_default(lhs.c_str(), rhs); }
inline int compare_string_system_default(const char *lhs, const std::string &rhs) { return compare_string_system_default(lhs, rhs.c_str()); }
inline int compare_string_system_default(const std::string &lhs, const std::string &rhs) { return compare_string_system_default(lhs.c_str(), rhs.c_str()); }
RRWINDOWS_API int RRWINDOWS_CALL compare_string_system_default(const wchar_t *lhs, const wchar_t *rhs);
inline int compare_string_system_default(const std::wstring &lhs, const wchar_t *rhs) { return compare_string_system_default(lhs.c_str(), rhs); }
inline int compare_string_system_default(const wchar_t *lhs, const std::wstring &rhs) { return compare_string_system_default(lhs, rhs.c_str()); }
inline int compare_string_system_default(const std::wstring &lhs, const std::wstring &rhs) { return compare_string_system_default(lhs.c_str(), rhs.c_str()); }

RRWINDOWS_API int RRWINDOWS_CALL compare_string_user_default(const char *lhs, const char *rhs);
inline int compare_string_user_default(const std::string &lhs, const char *rhs) { return compare_string_user_default(lhs.c_str(), rhs); }
inline int compare_string_user_default(const char *lhs, const std::string &rhs) { return compare_string_user_default(lhs, rhs.c_str()); }
inline int compare_string_user_default(const std::string &lhs, const std::string &rhs) { return compare_string_user_default(lhs.c_str(), rhs.c_str()); }
RRWINDOWS_API int RRWINDOWS_CALL compare_string_user_default(const wchar_t *lhs, const wchar_t *rhs);
inline int compare_string_user_default(const std::wstring &lhs, const wchar_t *rhs) { return compare_string_user_default(lhs.c_str(), rhs); }
inline int compare_string_user_default(const wchar_t *lhs, const std::wstring &rhs) { return compare_string_user_default(lhs, rhs.c_str()); }
inline int compare_string_user_default(const std::wstring &lhs, const std::wstring &rhs) { return compare_string_user_default(lhs.c_str(), rhs.c_str()); }

}
