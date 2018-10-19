/*===-- Unicode and Character Sets -----------------------------*- C -*-===*//**
 *
 * \file
 * \brief 统一码与字符集。
 *
 * \version 2018-10-19
 * \since 2018-01-11
 * \authors zhengrr
 * \copyright The Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/macros.h"

#ifndef CP_GB2312
#define CP_GB2312                 936
#endif
#ifndef CP_BIG5
#define CP_BIG5                   950
#endif
#ifndef CP_GB18030
#define CP_GB18030                54936
#endif
#ifndef CP_UTF8
#define CP_UTF8                   65001
#endif

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 多字节字符串分配宽字节字符串。
 * \param[in]  codepage 代码页。
 * \param[in]  src      源字符串。
 * \param[out] dest     堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `L'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
INT
WINAPI
MultiByteAllocWideChar(
    _In_  CONST UINT  codepage,
    _In_  PCSTR CONST src,
    _Out_ PWSTR*CONST dest
);

/**
 * \brief 宽字节字符串分配多字节字符串。
 * \param[in]  codepage 代码页。
 * \param[in]  src      源字符串。
 * \param[out] dest     堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
INT
WINAPI
WideCharAllocMultiByte(
    _In_  CONST UINT  codepage,
    _In_ PCWSTR CONST src,
    _Out_  PSTR*CONST dest
);

/**
 * \brief 多字节字符串分配多字节字符串。
 * \param[in]  srcCodepage  源代码页。
 * \param[in]  src          源字符串。
 * \param[in]  destCodepage 堆代码页。
 * \param[out] dest         堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
INT
WINAPI
MultiByteAllocMultiByte(
    _In_ CONST UINT  srcCodepage,
    _In_ PCSTR CONST src,
    _In_ CONST UINT  destCodepage,
    _Out_ PSTR*CONST dest
);

#ifdef __cplusplus
}
#endif
