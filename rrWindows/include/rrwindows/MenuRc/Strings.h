/*===-- Strings ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 字符串。
 *
 * \version 2018-10-19
 * \since 2018-05-07
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
 * \brief 字符串分配并串联（ANSI 适配）。
 * \param[in]  src1 源字符串 1。
 * \param[in]  src2 源字符串 2。
 * \param[out] dest 堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
StringAllocCatA(
    _In_     PCSTR CONST src1,
    _In_     PCSTR CONST src2,
    _Outptr_ PSTR *CONST dest
);

/**
 * \brief 字符串分配并串联（UNICODE 适配）。
 * \param[in]  src1 源字符串 1。
 * \param[in]  src2 源字符串 2。
 * \param[out] dest 堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `L'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
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
 * \brief 字符串分配并串联（ANSI 适配）。
 * \param[in]  src1 源字符串 1。
 * \param[in]  src2 源字符串 2。
 * \param[in]  src3 源字符串 3。
 * \param[out] dest 堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
StringAllocCat3A(
    _In_     PCSTR CONST src1,
    _In_     PCSTR CONST src2,
    _In_     PCSTR CONST src3,
    _Outptr_ PSTR *CONST dest
);

/**
 * \brief 字符串分配并串联（UNICODE 适配）。
 * \param[in]  src1 源字符串 1。
 * \param[in]  src2 源字符串 2。
 * \param[in]  src3 源字符串 3。
 * \param[out] dest 堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `L'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
StringAllocCat3W(
    _In_     PCWSTR CONST src1,
    _In_     PCWSTR CONST src2,
    _In_     PCWSTR CONST src3,
    _Outptr_ PWSTR *CONST dest
);

#ifdef _UNICODE
# define StringAllocCat3 StringAllocCat3W
#else
# define StringAllocCat3 StringAllocCat3A
#endif

/**
 * \brief 字符串分配并复制（ANSI 适配）。
 * \param[in]  src  源字符串。
 * \param[out] dest 堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
StringAllocCopyA(
    _In_     PCSTR CONST src,
    _Outptr_ PSTR *CONST dest
);

/**
 * \def StringAllocCopy
 * \brief 字符串分配并复制（UNICODE 适配）。
 * \param[in]  src  源字符串。
 * \param[out] dest 堆字符串指针。
 * \returns `+` 成功，值为堆字符串的字符计数（含 `L'\0'`）；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return > 0)
size_t
WINAPI
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
