/*===-- Debug Print --------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试打印。
 *
 * \version 2018-07-24
 * \since 2018-05-26
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrWindows/def.h"
#include "rrWindows/diag/dbg/basdbg/prtdbgstr.h"

/*-Debug-Print-Level----------------------------------------------------------*/

#define DEBUG_PRINT_OFF   0  /* 禁用调试打印。 */
#define DEBUG_PRINT_FATAL 1  /* 致命，程序随时可能终止。应尽快保存数据，整理日志，通知用户，并重启、自检、尝试修复。 */
#define DEBUG_PRINT_ERROR 2  /* 错误，不应路由至此状态。虽无崩溃之虞，但程序已脱离掌控，应引导用户积极处理。 */
#define DEBUG_PRINT_WARN  3  /* 警告，损害功能或性能，如操作失败、资源缺乏、连接失败、权限不足等。 */
#define DEBUG_PRINT_INFO  4  /* 信息，有助于更新程序，如操作记录（评估需求）、行为记录（改进交互）、性能记录（优化性能）等。 */
#define DEBUG_PRINT_DEBUG 5  /* 调试。 */
#define DEBUG_PRINT_TRACE 6  /* 追踪。 */
#define DEBUG_PRINT_ALL   7  /* 启用所有级别调试打印。 */

#ifndef DEBUG_PRINT_LEVEL
# ifdef _DEBUG
#  define DEBUG_PRINT_LEVEL DEBUG_PRINT_DEBUG
# else
#  define DEBUG_PRINT_LEVEL DEBUG_PRINT_INFO
# endif
#endif

/*-Debug-Print-Basic----------------------------------------------------------*/

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_FATAL
# define DpFatal(...)         ((void)0)
#elif defined(_DEBUG)
# define DpFatal(apdfmt, ...) do {                                             \
                              PrintDebugString(FILELINE _T("<%lu> Fatal: ") apdfmt ATFUNCNL, \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__);                   \
                              __debugbreak();                                  \
                              } while(0)
#else
# define DpFatal(apdfmt, ...) PrintDebugString(         _T("<%lu> Fatal: ") apdfmt _T("\n"), \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#endif

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_ERROR
# define DpError(...)         ((void)0)
#elif defined(_DEBUG)
# define DpError(apdfmt, ...) do {                                             \
                              PrintDebugString(FILELINE _T("<%lu> Error: ") apdfmt ATFUNCNL, \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__);                   \
                              __debugbreak();                                  \
                              } while(0)
#else
# define DpError(apdfmt, ...) PrintDebugString(         _T("<%lu> Error: ") apdfmt _T("\n"), \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#endif

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_WARN
# define DpWarn(...)          ((void)0)
#elif defined(_DEBUG)
# define DpWarn(apdfmt, ...)  PrintDebugString(FILELINE _T("<%lu> Warn: ") apdfmt ATFUNCNL, \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#else
# define DpWarn(apdfmt, ...)  PrintDebugString(         _T("<%lu> Warn: ") apdfmt _T("\n"), \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#endif

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_INFO
# define DpInfo(...)          ((void)0)
#elif defined(_DEBUG)
# define DpInfo(apdfmt, ...)  PrintDebugString(FILELINE _T("<%lu> Info: ") apdfmt ATFUNCNL, \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#else
# define DpInfo(apdfmt, ...)  PrintDebugString(         _T("<%lu> Info: ") apdfmt _T("\n"), \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#endif

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_DEBUG
# define DpDebug(...)         ((void)0)
#elif defined(_DEBUG)
# define DpDebug(apdfmt, ...) PrintDebugString(FILELINE _T("<%lu> Debug: ") apdfmt ATFUNCNL, \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#else
# define DpDebug(apdfmt, ...) PrintDebugString(         _T("<%lu> Debug: ") apdfmt _T("\n"), \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#endif

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_TRACE
# define DpTrace(...)         ((void)0)
#elif defined(_DEBUG)
# define DpTrace(apdfmt, ...) PrintDebugString(FILELINE _T("<%lu> Trace: ") apdfmt ATFUNCNL, \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#else
# define DpTrace(apdfmt, ...) PrintDebugString(         _T("<%lu> Trace: ") apdfmt _T("\n"), \
                                               GetCurrentThreadId(),           \
                                               __VA_ARGS__)
#endif

/*-Debug-Print-Extended-------------------------------------------------------*/

/**
 * \brief 调试打印错误：未知的（不预期的）Switch路由。
 */
#define DpErrorSwitchUnknown(expr) DpError(_T("Unknown switch-route with expression: ") _T(#expr) _T("=%I64d."), (INT64)(expr))

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_WARN
# define DpWarnFwLE(...)        ((void)0)
#elif defined(_DEBUG)
 /**
  * \brief 调试打印警告：失败和最后错误。
  *        Failed with Last Error.
  * \param opfmt 操作描述。
  * \since 2018-06-25
  */
# define DpWarnFwLE(opfmt, ...) PrintDebugString(FILELINE _T("<%lu> Warn: ") opfmt _T(" failed with error %lu: %s") ATFUNCNL, \
                                                 GetCurrentThreadId(),         \
                                                 __VA_ARGS__,                  \
                                                 GetLastError(),               \
                                                 GetLastErrorText())
#else
 /**
  * \brief 调试打印警告：失败和最后错误。
  *        Failed with Last Error.
  * \param opfmt 操作描述。
  * \since 2018-06-25
  */
# define DpWarnFwLE(opfmt, ...) PrintDebugString(         _T("<%lu> Warn: ") opfmt _T(" failed with error %lu: %s") _T("\n"), \
                                                 GetCurrentThreadId(),         \
                                                 __VA_ARGS__,                  \
                                                 GetLastError(),               \
                                                 GetLastErrorText())
#endif

#define DpDebugFunc() DpDebug(_T("Function name \"") _T(__FUNCTION__) _T("\", decorated name \"") _T(__FUNCDNAME__) _T("\", signature \"") _T(__FUNCSIG__) _T("\"."))

#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_WARN
# define DpWarnExpectTrue(...)   ((void)0)
# define DpWarnExpectFalse(...)  ((void)0)
#else
 /**
  * \brief 调试打印警告：期望为真。
  *        Expect True.
  * \param proc 处理，返回`TRUE`或`FALSE`。
  * \since 2018-07-02
  */
# define DpWarnExpectTrue(proc)  ((proc) || (DpWarnFwLE(#proc), FALSE))
 /**
  * \brief 调试打印警告：期望为假。
  *        Expect False.
  * \param proc 处理，返回`TRUE`或`FALSE`。
  * \since 2018-07-02
  */
# define DpWarnExpectFalse(proc) ((proc) && (DpWarnFwLE(#proc), TRUE))
#endif

/**
 * \brief 调试打印追踪：进入函数。
 * \since 2018-07-02
 */
#define DpTraceEnter() DpTrace(_T("Enter ") _T(__FUNCTION__) _T("."))
/**
 * \brief 调试打印追踪：离开函数。
 * \since 2018-07-02
 */
#define DpTraceLeave() DpTrace(_T("Leave ") _T(__FUNCTION__) _T("."))
