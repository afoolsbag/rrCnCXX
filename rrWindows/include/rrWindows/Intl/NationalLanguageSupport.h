/*===-- National Language Support ------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 国家语言支持。
 *
 * \version 2018-10-19
 * \since 2018-10-19
 * \authors zhengrr
 * \copyright The Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrWindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 字符串比对（ANSI 适配）。
 * \returns `CSTR_LESS_THAN`    左侧较先；\n
 *          `CSTR_EQUAL`        二者相等；\n
 *          `CSTR_GREATER_THAN` 右侧较先。
 */
FORCEINLINE
INT
WINAPI_INLINE
CompareStringInvariantA(
    _In_ PCSTR CONST str1,
    _In_ PCSTR CONST str2)
{
    return CompareStringA(LOCALE_INVARIANT, 0, str1, -1, str2, -1);
}

/**
 * \brief 字符串比对（UNICODE 适配）。
 * \returns `CSTR_LESS_THAN`    左侧较先；\n
 *          `CSTR_EQUAL`        二者相等；\n
 *          `CSTR_GREATER_THAN` 右侧较先。
 */
FORCEINLINE
INT
WINAPI_INLINE
CompareStringInvariantW(
    _In_ PCWSTR CONST str1,
    _In_ PCWSTR CONST str2)
{
    return CompareStringEx(LOCALE_NAME_INVARIANT, 0, str1, -1, str2, -1, NULL, NULL, 0);
}

#ifdef _UNICODE
# define CompareStringInvariant CompareStringInvariantW
#else
# define CompareStringInvariant CompareStringInvariantA
#endif

/**
 * \brief 字符串比对（ANSI 适配）。
 * \returns `CSTR_LESS_THAN`    左侧较先；\n
 *          `CSTR_EQUAL`        二者相等；\n
 *          `CSTR_GREATER_THAN` 右侧较先。
 */
FORCEINLINE
INT
WINAPI_INLINE
CompareStringSystemDefaultA(
    _In_ PCSTR CONST str1,
    _In_ PCSTR CONST str2)
{
    return CompareStringA(LOCALE_SYSTEM_DEFAULT, 0, str1, -1, str2, -1);
}

/**
 * \brief 字符串比对（UNICODE 适配）。
 * \returns `CSTR_LESS_THAN`    左侧较先；\n
 *          `CSTR_EQUAL`        二者相等；\n
 *          `CSTR_GREATER_THAN` 右侧较先。
 */
FORCEINLINE
INT
WINAPI_INLINE
CompareStringSystemDefaultW(
    _In_ PCWSTR CONST str1,
    _In_ PCWSTR CONST str2)
{
    return CompareStringEx(LOCALE_NAME_SYSTEM_DEFAULT, 0, str1, -1, str2, -1, NULL, NULL, 0);
}

#ifdef _UNICODE
# define CompareStringSystemDefault CompareStringSystemDefaultW
#else
# define CompareStringSystemDefault CompareStringSystemDefaultA
#endif

/**
 * \brief 字符串比对（ANSI 适配）。
 * \returns `CSTR_LESS_THAN`    左侧较先；\n
 *          `CSTR_EQUAL`        二者相等；\n
 *          `CSTR_GREATER_THAN` 右侧较先。
 */
FORCEINLINE
INT
WINAPI_INLINE
CompareStringUserDefaultA(
    _In_ PCSTR CONST str1,
    _In_ PCSTR CONST str2)
{
    return CompareStringA(LOCALE_USER_DEFAULT, 0, str1, -1, str2, -1);
}

/**
 * \brief 字符串比对（UNICODE 适配）。
 * \returns `CSTR_LESS_THAN`    左侧较先；\n
 *          `CSTR_EQUAL`        二者相等；\n
 *          `CSTR_GREATER_THAN` 右侧较先。
 */
FORCEINLINE
INT
WINAPI_INLINE
CompareStringUserDefaultW(
    _In_ PCWSTR CONST str1,
    _In_ PCWSTR CONST str2)
{
    return CompareStringEx(LOCALE_NAME_USER_DEFAULT, 0, str1, -1, str2, -1, NULL, NULL, 0);
}

#ifdef _UNICODE
# define CompareStringUserDefault CompareStringUserDefaultW
#else
# define CompareStringUserDefault CompareStringUserDefaultW
#endif

#ifdef __cplusplus
}
#endif
