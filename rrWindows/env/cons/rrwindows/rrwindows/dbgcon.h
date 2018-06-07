/*===-- Debug Console ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试控制台。
 *
 * \version 2018-06-06
 * \since 2018-04-18
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"
#include "conutil.h"

#ifdef __cplusplus
# include <typeinfo>
# include "rrwindows/sysmsgstr.h"

extern "C" {
#endif

#if ! defined _DEBUG
# define DebugConsolePrint(x) ((void)0)
#elif defined _UNICODE
# define DebugConsolePrint ConsoleColorPrintW
#else
# define DebugConsolePrint ConsoleColorPrintA
#endif
/** \brief 调试控制台打印有色字串（缩写）。 */
#define DbgConPrt DebugConsolePrint

#ifdef _DEBUG
# define NewDebugConsole() do{AllocConsole();}while(0)
#else
# define NewDebugConsole() ((void)0)
#endif
/** \brief 新建调试控制台（缩写）。 */
#define NewDbgCon NewDebugConsole

#ifdef _DEBUG
# define DeleteDebugConsole() do{FreeConsole();}while(0)
#else
# define DeleteDebugConsole() ((void)0)
#endif
/** \brief 删除调试控制台（缩写）。 */
#define DelDbgCon DeleteDebugConsole

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/** \brief 调试控制台打印（当前）方法。 */
# define DbgConPrtMeth(color)\
    do{\
        DbgConPrt(color, TEXT("%s::"), typeid(*this).name()+6);\
        DbgConPrt(static_cast<ConsoleColor>(color+0x8), TEXT("%s\n"), TEXT(__func__));\
    }while(0)
/** \brief 调试控制台打印（当前）`CmdMsg`方法。 */
# define DbgConPrtMethCmdMsg(color)\
    do{\
        DbgConPrt(color, TEXT("%s::"), typeid(*this).name()+6);\
        DbgConPrt(static_cast<ConsoleColor>(color+0x8), TEXT("%s %u with %d, 0x%p, 0x%p\n"), TEXT(__func__), nID, nCode, pExtra, pHandlerInfo);\
    }while(0)
/** \brief 调试控制台打印（当前）`WndMsg`方法。 */
# define DbgConPrtMethWndMsg(color)\
    do{\
        DbgConPrt(color, TEXT("%s::%s 0x%04X(%s), with %u, %ld, 0x%p\n"), typeid(*this).name()+6, TEXT(__func__), message, SysMsgStr(message), wParam, lParam, pResult);\
    }while(0)
#else
# define DbgConPrtMeth(x)       ((void)0)
# define DbgConPrtMethCmdMsg(x) ((void)0)
# define DbgConPrtMethWndMsg(x) ((void)0)
#endif
