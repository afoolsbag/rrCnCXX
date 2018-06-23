/*===-- Windows String -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gWinStr Windows字符串操作
 * \ingroup gStr
 *
 * \version 2018-06-23
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

#// C

/**
 * \brief 比较两个字符串（ANSI适配）。
 *
 * \returns 0                 失败，使用GetLastError()获取扩展错误信息；
 *          CSTR_LESS_THAN    左侧小于右侧；
 *          CSTR_EQUAL        两侧相等；
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
#define CmpStrA(lhs, rhs) CompareStringA(LOCALE_USER_DEFAULT, NORM_IGNORECASE, lhs, -1, rhs, -1)

/**
 * \brief 比较两个字符串（UNICODE适配）。
 *
 * \returns 0                 失败，使用GetLastError()获取扩展错误信息；
 *          CSTR_LESS_THAN    左侧小于右侧；
 *          CSTR_EQUAL        两侧相等；
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
#define CmpStrW(lhs, rhs) CompareStringW(LOCALE_USER_DEFAULT, NORM_IGNORECASE, lhs, -1, rhs, -1)

/**
 * \brief 比较两个字符串（缩写）。
 *
 * \returns 0                 失败，使用GetLastError()获取扩展错误信息；
 *          CSTR_LESS_THAN    左侧小于右侧；
 *          CSTR_EQUAL        两侧相等；
 *          CSTR_GREATER_THAN 左侧大于右侧。
 */
#define CmpStr(lhs, rhs) CompareString(LOCALE_USER_DEFAULT, NORM_IGNORECASE, lhs, -1, rhs, -1)

#// L

inline size_t StrLenA(LPCSTR CONST string)
{
    size_t len = 0;
    if (FAILED(StringCchLengthA(string, STRSAFE_MAX_CCH, &len))) return 0;
    return len;
}

inline size_t StrLenW(LPCWSTR CONST string)
{
    size_t len = 0;
    if (FAILED(StringCchLengthW(string, STRSAFE_MAX_CCH, &len))) return 0;
    return len;
}

#ifdef _UNICODE
# define StrLen StrLenW
#else
# define StrLen StrLenA
#endif

/** @} */
