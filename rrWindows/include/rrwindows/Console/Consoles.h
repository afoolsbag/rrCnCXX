/*===-- Consoles -----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 控制台。
 *
 * \version 2019-02-20
 * \since 2018-04-14
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/macros.h"

/**
 * \brief 控制台颜色。
 */
typedef
enum ConsoleColor {
    Black = 0x0, Blue = 0x1, Green = 0x2, Aqua = 0x3,
    Red = 0x4, Purple = 0x5, Yellow = 0x6, White = 0x7,
    Gray = 0x8, LightBlue = 0x9, LightGreen = 0xA, LightAqua = 0xB,
    LightRed = 0xC, LightPurple = 0xD, LightYellow = 0xE, BrightWhite = 0xF
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
 * \brief 控制台放置有色字串（ANSI 适配）。
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
 * \brief 控制台放置有色字串（UNICODE 适配）。
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
    ConsoleColorPut(White, text);
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
                                      ConsoleColorPut10)(__VA_ARGS__)

/**
 * \brief 控制台打印有色字串（ANSI 适配）。
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
 * \brief 控制台打印有色字串（UNICODE 适配）。
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
 * \brief 清空控制台屏幕（ANSI适配）。
 */
RRWINDOWS_API
VOID
WINAPI
ClearConsoleScreenA(VOID);

/**
 * \brief 清空控制台屏幕（UNICODE适配）。
 */
RRWINDOWS_API
VOID
WINAPI
ClearConsoleScreenW(VOID);

#ifdef _UNICODE
# define ClearConsoleScreen ClearConsoleScreenW
#else
# define ClearConsoleScreen ClearConsoleScreenA
#endif

#ifdef __cplusplus
}
#endif
