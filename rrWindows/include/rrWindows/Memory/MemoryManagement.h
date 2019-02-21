/*===-- Memory Management --------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 内存管理。
 *
 * \version 2019-02-21
 * \since 2018-07-13
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/**
 * \brief 分配内存块，Simplify 接口。
 *
 * \param bytes 内存块尺寸。
 * \returns `!NULL` 成功，指向所分配内存块的指针；\n
 *           `NULL` 失败。
 */
FORCEINLINE
_Ret_maybenull_
_Post_writable_byte_size_(bytes)
LPVOID
WINAPI_INLINE
HeapAllocS(
    _In_ CONST SIZE_T bytes)
{
    return HeapAlloc(GetProcessHeap(), 0, bytes);
}

/**
 * \brief 重新分配内存块，Simplify 接口。
 *
 * \param ptr   内存块指针。
 * \param bytes 内存块尺寸。
 * \returns `!NULL` 成功，指向所分配内存块的指针；\n
 *           `NULL` 失败。
 *
 * \since 2019-02-21
 */
FORCEINLINE
_Ret_maybenull_
_Post_writable_byte_size_(bytes)
LPVOID
WINAPI_INLINE
HeapReAllocS(
    _In_ PVOID CONST  ptr,
    _In_ CONST SIZE_T bytes)
{
    return HeapReAlloc(GetProcessHeap(), 0, ptr, bytes);
}

/**
 * \brief 释放内存块，Simplify 接口。
 *
 * \param ptr 内存块指针。
 * \returns `!FALSE` 成功，指向所分配内存块的指针；\n
 *           `FALSE` 失败，可调用`GetLastError()`获取扩展错误信息。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
HeapFreeS(
    _In_ LPVOID CONST ptr)
{
    return HeapFree(GetProcessHeap(), 0, ptr);
}
