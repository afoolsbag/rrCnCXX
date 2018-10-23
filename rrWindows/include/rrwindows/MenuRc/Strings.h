/*===-- Strings ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 字符串。
 *
 * \version 2018-10-23
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
 * \brief 字符串分配串联（ANSI 适配）。
 * \param src1 源字符串 1。
 * \param src2 源字符串 2。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
StringAllocCatA(
    _In_ PCSTR CONST src1,
    _In_ PCSTR CONST src2
);

/**
 * \brief 字符串分配串联（UNICODE 适配）。
 * \param[in]  src1 源字符串 1。
 * \param[in]  src2 源字符串 2。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
StringAllocCatW(
    _In_ PCWSTR CONST src1,
    _In_ PCWSTR CONST src2
);

#ifdef _UNICODE
# define StringAllocCat StringAllocCatW
#else
# define StringAllocCat StringAllocCatA
#endif

/**
 * \brief 字符串分配串联 3（ANSI 适配）。
 * \param[in]  src1 源字符串 1。
 * \param[in]  src2 源字符串 2。
 * \param[in]  src3 源字符串 3。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
StringAllocCat3A(
    _In_ PCSTR CONST src1,
    _In_ PCSTR CONST src2,
    _In_ PCSTR CONST src3
);

/**
 * \brief 字符串分配串联 3（UNICODE 适配）。
 * \param[in]  src1 源字符串 1。
 * \param[in]  src2 源字符串 2。
 * \param[in]  src3 源字符串 3。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
StringAllocCat3W(
    _In_ PCWSTR CONST src1,
    _In_ PCWSTR CONST src2,
    _In_ PCWSTR CONST src3
);

#ifdef _UNICODE
# define StringAllocCat3 StringAllocCat3W
#else
# define StringAllocCat3 StringAllocCat3A
#endif

/**
 * \brief 字符串分配复制，额外 `Count` 参数（ANSI 适配）。
 * \param[in]  src       源字符串。
 * \param[out] heapCount 分配的堆字符数。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PSTR
WINAPI
StringAllocCopy_CountA(
    _In_        PCSTR CONST src,
    _Out_opt_ PSIZE_T CONST heapCount
);

/**
 * \brief 字符串分配复制，额外 `Count` 参数（UNICODE 适配）。
 * \param[in]  src       源字符串。
 * \param[out] heapCount 分配的堆字符数。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
StringAllocCopy_CountW(
    _In_       PCWSTR CONST src,
    _Out_opt_ PSIZE_T CONST heapCount
);

#ifdef _UNICODE
# define StringAllocCopy_Count StringAllocCopy_CountW
#else
# define StringAllocCopy_Count StringAllocCopy_CountA
#endif

/**
 * \brief 字符串分配复制（ANSI 适配）。
 * \param[in]  src  源字符串。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCSTR
WINAPI_INLINE
StringAllocCopyA(
    _In_ PCSTR CONST src)
{
    return StringAllocCopy_CountA(src, NULL);
}

/**
 * \brief 字符串分配复制（UNICODE 适配）。
 * \param[in]  src  源字符串。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCWSTR
WINAPI_INLINE
StringAllocCopyW(
    _In_ PCWSTR CONST src)
{
    return StringAllocCopy_CountW(src, NULL);
}

#ifdef _UNICODE
# define StringAllocCopy StringAllocCopyW
#else
# define StringAllocCopy StringAllocCopyA
#endif

#ifdef __cplusplus
}
#endif
