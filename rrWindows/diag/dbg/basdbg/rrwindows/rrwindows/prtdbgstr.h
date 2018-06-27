/*===-- Print Debug String -------------------------------------*- C -*-===*//**
 *
 * \defgroup gPrtDbgStr 打印调试字串。
 * \ingroup gBasDbg
 *
 * \sa ["OutputDebugString function"](https://msdn.microsoft.com/library/aa363362). *MSDN*.
 *
 * \version 2018-06-27
 * \since 2018-05-26
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrwindows/def.h"
#include "rrwindows/rrwindowsapi.h"

/*-Output-Debug-String--------------------------------------------------------*/

/*
WINBASEAPI
VOID
WINAPI
OutputDebugStringA(
    _In_opt_ LPCSTR lpOutputString);
*/

/*
WINBASEAPI
VOID
WINAPI
OutputDebugStringW(
    _In_opt_ LPCWSTR lpOutputString);
*/

/*-Variadic-Print-Debug-String------------------------------------------------*/

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 打印调试字串（va_list接口，ANSI适配，MemoryAllocate实现）。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringAma(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va);

/**
 * \brief 打印调试字串（va_list接口，ANSI适配，StaticBuffer实现）。
 * \warning 预设的缓存尺寸可能不足。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringAsb(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va);

/**
 * \brief 打印调试字串（va_list接口，UNICODE适配，MemoryAllocate实现）。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringWma(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    _In_                          va_list CONST va);

/**
 * \brief 打印调试字串（va_list接口，UNICODE适配，StaticBuffer实现）。
 * \warning 预设的缓存尺寸可能不足。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringWsb(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    _In_                          va_list CONST va);

#ifdef __cplusplus
}
#endif

/*-Print-Debug-String---------------------------------------------------------*/

/**
 * \brief 打印调试字串（ANSI适配，MemoryAllocate实现）。
 */
FORCEINLINE
VOID
WINAPIV
PrintDebugStringAma(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);
    VPrintDebugStringAma(format, va);
    va_end(va);
}

/**
 * \brief 打印调试字串（ANSI适配，StaticBuffer实现）。
 * \warning 预设的缓存尺寸可能不足。
 */
FORCEINLINE
VOID
WINAPIV
PrintDebugStringAsb(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);
    VPrintDebugStringAsb(format, va);
    va_end(va);
}

/**
 * \brief 打印调试字串（UNICODE适配，MemoryAllocate实现）。
 */
FORCEINLINE
VOID
WINAPIV
PrintDebugStringWma(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);
    VPrintDebugStringWma(format, va);
    va_end(va);
}

/**
 * \brief 打印调试字串（UNICODE适配，StaticBuffer实现）。
 * \warning 预设的缓存尺寸可能不足。
 */
FORCEINLINE
VOID
WINAPIV
PrintDebugStringWsb(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);
    VPrintDebugStringWsb(format, va);
    va_end(va);
}

#ifdef _UNICODE
# define PrintDebugString PrintDebugStringWsb
#else
# define PrintDebugString PrintDebugStringAsb
#endif

/*-Debug-Print----------------------------------------------------------------*/

#define DEBUG_PRINT_OFF   0  /* 禁用调试打印。 */
#define DEBUG_PRINT_FATAL 1  /* 致命，程序随时可能终止。应尽快保存数据，整理日志，通知用户，并重启、自检、尝试修复。 */
#define DEBUG_PRINT_ERROR 2  /* 错误，不应路由至此状态。虽无崩溃之虞，但程序已脱离掌控，应引导用户积极处理。 */
#define DEBUG_PRINT_WARN  3  /* 警告，损害功能或性能，如操作失败、资源缺乏、连接失败、权限不足等。 */
#define DEBUG_PRINT_INFO  4  /* 信息，有助于更新程序，如操作记录（评估需求）、行为记录（改进交互）、性能记录（优化性能）等。 */
#define DEBUG_PRINT_DEBUG 5  /* 调试。 */
#define DEBUG_PRINT_TRACE 6  /* 追踪，以追踪流程。 */
#define DEBUG_PRINT_ALL   7  /* 启用所有级别调试打印。 */
#ifdef _DEBUG
# define DEBUG_PRINT_DEFAULT DEBUG_PRINT_DEBUG
#else
# define DEBUG_PRINT_DEFAULT DEBUG_PRINT_INFO
#endif

