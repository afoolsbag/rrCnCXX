/*===-- Debug Print --------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 调试打印。
 *
 * \version 2018-08-28
 * \since 2018-05-26
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrwindows/api.h"

/*-Debug-Print-Level----------------------------------------------------------*/

/**
 * \brief 调试打印等级。
 */
typedef enum DebugPrintLevel {
    DEBUG_PRINT_OFF = 0,    /* 禁用调试打印。 */
    DEBUG_PRINT_FATAL = 1,  /* 致命，程序随时可能终止。应尽快保存数据，整理日志，通知用户，并重启、自检、尝试修复。 */
    DEBUG_PRINT_ERROR = 2,  /* 错误，不应路由至此状态。虽无崩溃之虞，但程序已脱离掌控，应引导用户积极处理。 */
    DEBUG_PRINT_WARN = 3,   /* 警告，损害功能或性能，如操作失败、资源缺乏、连接失败、权限不足等。 */
    DEBUG_PRINT_INFO = 4,   /* 信息，有助于更新程序，如操作记录（评估需求）、行为记录（改进交互）、性能记录（优化性能）等。 */
    DEBUG_PRINT_DEBUG = 5,  /* 调试。 */
    DEBUG_PRINT_TRACE = 6,  /* 追踪。 */
    DEBUG_PRINT_ALL = 7     /* 启用所有级别调试打印。 */
} DebugPrintLevel;

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 设置调试打印等级。
 */
RRWINDOWS_API
VOID
WINAPI
SetDebugPrintLevel(
    _In_ CONST DebugPrintLevel level
);

/**
 * \brief 获取调试打印等级。
 */
RRWINDOWS_API
DebugPrintLevel
WINAPI
GetDebugPrintLevel(VOID);

#ifdef __cplusplus
}
#endif

/*-Debug-Print----------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 变参调试打印（ANSI 适配）。
 */
RRWINDOWS_API
VOID
WINAPI
VDebugPrintA(
    _In_z_                        LPCSTR CONST           file,
    _In_                           CONST UINT            line,
    _In_                           CONST DebugPrintLevel level,
    _In_z_ _Printf_format_string_ LPCSTR CONST           format,
    _In_                         va_list CONST           va
);

/**
 * \brief 变参调试打印（UNICODE 适配）。
 */
RRWINDOWS_API
VOID
WINAPI
VDebugPrintW(
    _In_z_                        LPCWSTR CONST           file,
    _In_                            CONST UINT            line,
    _In_                            CONST DebugPrintLevel level,
    _In_z_ _Printf_format_string_ LPCWSTR CONST           format,
    _In_                          va_list CONST           va
);

#ifdef _UNICODE
# define VDebugPrint VDebugPrintW
#else
# define VDebugPrint VDebugPrintA
#endif

#ifdef __cplusplus
}
#endif

/**
 * \brief 调试打印（ANSI 适配）。
 */
FORCEINLINE
VOID
WINAPIV
DebugPrintA(
    _In_z_                        LPCSTR CONST           file,
    _In_                           CONST UINT            line,
    _In_                           CONST DebugPrintLevel level,
    _In_z_ _Printf_format_string_ LPCSTR CONST           format,
    ...)
{
    va_list va;
    va_start(va, format);
    VDebugPrintA(file, line, level, format, va);
    va_end(va);
}

/**
 * \brief 调试打印（UNICODE 适配）。
 */
FORCEINLINE
VOID
WINAPIV
DebugPrintW(
    _In_z_                        LPCWSTR CONST           file,
    _In_                            CONST UINT            line,
    _In_                            CONST DebugPrintLevel level,
    _In_z_ _Printf_format_string_ LPCWSTR CONST           format,
    ...)
{
    va_list va;
    va_start(va, format);
    VDebugPrintW(file, line, level, format, va);
    va_end(va);
}

#ifdef _UNICODE
# define DebugPrint DebugPrintW
#else
# define DebugPrint DebugPrintA
#endif

/*-Debug-Print-Basic----------------------------------------------------------*/

#ifdef _DEBUG
# define DpFatal(fmt, ...)                                                     \
  do {                                                                         \
      DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_FATAL, fmt, __VA_ARGS__); \
      __debugbreak();                                                          \
  } while(0)
#else
# define DpFatal(fmt, ...)                                                     \
      DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_FATAL, fmt, __VA_ARGS__)
#endif

#ifdef _DEBUG
# define DpError(fmt, ...)                                                     \
  do {                                                                         \
      DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_ERROR, fmt, __VA_ARGS__); \
      __debugbreak();                                                          \
  } while(0)
#else
# define DpError(fmt, ...)                                                     \
      DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_ERROR, fmt, __VA_ARGS__)
#endif

#define DpWarn(fmt, ...)                                                       \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_WARN, fmt, __VA_ARGS__)

#define DpInfo(fmt, ...)                                                       \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_INFO, fmt, __VA_ARGS__)

#define DpDebug(fmt, ...)                                                      \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_DEBUG, fmt, __VA_ARGS__)

#define DpTrace(fmt, ...)                                                      \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_TRACE, fmt, __VA_ARGS__)

/*-Debug-Print-Extended-------------------------------------------------------*/

/**
 * \brief 调试打印错误：不预期的 Switch 路由。\n
 *        Debug Print Error: Unexpected Switch Route.
 */
#define DpErrorUSR(expr)                                                       \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_ERROR,                      \
               _T("Unexpected switch route with expression: ") _T(#expr) _T("=%I64d."), \
               (INT64)(expr)                                                   \
    )

/**
 * \brief 调试打印警告：失败和最后错误。\n
 *        Debug Print Warning: Failed with Last Error.
 * \param desc 操作描述。
 */
#define DpWarnFwLE(desc, ...)                                                  \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_WARN,                       \
               desc _T(" failed with error %lu: %s"),                          \
               __VA_ARGS__, GetLastError(), LastErrorText()                    \
    )

/**
 * \brief 调试打印警告：期望为真。\n
 *        Debug Print Warning: Expect True.
 * \param proc 处理，返回 `TRUE` 或 `FALSE`。
 * \since 2018-07-02
 */
#define DpWarnExpectTrue(proc)                                                 \
    ((proc) || (DpWarnFwLE(_T(#proc)), FALSE))

 /**
  * \brief 调试打印警告：期望为假。\n
  *        Debug Print Warning: Expect False.
  * \param proc 处理，返回 `TRUE` 或 `FALSE`。
  * \since 2018-07-02
  */
#define DpWarnExpectFalse(proc)                                                \
    ((proc) && (DpWarnFwLE(_T(#proc)), TRUE))

/**
 * \brief 调试打印调试：函数信息。
 */
#define DpDebugFunc()                                                          \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_DEBUG,                      \
               _T("Function name \"%s\", decorated name \"%s\", signature \"%s\"."), \
               _T(__FUNCTION__),                                               \
               _T(__FUNCDNAME__),                                              \
               _T(__FUNCSIG__)                                                 \
    )

/**
 * \brief 调试打印追踪：进入函数。
 * \since 2018-07-02
 */
#define DpTraceEnter()                                                         \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_TRACE,                      \
               _T("Enter ") _T(__FUNCTION__) _T(".")                           \
    )

/**
 * \brief 调试打印追踪：离开函数。
 * \since 2018-07-02
 */
#define DpTraceLeave()                                                         \
    DebugPrint(_T(__FILE__), __LINE__, DEBUG_PRINT_TRACE,                      \
               _T("Leave ") _T(__FUNCTION__) _T(".")                           \
    )
