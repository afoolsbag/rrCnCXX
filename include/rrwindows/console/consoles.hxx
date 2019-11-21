//===-- Consoles ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 控制台。
///
/// \sa <https://docs.microsoft.com/windows/console/consoles>
///
/// \version 2019-07-08
/// \since 2018-04-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cstdint>
#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 控制台颜色。
enum class console_color : std::uint16_t {
    black = 0x0, blue = 0x1, green = 0x2, aqua = 0x3,
    red = 0x4, purple = 0x5, yellow = 0x6, white = 0x7,
    gray = 0x8, light_blue = 0x9, light_green = 0xA, light_aqua = 0xB,
    light_red = 0xC, light_purple = 0xD, light_yellow = 0xE, bright_white = 0xF
};

/// \brief 向标准输出流写入：put string
RRWINDOWS_API void RRWINDOWS_CALL puts(const char *text);
inline void puts(const std::string &text) { return puts(text.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL puts(const wchar_t *text);
inline void puts(const std::wstring &text) { return puts(text.c_str()); }

/// \brief 向标准错误流写入：error put string
RRWINDOWS_API void RRWINDOWS_CALL eputs(const char *text);
inline void eputs(const std::string &text) { return eputs(text.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL eputs(const wchar_t *text);
inline void eputs(const std::wstring &text) { return eputs(text.c_str()); }

/// \brief 格式化写入标准输出流：print format
/// \param format 格式。
/// \param ...    参数。
RRWINDOWS_API void RRWINDOWS_CALLV printf(const char *format, ...);
RRWINDOWS_API void RRWINDOWS_CALLV printf(const wchar_t *format, ...);

/// \brief 格式化写入标准错误流：error print format
/// \param format 格式。
/// \param ...    参数。
RRWINDOWS_API void RRWINDOWS_CALLV eprintf(const char *format, ...);
RRWINDOWS_API void RRWINDOWS_CALLV eprintf(const wchar_t *format, ...);

/// \brief 清空标准输出流屏幕。
RRWINDOWS_API void RRWINDOWS_CALL clear_stdout_screen();

/// \brief 清空标准错误流屏幕。
RRWINDOWS_API void RRWINDOWS_CALL clear_stderr_screen();

}
