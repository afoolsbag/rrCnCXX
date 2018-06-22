/*===-- Print Debug --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gPrtDbg 打印调试
 * \ingroup gBasDbg
 *
 * \version 2018-06-22
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

EXTERN_C_START

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

EXTERN_C_END

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
#define DEBUG_PRINT_FATAL   1  /* 致命，程序随时可能终止。应尽快保存数据，整理日志，通知用户，并重启、自检、尝试修复。 */
#define DEBUG_PRINT_ERROR   2  /* 错误，不应路由至此状态。虽无崩溃之虞，但程序已脱离掌控，应引导用户积极处理。 */
#define DEBUG_PRINT_WARN    3  /* 警告，损害功能或性能，如操作失败、资源缺乏、连接失败、权限不足等。 */
#define DEBUG_PRINT_INFO    4  /* 信息，有助于更新程序，如操作记录（评估需求）、行为记录（改进交互）、性能记录（优化性能）等。 */
#define DEBUG_PRINT_DEBUG   5  /* 调试，以追踪流程。 */
#define DEBUG_PRINT_TRACE   6  /* 跟踪，以追踪细节。 */
#define DEBUG_PRINT_ALL     7  /* 启用所有级别调试输出。 */

#ifdef _DEBUG
# define DEBUG_PRINT_DEFAULT DEBUG_PRINT_ALL
#else
# define DEBUG_PRINT_DEFAULT DEBUG_PRINT_INFO
#endif

#ifndef DEBUG_PRINT_LEVEL
#define DEBUG_PRINT_LEVEL DEBUG_PRINT_DEFAULT  /* 调试输出级别。 */
#endif

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_FATAL
# define DpFatal(...)         ((void)0)
#elif defined(_DEBUG)
# define DpFatal(format, ...) do{DebugPrint(_T("Fatal: ") format, __VA_ARGS__); __debugbreak();}while(0)
#else
# define DpFatal(format, ...) DebugPrint(_T("Fatal: ") format, __VA_ARGS__)
#endif
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_ERROR
# define DpError(...)         ((void)0)
#elif defined(_DEBUG)
# define DpError(format, ...) do{DebugPrint(_T("Error: ") format, __VA_ARGS__); __debugbreak();}while(0)
#else
# define DpError(format, ...) DebugPrint(_T("Error: ") format, __VA_ARGS__)
#endif
#if DEBUG_PRINT_WARN <= DEBUG_PRINT_LEVEL
# define DpWarn(format, ...)  DebugPrint(_T("Warn: ") format, __VA_ARGS__)
#else
# define DpWarn(...)          ((void)0)
#endif
#if DEBUG_PRINT_INFO <= DEBUG_PRINT_LEVEL
# define DpInfo(format, ...)  DebugPrint(_T("Info: ") format, __VA_ARGS__)
#else
# define DpInfo(...)          ((void)0)
#endif
#if DEBUG_PRINT_DEBUG <= DEBUG_PRINT_LEVEL
# define DpDebug(format, ...) DebugPrint(_T("Debug: ") format, __VA_ARGS__)
#else
# define DpDebug(...)         ((void)0)
#endif
#if DEBUG_PRINT_TRACE <= DEBUG_PRINT_LEVEL
# define DpTrace(format, ...) DebugPrint(_T("Trace: ") format, __VA_ARGS__)
#else
# define DpTrace(...)         ((void)0)
#endif

/** \brief 调试打印函数名、函数修饰名和函数签名。 */
#define DpTraceFunc() DpTrace(_T("Function name \"%s\", decorated name \"%s\", signature \"%s\"."), _T(__FUNCTION__), _T(__FUNCDNAME__), _T(__FUNCSIG__))

/** @} */
