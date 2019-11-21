//===-- Unicode and Character Sets ------------------------------*- C++ -*-===//
///
/// \file
/// \brief 统一码与字符集。
///
/// \sa <https://docs.microsoft.com/windows/win32/intl/unicode-and-character-sets>
///
/// \version 2019-07-08
/// \since 2018-01-11
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

#ifndef CP_ACP
constexpr unsigned CP_ACP {0};
#endif
#ifndef CP_GB2312
constexpr unsigned CP_GB2312 {936};
#endif
#ifndef CP_BIG5
constexpr unsigned CP_BIG5 {950};
#endif
#ifndef CP_GB18030
constexpr unsigned CP_GB18030 {54936};
#endif
#ifndef CP_UTF8
constexpr unsigned CP_UTF8 {65001};
#endif

/// \brief 多字节字符串转宽字节 Unicode 字符串。
/// \param src   源多字节字符串。
/// \param srccp 源多字节字符串代码页。
RRWINDOWS_API std::wstring RRWINDOWS_CALL multi_byte_to_wide_char(const char *src, unsigned srccp);
inline std::wstring multi_byte_to_wide_char(const std::string &src, unsigned srccp) { return multi_byte_to_wide_char(src.c_str(), srccp); }

/// \brief 宽字节 Unicode 字符串转多字节字符串。
/// \param src   源宽字节 Unicode 字符串。
/// \param dstcp 目的多字节字符串代码页。
RRWINDOWS_API std::string RRWINDOWS_CALL wide_char_to_multi_byte(const wchar_t *src, unsigned dstcp);
inline std::string wide_char_to_multi_byte(const std::wstring src, unsigned dstcp) { return wide_char_to_multi_byte(src.c_str(), dstcp); }

#ifdef _UNICODE
using tstring = std::wstring;
inline tstring xstring(const std::string &src, unsigned srccp = CP_ACP) { return multi_byte_to_wide_char(src.c_str(), srccp); }
inline tstring xstring(const std::wstring &src, [[maybe_unused]] unsigned srccp = CP_ACP) { return src; }
#else
using tstring = std::string;
inline tstring xstring(const std::string &src, [[maybe_unused]] unsigned dstcp = CP_ACP) { return src; }
inline tstring xstring(const std::wstring &src, unsigned dstcp = CP_ACP) { return wide_char_to_multi_byte(src.c_str(), dstcp); }
#endif

/// \brief 多字节字符串转多字节字符串。
/// \param src   源多字节字符串。
/// \param srccp 源多字节字符串代码页。
/// \param dstcp 目标多字节字符串代码页。
RRWINDOWS_API std::string RRWINDOWS_CALL multi_byte_to_multi_byte(const char *src, unsigned srccp, unsigned dstcp);
inline std::string multi_byte_to_multi_byte(const std::string &src, unsigned srccp, unsigned dstcp) { return multi_byte_to_multi_byte(src.c_str(), srccp, dstcp); }

}
