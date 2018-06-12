/*===-- Debug Console ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试控制台。
 *
 * \version 2018-06-11
 * \since 2018-04-18
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"
#include "conutil.h"

#ifdef __cplusplus
extern "C" {
#endif

#if ! defined _DEBUG
# define DebugConsolePut(...) ((void)0)
#elif defined _UNICODE
# define DebugConsolePut ConsoleColorPutW
#else
# define DebugConsolePut ConsoleColorPutA
#endif
/** \brief 调试控制台放置有色字串（缩写）。 */
#define DbgConPut DebugConsolePut

#if ! defined _DEBUG
# define DebugConsolePrint(...) ((void)0)
#elif defined _UNICODE
# define DebugConsolePrint ConsoleColorPrintW
#else
# define DebugConsolePrint ConsoleColorPrintA
#endif
/** \brief 调试控制台打印有色字串（缩写）。 */
#define DbgConPrt DebugConsolePrint

#ifdef _DEBUG
# define NewDebugConsole AllocConsole
#else
# define NewDebugConsole(...) ((void)0)
#endif

#ifdef _DEBUG
# define DeleteDebugConsole FreeConsole
#else
# define DeleteDebugConsole(...) ((void)0)
#endif

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
# include "rrwindows/sysmsgstr.h"
/** \brief 调试控制台打印当前方法。 */
# define DbgConMeth()           DebugConsolePut(Gray, _T(__FUNCTION__) _T("\n"))
/** \brief 调试控制台打印当前方法（指定颜色）。 */
# define DbgConMethCol(color)   DebugConsolePut(color, _T(__FUNCTION__) _T("\n"))
/** \brief 调试控制台打印当前`CmdMsg`方法。 */
# define DbgConCmdMsg()         DebugConsolePrint(Gray, _T("%s %u with %d, 0x%p, 0x%p\n"), _T(__FUNCTION__), nID, nCode, pExtra, pHandlerInfo)
/** \brief 调试控制台打印当前`CmdMsg`方法（指定颜色）。 */
# define DbgConCmdMsgCol(color) DebugConsolePrint(color, _T("%s %u with %d, 0x%p, 0x%p\n"), _T(__FUNCTION__), nID, nCode, pExtra, pHandlerInfo)
/** \brief 调试控制台打印当前`WndMsg`方法。 */
# define DbgConWndMsg()         DebugConsolePrint(Gray, _T("%s 0x%04X(%s), with %u, %ld, 0x%p\n"), _T(__FUNCTION__), message, SysMsgStr(message), wParam, lParam, pResult)
/** \brief 调试控制台打印当前`WndMsg`方法（指定颜色）。 */
# define DbgConWndMsgCol(color) DebugConsolePrint(color, _T("%s 0x%04X(%s), with %u, %ld, 0x%p\n"), _T(__FUNCTION__), message, SysMsgStr(message), wParam, lParam, pResult)
#endif
