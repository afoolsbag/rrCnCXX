/*===-- Print Debug String -------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 打印调试字串。
 *
 * \sa ["OutputDebugString function"](https://msdn.microsoft.com/library/aa363362). *MSDN*.
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

#include "rrwindows/api.h"

/*-Output-Debug-String--------------------------------------------------------*/

/*
WINBASEAPI
VOID
WINAPI
OutputDebugStringA(
    _In_opt_ LPCSTR lpOutputString
);
*/

/*
WINBASEAPI
VOID
WINAPI
OutputDebugStringW(
    _In_opt_ LPCWSTR lpOutputString
);
*/

/*-Print-Debug-String---------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 变参打印调试字串（ANSI 适配）。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringA(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    _In_                         va_list CONST va
);

/**
 * \brief 变参打印调试字串（UNICODE 适配）。
 */
RRWINDOWS_API
VOID
WINAPI
VPrintDebugStringW(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    _In_                          va_list CONST va
);

#ifdef _UNICODE
# define VPrintDebugString VPrintDebugStringW
#else
# define VPrintDebugString VPrintDebugStringA
#endif

#ifdef __cplusplus
}
#endif

/**
 * \brief 打印调试字串（ANSI 适配）。
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
    VPrintDebugStringA(format, va);
    va_end(va);
}

/**
 * \brief 打印调试字串（UNICODE 适配）。
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
    VPrintDebugStringW(format, va);
    va_end(va);
}

#ifdef _UNICODE
# define PrintDebugString PrintDebugStringW
#else
# define PrintDebugString PrintDebugStringA
#endif

/** @} */
