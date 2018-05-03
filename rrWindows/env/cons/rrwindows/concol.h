/*===-- Console Color ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 控制台颜色。
 *
 * \version 2018-05-03
 * \since 2018-04-14
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "api.h"

/** \brief 控制台颜色。 */
enum ConsoleColor {
    Black = 0x0, Blue = 0x1, Green = 0x2, Aqua = 0x3,
    Red = 0x4, Purple = 0x5, Yellow = 0x6, White = 0x7,
    Gray = 0x8, LightBlue = 0x9, LightGreen = 0xA, LightAqua = 0xB,
    LightRed = 0xC, LightPurple = 0xD, LightYellow = 0xE, BrightWhite = 0xF
};
/** \brief 控制台颜色（缩写）。 */
typedef enum ConsoleColor ConCol;

# ifdef __cplusplus
extern "C" {
# endif

/** \brief 获取控制台背景色。 */
RRWINDOWS_API ConCol WINAPI
GetConsoleBackGroundColor(VOID);
/** \brief 获取控制台背景色（缩写）。 */
#define GetConBgCol GetConsoleBackGroundColor

/** \brief 获取控制台前景色。 */
RRWINDOWS_API ConCol WINAPI
GetConsoleForeGroundColor(VOID);
/** \brief 获取控制台前景色（缩写）。 */
#define GetConFgCol GetConsoleForeGroundColor

/** \brief 设定控制台颜色。 */
RRWINDOWS_API VOID WINAPI
SetConsoleColor(
    _In_ CONST ConCol backGroundColor,
    _In_ CONST ConCol foreGroundColor);
/** \brief 设定控制台颜色（缩写）。 */
#define SetConCol SetConsoleColor

/** \brief 设定控制台背景色。 */
RRWINDOWS_API VOID WINAPI
SetConsoleBackGroundColor(
    _In_ CONST ConCol backGroundColor);
/** \brief 设定控制台背景色（缩写）。 */
#define SetConBgCol SetConsoleBackGroundColor

/** \brief 设定控制台前景色。 */
RRWINDOWS_API VOID WINAPI
SetConsoleForeGroundColor(
    _In_ CONST ConCol foreGroundColor);
/** \brief 设定控制台前景色（缩写）。 */
#define SetConFgCol SetConsoleForeGroundColor

#ifdef __cplusplus
}
#endif
