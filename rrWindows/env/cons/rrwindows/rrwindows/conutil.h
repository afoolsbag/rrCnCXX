/*===-- Console Utilities --------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 控制台工具。
 *
 * \version 2018-06-07
 * \since 2018-04-14
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"

/**
 * \brief 控制台颜色。
 */
enum ConsoleColor {
    Black = 0x0, Blue = 0x1, Green = 0x2, Aqua = 0x3,
    Red = 0x4, Purple = 0x5, Yellow = 0x6, White = 0x7,
    Gray = 0x8, LightBlue = 0x9, LightGreen = 0xA, LightAqua = 0xB,
    LightRed = 0xC, LightPurple = 0xD, LightYellow = 0xE, BrightWhite = 0xF
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 获取控制台背景色。
 */
RRWINDOWS_API FORCEINLINE enum ConsoleColor WINAPI_INLINE
GetConsoleBackGroundColor(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput) return Black;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return Black;
    return (enum ConsoleColor)((csbi.wAttributes & 0x00F0) >> 4);
}

/**
 * \brief 获取控制台前景色。
 */
RRWINDOWS_API FORCEINLINE enum ConsoleColor WINAPI_INLINE
GetConsoleForeGroundColor(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput) return White;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(stdOutput, &csbi)) return White;
    return (enum ConsoleColor)(csbi.wAttributes & 0x000F);
}

/**
 * \brief 设定控制台颜色。
 *
 * \param backGroundColor 背景色。
 * \param foreGroundColor 前景色。
 */
RRWINDOWS_API VOID WINAPI
SetConsoleColor(
    _In_ CONST enum ConsoleColor backGroundColor,
    _In_ CONST enum ConsoleColor foreGroundColor);

/**
 * \brief 设定控制台背景色。
 */
RRWINDOWS_API VOID WINAPI
SetConsoleBackGroundColor(
    _In_ CONST enum ConsoleColor backGroundColor);

/**
 * \brief 设定控制台前景色。
 *
 * \param foreGroundColor 前景色。
 */
RRWINDOWS_API VOID WINAPI
SetConsoleForeGroundColor(
    _In_ CONST enum ConsoleColor foreGroundColor);

/**
 * \brief 控制台打印有色字串（ANSI适配）。
 */
RRWINDOWS_API VOID WINAPIV
ConsoleColorPrintA(
    _In_                           CONST enum ConsoleColor textColor,
    _In_z_ _Printf_format_string_ LPCSTR CONST             format,
    ...);

/**
 * \brief 控制台打印有色字串（UNICODE适配）。
 */
RRWINDOWS_API VOID WINAPIV
ConsoleColorPrintW(
    _In_                            CONST enum ConsoleColor textColor,
    _In_z_ _Printf_format_string_ LPCWSTR CONST             format,
    ...);

#ifdef _UNICODE
# define ConsoleColorPrint ConsoleColorPrintW
#else
# define ConsoleColorPrint ConsoleColorPrintA
#endif

/** \brief 控制台打印有色字串（缩写）。 */
#define ConColPrt ConsoleColorPrint

/**
 * \brief 清空控制台屏幕（ANSI适配）。
 */
RRWINDOWS_API VOID WINAPI
ClearConsoleScreenA(VOID);

/**
 * \brief 清空控制台屏幕（UNICODE适配）。
 */
RRWINDOWS_API VOID WINAPI
ClearConsoleScreenW(VOID);

#ifdef _UNICODE
# define ClearConsoleScreen ClearConsoleScreenW
#else
# define ClearConsoleScreen ClearConsoleScreenA
#endif

#ifdef __cplusplus
}
#endif
