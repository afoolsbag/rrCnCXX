/*===-- Debug Console ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试控制台。
 *
 * \version 2018-08-24
 * \since 2018-04-18
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrwindows/env/conutil.h"
#include "rrwindows/api.h"

/*-Debug-Console-Basic--------------------------------------------------------*/

#ifdef _DEBUG
# /** \brief 分配调试控制台。 */
# define DcAlloc  AllocConsole
# /** \brief 释放调试控制台。 */
# define DcFree   FreeConsole
# /** \brief 调试控制台放置有色字串。 */
# define DcKPut   ConsoleColorPut
# /** \brief 调试控制台打印有色字串。 */
# define DcKPrint ConsoleColorPrint
#
#else
# define DcAlloc(...)  ((void)0)
# define DcFree(...)   ((void)0)
# define DcKPut(...)   ((void)0)
# define DcKPrint(...) ((void)0)
#
#endif

/*-Debug-Console-Extended-----------------------------------------------------*/

#ifdef __cplusplus
# include "rrwindows/dtpui/syscodestr.h"
#
# define DcKMeth(color) DcKPut(color, _T(__FUNCTION__) _T("\n"))
# define DcMeth() DcKMeth(Gray)
#
# define DcKCmdMsg(color)                                                      \
      DcKPrint(color,                                                          \
               _T(__FUNCTION__) _T(" %6u(%s) nC=%d(%s) pE=0x%p, pHI=0x%p\n"),  \
               nID,                                                            \
               SystemCommandString(nID),                                       \
               nCode,                                                          \
               SystemCommandNotificationString(nCode),                         \
               pExtra,                                                         \
               pHandlerInfo)
# define DcCmdMsg() DcKCmdMsg(Gray)
#
# define DcKWndMsg(color)                                                      \
      DcKPrint(color,                                                          \
               _T(__FUNCTION__) _T(" 0x%04X(%s) wP=%u, lP=%ld, pR=0x%p\n"),    \
               message,                                                        \
               SystemMessageString(message),                                   \
               wParam,                                                         \
               lParam,                                                         \
               pResult)
# define DcWndMsg() DcKWndMsg(Gray)
#endif
