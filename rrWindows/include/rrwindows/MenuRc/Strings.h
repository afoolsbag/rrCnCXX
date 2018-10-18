/*===-- Strings ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 字符串。
 *
 * \version 2018-10-18
 * \since 2018-10-18
 * \authors zhengrr
 * \copyright The Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 分配内存并串联字符串（ANSI 适配）。
 * \param src1[in] 字符串 1。
 * \param src2[in] 字符串 2。
 * \param dest[out] 堆字符串指针。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCatA(
    _In_     PCSTR CONST src1,
    _In_     PCSTR CONST src2,
    _Outptr_ PSTR *CONST dest
);

/**
 * \brief 分配内存并串联字符串（ANSI 适配）。
 * \param src1[in] 字符串 1。
 * \param src2[in] 字符串 2。
 * \param dest[out] 堆字符串指针。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCatW(
    _In_     PCWSTR CONST src1,
    _In_     PCWSTR CONST src2,
    _Outptr_ PWSTR *CONST dest
);

#ifdef _UNICODE
# define StringAllocCat StringAllocCatW
#else
# define StringAllocCat StringAllocCatA
#endif

/**
 * \brief 分配内存并拷贝字符串（ANSI 适配）。
 * \param src[in]   源字符串。
 * \param dest[out] 堆字符串的指针。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCopyA(
    _In_     PCSTR CONST src,
    _Outptr_ PSTR *CONST dest
);

/**
 * \def StringAllocCopy
 * \brief 分配内存并拷贝字符串（UNICODE 适配）。
 * \param src[in]   源字符串。
 * \param dest[out] 堆字符串的指针。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
StringAllocCopyW(
    _In_     PCWSTR CONST src,
    _Outptr_ PWSTR *CONST dest
);

#ifdef _UNICODE
# define StringAllocCopy StringAllocCopyW
#else
# define StringAllocCopy StringAllocCopyA
#endif

#ifdef __cplusplus
}
#endif
