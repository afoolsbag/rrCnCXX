/*===-- Debug Console ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试控制台。
 *
 * \version 2018-04-25
 * \since 2018-04-18
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#ifdef DEBUG
# include "api.h"
# include "concol.h"

# ifdef __cplusplus
extern "C" {
# endif

RRMFC_UTILITIES_API VOID WINAPI
_NewDebugConsole(
    _In_                          CONST ConCol  textColor,
    _In_z_ _Printf_format_string_ CONST LPCTSTR format,
    ...);

RRMFC_UTILITIES_API VOID WINAPI
_DeleteDebugConsole(
    _In_                          CONST ConCol  textColor,
    _In_z_ _Printf_format_string_ CONST LPCTSTR format,
    ...);

RRMFC_UTILITIES_API VOID WINAPI
_DebugConsolePrint(
    _In_                          CONST ConCol  textColor,
    _In_z_ _Printf_format_string_ CONST LPCTSTR format,
    ...);

RRMFC_UTILITIES_API VOID WINAPI
_DebugConsolePrintWindowMessage(
    _In_   CONST ConCol  textColor,
    _In_z_ CONST LPCTSTR prefix,
    _In_   CONST UINT    message,
    _In_   CONST WPARAM  wParam,
    _In_   CONST LPARAM  lParam,
    _In_   CONST PVOID   pResult);

RRMFC_UTILITIES_API VOID WINAPI
_DebugConsolePrintCommandMessage(
    _In_   CONST ConCol  textColor,
    _In_z_ CONST LPCTSTR prefix,
    _In_   CONST UINT    nID,
    _In_   CONST INT     nCode,
    _In_   CONST PVOID   pExtra,
    _In_   CONST PVOID   pHandlerInfo);

# ifdef __cplusplus
}
# endif

/** \brief 创建调试控制台。 */
# define NewDebugConsole                 _NewDebugConsole
/** \brief 删除调试控制台。 */
# define DeleteDebugConsole              _DeleteDebugConsole
/** \brief 调试控制台打印格式化字串。 */
# define DebugConsolePrint               _DebugConsolePrint
/** \brief 调试控制台打印窗口消息。 */
# define DebugConsolePrintWindowMessage  _DebugConsolePrintWindowMessage
/** \brief 调试控制台打印命令消息。 */
# define DebugConsolePrintCommandMessage _DebugConsolePrintCommandMessage
#else//DEBUG
# define NewDebugConsole(x)                 ((void)0)
# define DeleteDebugConsole(x)              ((void)0)
# define DebugConsolePrint(x)               ((void)0)
# define DebugConsolePrintWindowMessage(x)  ((void)0)
# define DebugConsolePrintCommandMessage(x) ((void)0)
#endif//DEBUG

/** \brief 创建调试控制台（缩写）。 */
#define NewDbgCon       NewDebugConsole
/** \brief 删除调试控制台（缩写）。 */
#define DelDbgCon       DeleteDebugConsole
/** \brief 调试控制台打印格式化字串（缩写）。 */
#define DbgConPrt       DebugConsolePrint
/** \brief 调试控制台打印窗口消息（缩写）。 */
#define DbgConPrtWndMsg DebugConsolePrintWindowMessage
/** \brief 调试控制台打印命令消息（缩写）。 */
#define DbgConPrtCmdMsg DebugConsolePrintCommandMessage
