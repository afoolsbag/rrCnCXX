/*===-- String Interface Simplify ------------------------------*- C -*-===*//**
 *
 * \defgroup gStrSim 字符串接口简化
 * \ingroup gStr
 *
 * \version 2018-07-13
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

#include "rrWindows/macro.h"

/*-C--------------------------------------------------------------------------*/

/**
 * \brief 按二进制顺序地比较UNICODE字符串（Simplify接口，2参数）。
 *
 * \param lhs 左侧字符串；
 * \param rhs 右侧字符串。
 * \returns 0                 失败，可调用`GetLastError()`获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
FORCEINLINE
_Success_(return != 0)
INT
WINAPI_INLINE
CompareStringOrdinalS2(
    _In_z_ LPCWSTR CONST lhs,
    _In_z_ LPCWSTR CONST rhs)
{
    return CompareStringOrdinal(lhs, -1, rhs, -1, FALSE);
}
/**
 * \brief 按二进制顺序地比较UNICODE字符串（Simplify接口，3参数）。
 *
 * \param lhs        左侧字符串；
 * \param rhs        右侧字符串；
 * \param ignoreCase 忽略大小写。
 * \returns 0                 失败，可调用`GetLastError()`获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
FORCEINLINE
_Success_(return != 0)
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
 * \brief 按二进制顺序地比较UNICODE字符串（Simplify接口，便利宏）。
 *
 * \param lhs        左侧字符串；
 * \param rhs        右侧字符串；
 * \param ignoreCase 可选的，忽略大小写，默认`FALSE`。
 * \returns 0                 失败，可调用`GetLastError()`获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
#define CompareStringOrdinalS(...)                                             \
    RRWINDOWS_EXPAND(                                                          \
        RRWINDOWS_VAFUNC3(__VA_ARGS__, CompareStringOrdinalS3,                 \
                                       CompareStringOrdinalS2,                 \
                                       RRWINDOWS_VABAN)(__VA_ARGS__)           \
    )

/**
 * \brief 比较字符串（ANSI适配，Simplify接口）。
 *
 * \param lhs 左侧字符串；
 * \param rhs 右侧字符串。
 * \returns 0                 失败，可调用`GetLastError()`获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
FORCEINLINE
_Success_(return != 0)
INT
WINAPI_INLINE
CompareStringAs(
    _In_z_ LPCSTR CONST lhs,
    _In_z_ LPCSTR CONST rhs)
{
    return CompareStringA(LOCALE_USER_DEFAULT, NORM_LINGUISTIC_CASING, lhs, -1, rhs, -1);
}
/**
 * \brief 比较字符串（UNICODE适配，Simplify接口）。
 *
 * \param lhs 左侧字符串；
 * \param rhs 右侧字符串。
 * \returns 0                 失败，可调用`GetLastError()`获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
FORCEINLINE
_Success_(return != 0)
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
 * \brief 按区域地比较UNICODE字符串（Simplify接口）。
 *
 * \param lhs 左侧字符串；
 * \param rhs 右侧字符串。
 * \returns 0                 失败，可调用`GetLastError()`获取扩展错误信息；\n
 *          CSTR_LESS_THAN    左侧小于右侧；\n
 *          CSTR_EQUAL        两侧相等；\n
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
FORCEINLINE
_Success_(return != 0)
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
 * \param str 字符串。
 * \returns 长度。
 */
FORCEINLINE
size_t
WINAPI_INLINE
StringCchLengthAs(
    _In_z_ LPCSTR CONST str)
{
    size_t len = 0;
    if (FAILED(StringCchLengthA(str, STRSAFE_MAX_CCH, &len)))
        return 0;
    return len;
}
/**
 * \brief 计算字符串长度（UNICODE适配，Simplify接口）。
 *
 * \param str 字符串。
 * \returns 长度。
 */
FORCEINLINE
size_t
WINAPI_INLINE
StringCchLengthWs(
    _In_z_ LPCWSTR CONST str)
{
    size_t len = 0;
    if (FAILED(StringCchLengthW(str, STRSAFE_MAX_CCH, &len)))
        return 0;
    return len;
}
#ifdef _UNICODE
# define StringCchLengthS StringCchLengthWs
#else
# define StringCchLengthS StringCchLengthAs
#endif

/** @} */
