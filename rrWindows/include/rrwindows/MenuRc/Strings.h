/*===-- Strings ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 字符串。
 *
 * \version 2019-01-03
 * \since 2018-05-07
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>

#include "rrwindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 比较字符串，简化接口（ANSI 适配）。
 *
 * \param lhs 左侧字符串；
 * \param rhs 右侧字符串。
 * \returns `0`                 失败，调用 `GetLastError()` 获取扩展信息；\n
 *          `CSTR_LESS_THAN`    左侧小于右侧；\n
 *          `CSTR_EQUAL`        两侧相等；\n
 *          `CSTR_GREATER_THAN` 左侧大于右侧。
 */
FORCEINLINE
_Success_(return != 0)
INT
WINAPI_INLINE
CompareString_SimplifyA(
    _In_z_ PCSTR CONST lhs,
    _In_z_ PCSTR CONST rhs)
{
    return CompareStringA(LOCALE_USER_DEFAULT, NORM_LINGUISTIC_CASING, lhs, -1, rhs, -1);
}

/**
 * \brief 比较字符串，简化接口（UNICODE 适配）。
 *
 * \param lhs 左侧字符串；
 * \param rhs 右侧字符串。
 * \returns `0`                 失败，可调用`GetLastError()`获取扩展错误信息；\n
 *          `CSTR_LESS_THAN`    左侧小于右侧；\n
 *          `CSTR_EQUAL`        两侧相等；\n
 *          `CSTR_GREATER_THAN` 左侧大于右侧。
 */
FORCEINLINE
_Success_(return != 0)
INT
WINAPI_INLINE
CompareString_SimplifyW(
    _In_z_ PCWSTR CONST lhs,
    _In_z_ PCWSTR CONST rhs)
{
    return CompareStringW(LOCALE_USER_DEFAULT, NORM_LINGUISTIC_CASING, lhs, -1, rhs, -1);
}

#ifdef _UNICODE
# define CompareString_Simplify CompareString_SimplifyW
#else
# define CompareString_Simplify CompareString_SimplifyA
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
 * \param src1 源字符串 1。
 * \param src2 源字符串 2。
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
 * \param src1 源字符串 1。
 * \param src2 源字符串 2。
 * \param src3 源字符串 3。
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
 * \param src1 源字符串 1。
 * \param src2 源字符串 2。
 * \param src3 源字符串 3。
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
 * \param src  源字符串。
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
 * \param src  源字符串。
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

/**
 * \brief 计算字符串长度，简化接口（ANSI 适配）。
 *
 * \param str 字符串。
 * \returns 长度。
 */
FORCEINLINE
size_t
WINAPI_INLINE
StringCchLength_SimplifyA(
    _In_z_ PCSTR CONST str)
{
    size_t len;
    if (FAILED(StringCchLengthA(str, STRSAFE_MAX_CCH, &len)))
        return 0;
    return len;
}

/**
 * \brief 计算字符串长度，简化接口（UNICODE 适配）。
 *
 * \param str 字符串。
 * \returns 长度。
 */
FORCEINLINE
size_t
WINAPI_INLINE
StringCchLength_SimplifyW(
    _In_z_ PCWSTR CONST str)
{
    size_t len;
    if (FAILED(StringCchLengthW(str, STRSAFE_MAX_CCH, &len)))
        return 0;
    return len;
}

#ifdef _UNICODE
# define StringCchLength_Simplify StringCchLength_SimplifyW
#else
# define StringCchLength_Simplify StringCchLength_SimplifyA
#endif

#ifdef __cplusplus
}
#endif
