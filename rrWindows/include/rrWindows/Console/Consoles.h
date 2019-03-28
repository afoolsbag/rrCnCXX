/*===-- Consoles -----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 控制台。
 *
 * \version 2019-03-28
 * \since 2018-04-14
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrWindows/macros.h"

#include "rrWindows/MenuRc/Strings.h"

/*------------------------------------------------------------------------------
 * 简化控制台颜色
 */

/**
 * \brief 控制台颜色。
 */
typedef
enum ConsoleColor {
    ConsoleBlack = 0x0,
    ConsoleBlue = 0x1,
    ConsoleGreen = 0x2,
    ConsoleAqua = 0x3,
    ConsoleRed = 0x4,
    ConsolePurple = 0x5,
    ConsoleYellow = 0x6,
    ConsoleWhite = 0x7,
    ConsoleGray = 0x8,
    ConsoleLightBlue = 0x9,
    ConsoleLightGreen = 0xA,
    ConsoleLightAqua = 0xB,
    ConsoleLightRed = 0xC,
    ConsoleLightPurple = 0xD,
    ConsoleLightYellow = 0xE,
    ConsoleBrightWhite = 0xF
} ConsoleColor;

/**
 * \brief 获取控制台背景色。
 *
 * \param hConsoleOutput 控制台句柄。
 */
FORCEINLINE
ConsoleColor
WINAPI_INLINE
GetConsoleBackGroundColor(
    _In_ HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &info))
        return ConsoleBlack;
    return (ConsoleColor)((info.wAttributes & 0x00F0) >> 4);
}

/**
 * \brief 获取控制台前景色。
 *
 * \param hConsoleOutput 控制台句柄。
 */
FORCEINLINE
ConsoleColor
WINAPI_INLINE
GetConsoleForeGroundColor(
    _In_ HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &info))
        return ConsoleWhite;
    return (ConsoleColor)(info.wAttributes & 0x000F);
}

/**
 * \brief 设定控制台背景色。
 *
 * \param hConsoleOutput 控制台句柄。
 * \param backGroundColor 背景色。
 */
FORCEINLINE
VOID
WINAPI_INLINE
SetConsoleBackGroundColor(
    _In_ HANDLE       hConsoleOutput,
    _In_ ConsoleColor backGroundColor)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &info))
        return;
    info.wAttributes &= 0xFF0F;
    info.wAttributes |= backGroundColor << 4;
    if (!SetConsoleTextAttribute(hConsoleOutput, info.wAttributes))
        return;
}

/**
 * \brief 设定控制台前景色。
 *
 * \param hConsoleOutput 控制台句柄。
 * \param foreGroundColor 前景色。
 */
FORCEINLINE
VOID
WINAPI_INLINE
SetConsoleForeGroundColor(
    _In_ HANDLE       hConsoleOutput,
    _In_ ConsoleColor foreGroundColor)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &info))
        return;
    info.wAttributes &= 0xFFF0;
    info.wAttributes |= foreGroundColor;
    if (!SetConsoleTextAttribute(hConsoleOutput, info.wAttributes))
        return;
}

/*------------------------------------------------------------------------------
 * 简化写入标准输出流和标准错误流
 */

/**
 * \brief 向标准输出流写入，Simplify 接口，ANSI 适配。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
WriteStdoutA(
    _In_z_ PCSTR text)
{
    CONST HANDLE outHdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (outHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return WriteConsoleA(outHdl, text, (DWORD)StringCchLengthSA(text), NULL, NULL);
}

/**
 * \brief 向标准输出流写入，Simplify 接口，Unicode 适配。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
WriteStdoutW(
    _In_z_ PCWSTR text)
{
    CONST HANDLE outHdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (outHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return WriteConsoleW(outHdl, text, (DWORD)StringCchLengthSW(text), NULL, NULL);
}

#ifdef _UNICODE
# define WriteStdout WriteStdoutW
#else
# define WriteStdout WriteStdoutA
#endif

/**
 * \brief 向标准错误流写入，Simplify 接口，ANSI 适配。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
WriteStderrA(
    _In_z_ PCSTR text)
{
    CONST HANDLE errHdl = GetStdHandle(STD_ERROR_HANDLE);
    if (errHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return WriteConsoleA(errHdl, text, (DWORD)StringCchLengthSA(text), NULL, NULL);
}

/**
 * \brief 向标准错误流写入，Simplify 接口，Unicode 适配。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
WriteStderrW(
    _In_z_ PCWSTR text)
{
    CONST HANDLE errHdl = GetStdHandle(STD_ERROR_HANDLE);
    if (errHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return WriteConsoleW(errHdl, text, (DWORD)StringCchLengthSW(text), NULL, NULL);
}

#ifdef _UNICODE
# define WriteStderr WriteStderrW
#else
# define WriteStderr WriteStderrA
#endif

/*------------------------------------------------------------------------------
 * 格式化写入控制台及其简化
 */

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 格式化写入控制台，ANSI 适配。
 *
 * \param hConsoleOutput 控制台句柄。
 * \param format         格式。
 * \param argList        参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
