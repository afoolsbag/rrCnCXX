/*===-- Windows String -----------------------------------------*- C -*-===*//**
 *
 * \defgroup gWinStr Windows字符串操作
 * \ingroup gStr
 *
 * \version 2018-05-07
 * \since 2018-05-07
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#include <strsafe.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#// C

#ifndef CmpStrA
#define CmpStrA(str1, str2) CompareStringA(LOCALE_USER_DEFAULT, NORM_IGNORECASE, str1, -1, str2, -1)
#endif/*CmpStrA*/
#ifndef CmpStrW
#define CmpStrW(str1, str2) CompareStringW(LOCALE_USER_DEFAULT, NORM_IGNORECASE, str1, -1, str2, -1)
#endif/*CmpStrW*/

#ifdef UNICODE
# define CmpStr CmpStrW
#else
# define CmpStr CmpStrA
#endif

#// L

inline size_t StrLenA(LPCSTR CONST string)
{
    size_t len = 0;
    (VOID)SUCCEEDED(StringCchLengthA(string, STRSAFE_MAX_CCH, &len));
    return len;
}

inline size_t StrLenW(LPCWSTR CONST string)
{
    size_t len = 0;
    (VOID)SUCCEEDED(StringCchLengthW(string, STRSAFE_MAX_CCH, &len));
    return len;
}

#ifdef UNICODE
# define StrLen StrLenW
#else
# define StrLen StrLenA
#endif

/** @} */
