/*===-- Debug Console ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试控制台。
 *
 * \version 2018-06-29
 * \since 2018-04-18
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrWindows/env/cons/conutil.h"
#include "rrWindows/rrwindowsapi.h"

/**
 * \brief 分配调试控制台。
 */
#ifdef _DEBUG
# define AllocDebugConsole AllocConsole
#else
# define AllocDebugConsole(...) ((void)0)
#endif

/**
 * \brief 释放调试控制台。
 */
#ifdef _DEBUG
# define FreeDebugConsole FreeConsole
#else
# define FreeDebugConsole(...) ((void)0)
#endif

/**
 * \brief 调试控制台放置有色字串（Debug-Console C(K)olor Put）。
 */
#ifdef _DEBUG
# define DckPut ConsoleColorPut
#else
# define DckPut(...) ((void)0)
#endif

/**
 * \brief 调试控制台打印有色字串（Debug-Console C(K)olor Print）。
 */
#ifdef _DEBUG
# define DckPrint ConsoleColorPrint
#else
# define DckPrint(...) ((void)0)
#endif

#ifdef __cplusplus
# include "rrwindows/syscodestr.h"
#
# define DckMeth(color) DckPut(color, _T(__FUNCTION__) _T("\n"))
# define DcMeth() DckMeth(Gray)
#
# define DckCmdMsg(color) DckPrint(color, _T(__FUNCTION__) _T(" %6u(%s) nC=%d(%s) pE=0x%p, pHI=0x%p\n"), nID, SystemCommandString(nID), nCode, SystemCommandNotificationString(nCode), pExtra, pHandlerInfo)
# define DcCmdMsg() DckCmdMsg(Gray)
#
# define DckWndMsg(color) DckPrint(color, _T(__FUNCTION__) _T(" 0x%04X(%s) wP=%u, lP=%ld, pR=0x%p\n"), message, SystemMessageString(message), wParam, lParam, pResult)
# define DcWndMsg() DckWndMsg(Gray)
#endif
