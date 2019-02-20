/*===-- Remote Procedure Call ----------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 远程过程调用。
 *
 * \version 2019-02-20
 * \since 2018-02-23
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/macros.h"

#ifndef UUID_STRING_COUNT
#define UUID_STRING_COUNT 37
#endif

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 生成通用唯一标识符字符串，ANSI 适配。
 *
 * \param[out] buf 缓存
 * \param[in]  cnt 缓存容量（字符数）
 */
RRWINDOWS_API
HRESULT
WINAPI
GenerateUuidStringA(
    _Out_  PSTR CONST  buf,
    _In_  CONST SIZE_T cnt
);

/**
 * \brief 生成通用唯一标识符字符串，Unicode 适配。
 *
 * \param[out] buf 缓存
 * \param[in]  cnt 缓存容量（字符数）
 */
RRWINDOWS_API
HRESULT
WINAPI
GenerateUuidStringW(
    _Out_ PWSTR CONST  buf,
    _In_  CONST SIZE_T cnt
);

#ifdef _UNICODE
# define GenerateUuidString GenerateUuidStringW
#else
# define GenerateUuidString GenerateUuidStringA
#endif

/**
 * \brief 分配通用唯一标识符字符串，Count 输出，ANSI 适配。
 *
 * \param[out] cnt 缓存容量（字符数）
 * \returns `!NULL` 成功\n
 *           `NULL` 失败
 *
 * \post 若函数成功，当字符串不再使用时，调用者有责任调用 `FreeUuidString()` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PSTR
WINAPI
AllocUuidStringCA(
    _Out_opt_ PSIZE_T CONST cnt
);

/**
 * \brief 分配通用唯一标识符字符串，Count 输出，Unicode 适配。
 *
 * \param[out] cnt 分配容量（字符数）
 * \returns `!NULL` 成功\n
 *           `NULL` 失败
 *
 * \post 若函数成功，当字符串不再使用时，调用者有责任调用 `FreeUuidString()` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
AllocUuidStringCW(
    _Out_opt_ PSIZE_T CONST cnt
);

#ifdef _UNICODE
# define AllocUuidStringC AllocUuidStringCW
#else
# define AllocUuidStringC AllocUuidStringCA
#endif

/**
 * \brief 分配通用唯一标识符字符串，Unicode 适配。
 *
 * \returns `!NULL` 成功\n
 *           `NULL` 失败
 *
 * \post 若函数成功，当字符串不再使用时，调用者有责任调用 `FreeUuidString()` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCSTR
WINAPI_INLINE
AllocUuidStringA(VOID)
{
    return AllocUuidStringCA(NULL);
}

/**
 * \brief 分配通用唯一标识符字符串，Unicode 适配。
 *
 * \returns `!NULL` 成功\n
 *           `NULL` 失败
 *
 * \post 若函数成功，当字符串不再使用时，调用者有责任调用 `FreeUuidString()` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCWSTR
WINAPI_INLINE
AllocUuidStringW(VOID)
{
    return AllocUuidStringCW(NULL);
}

/**
 * \brief 释放通用唯一标识符字符串。
 */
RRWINDOWS_API
VOID
WINAPI
FreeUuidString(
    _In_ PVOID CONST ptr
);

#ifdef __cplusplus
}
#endif