VPrintfConsoleA(
    _In_                          HANDLE  hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCSTR  format,
    _In_                          va_list argList
);

/**
 * \brief 格式化写入控制台，Unicode 适配。
 *
 * \param hConsoleOutput 控制台句柄。
 * \param format         格式。
 * \param argList        参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
VPrintfConsoleW(
    _In_                          HANDLE  hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCWSTR format,
    _In_                          va_list argList
);

#ifdef _UNICODE
# define VPrintfConsole VPrintfConsoleW
#else
# define VPrintfConsole VPrintfConsoleA
#endif

/**
 * \brief 格式化写入控制台，Simplify 接口，ANSI 适配。
 *
 * \param hConsoleOutput 控制台句柄。
 * \param format         格式。
 * \param ...            参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfConsoleA(
    _In_                          HANDLE hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...
);

/**
 * \brief 格式化写入控制台，Simplify 接口，Unicode 适配。
 *
 * \param hConsoleOutput 控制台句柄。
 * \param format         格式。
 * \param ...            参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfConsoleW(
    _In_                          HANDLE  hConsoleOutput,
    _In_z_ _Printf_format_string_ LPCWSTR format,
    ...
);

#ifdef _UNICODE
# define PrintfConsole PrintfConsoleW
#else
# define PrintfConsole PrintfConsoleA
#endif

/**
 * \brief 格式化写入标准输出流，Simplify 接口，ANSI 适配。
 *
 * \param format 格式。
 * \param ...    参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStdoutA(
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...
);

/**
 * \brief 格式化写入标准输出流，Simplify 接口，Unicode 适配。
 *
 * \param format 格式。
 * \param ...    参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStdoutW(
    _In_z_ _Printf_format_string_ LPCWSTR format,
    ...
);

#ifdef _UNICODE
# define PrintfStdout PrintfStdoutW
#else
# define PrintfStdout PrintfStdoutA
#endif

/**
 * \brief 格式化写入标准错误流，Simplify 接口，ANSI 适配。
 *
 * \param format 格式。
 * \param ...    参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStderrA(
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...
);

/**
 * \brief 格式化写入标准错误流，Simplify 接口，Unicode 适配。
 *
 * \param format 格式。
 * \param ...    参数。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPIV
PrintfStderrW(
    _In_z_ _Printf_format_string_ LPCSTR format,
    ...
);

#ifdef _UNICODE
# define PrintfStderr PrintfStderrW
#else
# define PrintfStderr PrintfStderrA
#endif

#ifdef __cplusplus
}
#endif

/*------------------------------------------------------------------------------
 * 清空控制台及其简化
 */

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 清空控制台屏幕。
 *
 * \param hConsoleOutput 控制台句柄。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ClearConsoleScreen(
    _In_ HANDLE hConsoleOutput);

#ifdef __cplusplus
}
#endif

/**
 * \brief 清空标准输出流屏幕，Simplify 接口。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
ClearStdoutScreen(VOID)
{
    HANDLE outHdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (outHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return ClearConsoleScreen(outHdl);
}

/**
 * \brief 清空标准错误流屏幕，Simplify 接口。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
ClearStderrScreen(VOID)
{
    HANDLE errHdl = GetStdHandle(STD_ERROR_HANDLE);
    if (errHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return ClearConsoleScreen(errHdl);
}

#ifdef _UNICODE
# define WriteStdout WriteStdoutW
#else
# define WriteStdout WriteStdoutA
#endif
