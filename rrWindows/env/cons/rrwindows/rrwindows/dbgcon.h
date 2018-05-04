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

#include <assert.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"
#include "concol.h"

#ifdef __cplusplus
# include <typeinfo>
# include "rrwindows/sysmsgstr.h"

extern "C" {
#endif

/**
 * \brief 调试控制台打印有色字串（ANSI适配）。
 */
RRWINDOWS_API VOID WINAPIV
DebugConsolePrintA(
    _In_                          CONST ConCol textColor,
    _In_z_ _Printf_format_string_ CONST LPCSTR format,
    ...);

/**
 * \brief 调试控制台打印有色字串（UNICODE适配）。
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
/** \brief 调试控制台打印有色字串（缩写）。 */
#define DbgConPrt DebugConsolePrint

#ifdef DEBUG
# define NewDebugConsole() do{AllocConsole();}while(0)
#else
# define NewDebugConsole() ((void)0)
#endif
/** \brief 新建调试控制台（缩写）。 */
#define NewDbgCon NewDebugConsole

#ifdef DEBUG
# define DeleteDebugConsole() do{FreeConsole();}while(0)
#else
# define DeleteDebugConsole() ((void)0)
#endif
/** \brief 删除调试控制台（缩写）。 */
#define DelDbgCon DeleteDebugConsole

// 便利宏
#ifdef __cplusplus
# define DbgConPrtMeth(color) \
    do{\
        DbgConPrt(color, TEXT("%s::"), typeid(*this).name()+6);\
        DbgConPrt(static_cast<ConsoleColor>(color+0x8), TEXT("%s\n"), TEXT(__func__));\
    }while(0)
# define DbgConPrtMethCmdMsg(color) \
    do{\
        DbgConPrt(color, TEXT("%s::"), typeid(*this).name()+6);\
        DbgConPrt(static_cast<ConsoleColor>(color+0x8), TEXT("%s %u with %d, 0x%p, 0x%p\n"), TEXT(__func__), nID, nCode, pExtra, pHandlerInfo);\
    }while(0)
# define DbgConPrtMethWndMsg(color) \
    do{\
        DbgConPrt(color, TEXT("%s::%s 0x%04X(%s), with %u, %ld, 0x%p\n"), typeid(*this).name()+6, TEXT(__func__), message, SysMsgStr(message), wParam, lParam, pResult);\
    }while(0)
#else
# define DbgConPrtMeth(x)       ((void)0)
# define DbgConPrtMethCmdMsg(x) ((void)0)
# define DbgConPrtMethWndMsg(x) ((void)0)
#endif

#ifdef __cplusplus
}
#endif
