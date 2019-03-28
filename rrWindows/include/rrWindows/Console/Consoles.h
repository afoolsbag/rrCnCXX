/*===-- Consoles -----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 控制台。
 *
 * \version 2019-02-21
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
 * 简化函数
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
    HANDLE outHdl = GetStdHandle(STD_OUTPUT_HANDLE);
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
    HANDLE outHdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (outHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return WriteConsoleW(outHdl, text, (DWORD)StringCchLengthSW(text), NULL, NULL);
}

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
    HANDLE errHdl = GetStdHandle(STD_ERROR_HANDLE);
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
    HANDLE errHdl = GetStdHandle(STD_ERROR_HANDLE);
    if (errHdl == INVALID_HANDLE_VALUE)
        return FALSE;
    return WriteConsoleW(errHdl, text, (DWORD)StringCchLengthSW(text), NULL, NULL);
}

#ifdef _UNICODE
# define WriteStderrS WriteStderrW
#else
# define WriteStderrS WriteStderrA
#endif

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

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 获取控制台背景色。
 */
RRWINDOWS_API
ConsoleColor
WINAPI
GetConsoleBackGroundColor(VOID);

/**
 * \brief 获取控制台前景色。
 */
RRWINDOWS_API
ConsoleColor
WINAPI
GetConsoleForeGroundColor(VOID);

/**
 * \brief 设定控制台颜色。
 *
 * \param backGroundColor 背景色。
 * \param foreGroundColor 前景色。
 */
RRWINDOWS_API
VOID
WINAPI
SetConsoleColor(
    _In_ CONST ConsoleColor backGroundColor,
    _In_ CONST ConsoleColor foreGroundColor
);

/**
 * \brief 设定控制台背景色。
 *
 * \param backGroundColor 背景色。
 */
RRWINDOWS_API
VOID
WINAPI
SetConsoleBackGroundColor(
    _In_ CONST ConsoleColor backGroundColor
);

/**
 * \brief 设定控制台前景色。
 *
 * \param foreGroundColor 前景色。
 */
RRWINDOWS_API
VOID
WINAPI
SetConsoleForeGroundColor(
    _In_ CONST ConsoleColor foreGroundColor
);

/**
 * \brief 控制台放置有色字串，ANSI 适配。
 *
 * \param color 颜色。
 * \param text  字串。
 */
RRWINDOWS_API
VOID
WINAPI
ConsoleColorPutA(
    _In_    CONST ConsoleColor color,
    _In_z_ LPCSTR CONST        text
);

/**
 * \brief 控制台放置有色字串，Unicode 适配。
 *
 * \param color 颜色。
 * \param text  字串。
 */
RRWINDOWS_API
VOID
WINAPI
ConsoleColorPutW(
    _In_     CONST ConsoleColor color,
    _In_z_ LPCWSTR CONST        text
);

#ifdef _UNICODE
# define ConsoleColorPut ConsoleColorPutW
#else
# define ConsoleColorPut ConsoleColorPutA
#endif

FORCEINLINE
VOID
WINAPI_INLINE
ConsoleColorPut1(
    _In_z_ LPCTSTR CONST text)
{
    ConsoleColorPut(ConsoleWhite, text);
}

FORCEINLINE
VOID
WINAPI_INLINE
ConsoleColorPut2(
    _In_     CONST ConsoleColor color,
    _In_z_ LPCTSTR CONST        text)
{
    ConsoleColorPut(color, text);
}

FORCEINLINE
VOID
WINAPI_INLINE
ConsoleColorPut4(
    _In_     CONST ConsoleColor color,
    _In_z_ LPCTSTR CONST        text,
    _In_     CONST ConsoleColor color2,
    _In_z_ LPCTSTR CONST        text2)
{
    ConsoleColorPut(color, text);
    ConsoleColorPut(color2, text2);
}

FORCEINLINE
VOID
WINAPI_INLINE
ConsoleColorPut6(
    _In_     CONST ConsoleColor color,
    _In_z_ LPCTSTR CONST        text,
    _In_     CONST ConsoleColor color2,
    _In_z_ LPCTSTR CONST        text2,
    _In_     CONST ConsoleColor color3,
    _In_z_ LPCTSTR CONST        text3)
{
    ConsoleColorPut(color, text);
    ConsoleColorPut(color2, text2);
    ConsoleColorPut(color3, text3);
}

FORCEINLINE
VOID
WINAPI_INLINE
ConsoleColorPut8(
    _In_     CONST ConsoleColor color,
    _In_z_ LPCTSTR CONST        text,
    _In_     CONST ConsoleColor color2,
    _In_z_ LPCTSTR CONST        text2,
    _In_     CONST ConsoleColor color3,
    _In_z_ LPCTSTR CONST        text3,
    _In_     CONST ConsoleColor color4,
    _In_z_ LPCTSTR CONST        text4)
{
    ConsoleColorPut(color, text);
    ConsoleColorPut(color2, text2);
    ConsoleColorPut(color3, text3);
    ConsoleColorPut(color4, text4);
}

FORCEINLINE
VOID
WINAPI_INLINE
ConsoleColorPut10(
    _In_     CONST ConsoleColor color,
    _In_z_ LPCTSTR CONST        text,
    _In_     CONST ConsoleColor color2,
    _In_z_ LPCTSTR CONST        text2,
    _In_     CONST ConsoleColor color3,
    _In_z_ LPCTSTR CONST        text3,
    _In_     CONST ConsoleColor color4,
    _In_z_ LPCTSTR CONST        text4,
    _In_     CONST ConsoleColor color5,
    _In_z_ LPCTSTR CONST        text5)
{
    ConsoleColorPut(color, text);
    ConsoleColorPut(color2, text2);
    ConsoleColorPut(color3, text3);
    ConsoleColorPut(color4, text4);
    ConsoleColorPut(color5, text5);
}

/**
 * \brief 控制台放置有色字串，宏函数变参重载。
 */
#define ConsoleColorPutV(...) MFVO_10(MFVO_BAN,                                \
                                      ConsoleColorPut1,                        \
                                      ConsoleColorPut2,                        \
                                      MFVO_BAN,                                \
                                      ConsoleColorPut4,                        \
                                      MFVO_BAN,                                \
                                      ConsoleColorPut6,                        \
                                      MFVO_BAN,                                \
                                      ConsoleColorPut8,                        \
                                      MFVO_BAN,                                \
                                      ConsoleColorPut10, __VA_ARGS__)

/**
 * \brief 控制台打印有色字串，ANSI 适配。
 *
 * \param color  颜色。
 * \param format 格式。
 * \param ...    参数。
 */
RRWINDOWS_API
VOID
WINAPIV
ConsoleColorPrintA(
    _In_                           CONST ConsoleColor color,
    _In_z_ _Printf_format_string_ LPCSTR CONST        format,
    ...
);

/**
 * \brief 控制台打印有色字串，Unicode 适配。
 *
 * \param color  颜色。
 * \param format 格式。
 * \param ...    参数。
 */
RRWINDOWS_API
VOID
WINAPIV
ConsoleColorPrintW(
    _In_                            CONST ConsoleColor color,
    _In_z_ _Printf_format_string_ LPCWSTR CONST        format,
    ...
);

#ifdef _UNICODE
# define ConsoleColorPrint ConsoleColorPrintW
#else
# define ConsoleColorPrint ConsoleColorPrintA
#endif

/**
 * \brief 清空控制台屏幕。
 */
RRWINDOWS_API
VOID
WINAPI
ClearConsoleScreen(VOID);

#ifdef __cplusplus
}
#endif
