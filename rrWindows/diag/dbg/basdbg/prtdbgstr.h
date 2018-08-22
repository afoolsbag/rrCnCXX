/*===-- Print Debug String -------------------------------------*- C -*-===*//**
 *
 * \defgroup gPrtDbgStr 打印调试字串。
 * \ingroup gBasDbg
 *
 * \sa ["OutputDebugString function"](https://msdn.microsoft.com/library/aa363362). *MSDN*.
 *
 * \version 2018-08-22
 * \since 2018-05-26
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrWindows/rrwindowsapi.h"

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
 * \brief 变参打印调试字串（ANSI 适配，MemoryAllocate 实现）。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringAma(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va);
/**
 * \brief 变参打印调试字串（UNICODE 适配，MemoryAllocate 实现）。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringWma(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    _In_                          va_list CONST va);
#ifdef _UNICODE
# define VPrintDebugStringMa VPrintDebugStringWma
#else
# define VPrintDebugStringMa VPrintDebugStringAma
#endif
/**
 * \brief 变参打印调试字串（ANSI 适配，StaticBuffer 实现）。
 * \warning 预设的缓存尺寸可能不足。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringAsb(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va);
/**
 * \brief 变参打印调试字串（UNICODE 适配，StaticBuffer 实现）。
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
 * \brief 打印调试字串（ANSI 适配）。
 * \warning 预设的缓存尺寸可能不足。
 */
FORCEINLINE
VOID
WINAPIV
PrintDebugStringA(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);
    VPrintDebugStringAsb(format, va);
    va_end(va);
}
/**
 * \brief 打印调试字串（UNICODE 适配）。
 * \warning 预设的缓存尺寸可能不足。
 */
FORCEINLINE
VOID
WINAPIV
PrintDebugStringW(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...)
{
    va_list va;
    va_start(va, format);
    VPrintDebugStringWsb(format, va);
    va_end(va);
}
#ifdef _UNICODE
# define PrintDebugString PrintDebugStringW
#else
# define PrintDebugString PrintDebugStringA
#endif

/** @} */