#ifndef DEBUG_PRINT_LEVEL
#define DEBUG_PRINT_LEVEL DEBUG_PRINT_DEFAULT  /* 调试打印级别。 */
#endif

#ifdef _DEBUG
# define DpFormat(apdfmt, ...) PrintDebugString(FILELINE _T("<%lu> ") apdfmt ATFUNCNL, GetCurrentThreadId(), __VA_ARGS__)
#else
# define DpFormat(apdfmt, ...) PrintDebugString(_T("<%lu> ") apdfmt _T("\n"), GetCurrentThreadId(), __VA_ARGS__)
#endif

/** \brief 调试打印（致命）。 */
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_FATAL
# define DpFatal(...)         ((void)0)
#elif defined(_DEBUG)
# define DpFatal(apdfmt, ...) do { DpFormat(_T("Fatal: ") apdfmt, __VA_ARGS__); __debugbreak(); } while(0)
#else
# define DpFatal(apdfmt, ...) DpFormat(_T("Fatal: ") apdfmt, __VA_ARGS__)
#endif
/** \brief 调试打印（错误）。 */
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_ERROR
# define DpError(...)         ((void)0)
#elif defined(_DEBUG)
# define DpError(apdfmt, ...) do { DpFormat(_T("Error: ") apdfmt, __VA_ARGS__); __debugbreak(); } while(0)
#else
# define DpError(apdfmt, ...) DpFormat(_T("Error: ") apdfmt, __VA_ARGS__)
#endif
/** \brief 调试打印（警告）。 */
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_WARN
# define DpWarn(...)          ((void)0)
#else
# define DpWarn(apdfmt, ...)  DpFormat(_T("Warn: ") apdfmt, __VA_ARGS__)
#endif
/** \brief 调试打印（信息）。 */
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_INFO
# define DpInfo(...)          ((void)0)
#else
# define DpInfo(apdfmt, ...)  DpFormat(_T("Info: ") apdfmt, __VA_ARGS__)
#endif
/** \brief 调试打印（调试）。 */
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_DEBUG
# define DpDebug(...)         ((void)0)
#else
# define DpDebug(apdfmt, ...) DpFormat(_T("Debug: ") apdfmt, __VA_ARGS__)
#endif
/** \brief 调试打印（追踪）。 */
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_TRACE
# define DpTrace(...)         ((void)0)
#else
# define DpTrace(apdfmt, ...) DpFormat(_T("Trace: ") apdfmt, __VA_ARGS__)
#endif

/** \brief 调试打印（错误）：switch未知路由。
 *  \param expr 表达式。 */
#define DpErrorSwitchUnknown(expr) DpError(_T("Unknown switch-route with expression: ") _T(#expr) _T("=%I64d."), (INT64)(expr))

/** \brief 调试打印（警告）：失败和最后错误（Failed with Last Error）。
 *  \param opfmt 操作描述格式。
 *  \param ...   操作描述参数。 */
#if DEBUG_PRINT_LEVEL < DEBUG_PRINT_WARN
# define DpWarnFwLE(...)        ((void)0)
#elif defined(_DEBUG)
# define DpWarnFwLE(opfmt, ...) PrintDebugString(FILELINE _T("<%lu> ") _T("Warn: ") opfmt _T(" failed with error %lu: %s") ATFUNCNL, GetCurrentThreadId(), __VA_ARGS__, GetLastError(), GetLastErrorText())
#else
# define DpWarnFwLE(opfmt, ...) PrintDebugString(_T("<%lu> ") _T("Warn: ") opfmt _T(" failed with error %lu: %s\n"), GetCurrentThreadId(), __VA_ARGS__, GetLastError(), GetLastErrorText())
#endif

/** \brief 调试打印（调试）：函数名、函数修饰名和函数签名。 */
#define DpDebugFunc() DpDebug(_T("Function name \"%s\", decorated name \"%s\", signature \"%s\"."), _T(__FUNCTION__), _T(__FUNCDNAME__), _T(__FUNCSIG__))

/** \brief 调试打印（追踪）：进入函数。 */
#define DpTraceEnter() DpTrace(_T("Enter ") _T(__FUNCTION__) _T("."))

/** \brief 调试打印（追踪）：离开函数。 */
#define DpTraceLeave() DpTrace(_T("Leave ") _T(__FUNCTION__) _T("."))

/** @} */
