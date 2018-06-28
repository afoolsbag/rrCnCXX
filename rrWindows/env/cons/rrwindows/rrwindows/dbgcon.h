/*===-- Debug Console ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试控制台。
 *
 * \version 2018-06-28
 * \since 2018-04-18
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrwindows/conutil.h"
#include "rrwindows/rrwindowsapi.h"

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
# include "rrwindows/sysmsgstr.h"
#
# define DckMeth(color) DckPut(color, _T(__FUNCTION__) _T("\n"))
# define DcMeth() DckMeth(Gray)
#
# define DckCmdMsg(color) DckPrint(color, _T("%s %u with %d, 0x%p, 0x%p\n"), _T(__FUNCTION__), nID, nCode, pExtra, pHandlerInfo)
# define DcCmdMsg() DckCmdMsg(Gray)
#
# define DckWndMsg(color) DckPrint(color, _T("%s 0x%04X(%s), with %u, %ld, 0x%p\n"), _T(__FUNCTION__), message, SysMsgStr(message), wParam, lParam, pResult)
# define DcWndMsg() DckWndMsg(Gray)
#endif
