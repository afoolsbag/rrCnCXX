/*===-- Windows String -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gWinStr Windows字符串操作
 * \ingroup gStr
 *
 * \version 2018-06-26
 * \since 2018-05-07
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>

#include "rrwindows/macro.h"

/*-C--------------------------------------------------------------------------*/

_Success_(return != 0)
FORCEINLINE
INT
WINAPI_INLINE
CompareStringOrdinalS2(
    _In_z_ LPCWSTR CONST lhs,
    _In_z_ LPCWSTR CONST rhs)
{
    return CompareStringOrdinal(lhs, -1, rhs, -1, FALSE);
}

_Success_(return != 0)
FORCEINLINE
INT
WINAPI_INLINE
CompareStringOrdinalS3(
    _In_z_ LPCWSTR CONST lhs,
    _In_z_ LPCWSTR CONST rhs,
    _In_     CONST BOOL  ignoreCase)
{
    return CompareStringOrdinal(lhs, -1, rhs, -1, ignoreCase);
}

/**
 * \brief 二进制等价地比较两个字符串（UNICODE适配，Simplify接口）。
 *
 * \param lhs        左侧字符串。
 * \param rhs        右侧字符串。
 * \param ignoreCase 可选的，忽略大小写，默认`FALSE`。
 * \returns 0                 失败，使用GetLastError()获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
#define CompareStringOrdinalS(...) EXPAND(VAFUNC3(__VA_ARGS__, CompareStringOrdinalS3, CompareStringOrdinalS2, VABAN)(__VA_ARGS__))

/**
 * \brief 比较两个字符串（ANSI适配，Simplify接口）。
 *
 * \param lhs 左侧字符串。
 * \param rhs 右侧字符串。
 * \returns 0                 失败，使用GetLastError()获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
_Success_(return != 0)
FORCEINLINE
INT
WINAPI_INLINE
CompareStringAs(
    _In_z_ LPCSTR CONST lhs,
    _In_z_ LPCSTR CONST rhs)
{
    return CompareStringA(LOCALE_USER_DEFAULT, NORM_LINGUISTIC_CASING, lhs, -1, rhs, -1);
}

/**
 * \brief 比较两个字符串（UNICODE适配，Simplify接口）。
 *
 * \param lhs 左侧字符串。
 * \param rhs 右侧字符串。
 * \returns 0                 失败，使用GetLastError()获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
_Success_(return != 0)
FORCEINLINE
INT
WINAPI_INLINE
CompareStringWs(
    _In_z_ LPCWSTR CONST lhs,
    _In_z_ LPCWSTR CONST rhs)
{
    return CompareStringW(LOCALE_USER_DEFAULT, NORM_LINGUISTIC_CASING, lhs, -1, rhs, -1);
}

#ifdef _UNICODE
# define CompareStringS CompareStringWs
#else
# define CompareStringS CompareStringAs
#endif

/**
 * \brief 按区域地比较两个字符串（UNICODE适配，Simplify接口）。
 *
 * \param lhs 左侧字符串。
 * \param rhs 右侧字符串。
 * \returns 0                 失败，使用GetLastError()获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
_Success_(return != 0)
FORCEINLINE
INT
WINAPI_INLINE
CompareStringExS(
    _In_z_ LPCWSTR CONST lhs,
    _In_z_ LPCWSTR CONST rhs)
{
    return CompareStringEx(LOCALE_NAME_USER_DEFAULT, NORM_LINGUISTIC_CASING,
                           lhs, -1, rhs, -1, NULL, NULL, 0);
}

/*-L--------------------------------------------------------------------------*/

/**
 * \brief 计算字符串长度（ANSI适配，Simplify接口）。
 *
 * \param string 字符串。
 * \return 有效长度。
 */
FORCEINLINE
size_t
WINAPI_INLINE
StringCchLengthAs(
    _In_z_ LPCSTR CONST string)
{
    size_t len = 0;
    if (FAILED(StringCchLengthA(string, STRSAFE_MAX_CCH, &len)))
        return 0;
    return len;
}

/**
 * \brief 计算字符串长度（UNICODE适配，Simplify接口）。
 *
 * \param string 字符串。
 * \return 有效长度。
 */
FORCEINLINE
size_t
WINAPI_INLINE
StringCchLengthWs(
    _In_z_ LPCWSTR CONST string)
{
    size_t len = 0;
    if (FAILED(StringCchLengthW(string, STRSAFE_MAX_CCH, &len)))
        return 0;
    return len;
}

#ifdef _UNICODE
# define StringCchLengthS StringCchLengthWs
#else
# define StringCchLengthS StringCchLengthAs
#endif

/** @} */
