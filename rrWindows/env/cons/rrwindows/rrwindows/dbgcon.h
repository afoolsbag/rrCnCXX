/*===-- Debug Console ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试控制台。
 *
 * \version 2018-05-04
 * \since 2018-04-18
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"
#include "concol.h"

# ifdef __cplusplus
extern "C" {
# endif

/**
 * \brief 输出指定颜色字串到控制台（ANSI适配）。
 */
RRWINDOWS_API VOID WINAPIV
DebugConsolePrintA(
    _In_                          CONST ConCol textColor,
    _In_z_ _Printf_format_string_ CONST LPCSTR format,
    ...);

/**
 * \brief 输出指定颜色字串到控制台（UNICODE适配）。
 */
RRWINDOWS_API VOID WINAPIV
DebugConsolePrintW(
    _In_                          CONST ConCol  textColor,
    _In_z_ _Printf_format_string_ CONST LPCWSTR format,
    ...);

#if ! defined DEBUG
# define DebugConsolePrint(x) ((void)0)
#elif defined UNICODE
# define DebugConsolePrint DebugConsolePrintW
#else
# define DebugConsolePrint DebugConsolePrintA
#endif

/**
 * \brief 输出指定颜色字串到控制台（缩写）。
 */
#define DbgConPrt DebugConsolePrint

/**
 * \brief 合并两行的、输出指定颜色字串到控制台。
 */
#define DebugConsolePrintDouble(preColor, preString, ctxColor, ...)\
    do{DbgConPrt(preColor, preString);DbgConPrt(ctxColor, __VA_ARGS__);}while(0)

/**
 * \brief 合并两行的、输出指定颜色字串到控制台（缩写）。
 */
#define DbgConPrtDbl DebugConsolePrintDouble

#ifdef DEBUG
# define NewDebugConsole() do{AllocConsole();}while(0)
#else
# define NewDebugConsole() ((void)0)
#endif

/**
 * \brief 创建调试控制台（缩写）。
 */
#define NewDbgCon NewDebugConsole

#ifdef DEBUG
# define DeleteDebugConsole() do{FreeConsole();}while(0)
#else
# define DeleteDebugConsole() ((void)0)
#endif

/**
 * \brief 删除调试控制台（缩写）。
 */
#define DelDbgCon DeleteDebugConsole

# ifdef __cplusplus
}
# endif
