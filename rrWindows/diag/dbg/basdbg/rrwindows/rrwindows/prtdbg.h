/*===-- Print Debug --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gPrtDbg 打印调试
 * \ingroup gBasDbg
 *
 * \version 2018-06-09
 * \since 2018-05-26
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 打印调试字串（ANSI适配）。
 * \warning 预设的缓存尺寸可能不足。
 */
RRWINDOWS_API VOID WINAPIV
PrintDebugStringA(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...);

/**
 * \brief 打印调试字串（UNICODE适配）。
 * \warning 预设的缓存尺寸可能不足。
 */
RRWINDOWS_API VOID WINAPIV
PrintDebugStringW(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...);

#ifdef _UNICODE
# define PrintDebugString PrintDebugStringW
#else
# define PrintDebugString PrintDebugStringA
#endif

#ifdef __cplusplus
}
#endif

#ifdef _DEBUG
 /**
  * \brief 调试打印字串（调试适配）。
  * \details 形如`path/to/file.c(1337): ... @F.\\n`
  */
# define DebugPrint(format, ...) PrintDebugString(_T("%s(%d): ") format _T(" @%s.\n"), _T(__FILE__), __LINE__, __VA_ARGS__, _T(__FUNCTION__))
#else
 /**
  * \brief 调试打印字串（发布适配）。
  * \details 形如`... @F.\\n`
  */
# define DebugPrint(format, ...) PrintDebugString(format _T(" @%s.\n"), __VA_ARGS__, _T(__FUNCTION__))
#endif

#define DEBUG_PRINT_OFF     0  /* 禁用调试输出。 */
#define DEBUG_PRINT_FATAL   1  /* 致命错误，程序随时可能终止。应尽快保存数据、整理日志、警告报告、重启自检、尝试修复。 */
#define DEBUG_PRINT_ERROR   2  /* 逻辑错误，不应路由至此，设计无此状态。虽无崩溃之虞，但程序已脱离掌控，应引导用户恰当处理。 */
#define DEBUG_PRINT_WARN    3  /* 危险警告，该操作可能损害用户数据、或造成其它不可恢复的后果。 */
#define DEBUG_PRINT_INFO    4  /* 有用信息，如数据统计（以评估需求）、用户行为（以改进交互）、处理消耗（以优化性能）等。 */
#define DEBUG_PRINT_DEBUG   5  /* 调试信息，以追踪流程。 */
#define DEBUG_PRINT_TRACE   6  /* 跟踪信息，以追踪细节。 */
#define DEBUG_PRINT_ALL     7  /* 启用所有级别调试输出。 */
#define DEBUG_PRINT_DEFAULT DEBUG_PRINT_INFO  /* 默认调试输出级别。 */
#ifndef DEBUG_PRINT_LEVEL
#define DEBUG_PRINT_LEVEL DEBUG_PRINT_DEFAULT  /* 调试输出级别。 */
#endif

#if DEBUG_PRINT_FATAL <= DEBUG_PRINT_LEVEL
# define DpFatal(format, ...) DebugPrint(_T("Fatal: ") format, __VA_ARGS__)
#else
# define DpFatal(...) ((void)0)
#endif
#if DEBUG_PRINT_ERROR <= DEBUG_PRINT_LEVEL
# define DpError(format, ...) DebugPrint(_T("Error: ") format, __VA_ARGS__)
#else
# define DpError(...) ((void)0)
#endif
#if DEBUG_PRINT_WARN <= DEBUG_PRINT_LEVEL
# define DpWarn(format, ...) DebugPrint(_T("Warn: ") format, __VA_ARGS__)
#else
# define DpWarn(...) ((void)0)
#endif
#if DEBUG_PRINT_INFO <= DEBUG_PRINT_LEVEL
# define DpInfo(format, ...) DebugPrint(_T("Info: ") format, __VA_ARGS__)
#else
# define DpInfo(...) ((void)0)
#endif
#if DEBUG_PRINT_DEBUG <= DEBUG_PRINT_LEVEL
# define DpDebug(format, ...) DebugPrint(_T("Debug: ") format, __VA_ARGS__)
#else
# define DpDebug(...) ((void)0)
#endif
#if DEBUG_PRINT_TRACE <= DEBUG_PRINT_LEVEL
# define DpTrace(format, ...) DebugPrint(_T("Trace: ") format, __VA_ARGS__)
#else
# define DpTrace(...) ((void)0)
#endif

/** \brief 调试打印函数名、函数修饰名和函数签名。 */
#define DpFunc() DpTrace(_T("Function name \"%s\", decorated name \"%s\", signature \"%s\"."), _T(__FUNCTION__), _T(__FUNCDNAME__), _T(__FUNCSIG__))

/** @} */
