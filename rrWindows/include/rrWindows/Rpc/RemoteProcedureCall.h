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

#include "rrWindows/macros.h"

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
 * \brief 通用唯一标识符字符串，ANSI 适配。
 * \warning 该字符串存储在线程静态变量中，重复调用将被覆盖。
 *
 * \returns `!NULL` 成功\n
 *           `NULL` 失败
 */
RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
UuidStringA(VOID);

/**
 * \brief 通用唯一标识符字符串，Unicode 适配。
 * \warning 该字符串存储在线程静态变量中，重复调用将被覆盖。
 *
 * \returns `!NULL` 成功\n
 *           `NULL` 失败
 */
RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
UuidStringW(VOID);

#ifdef _UNICODE
# define UuidString UuidStringW
#else
# define UuidString UuidStringA
#endif

#ifdef __cplusplus
}
#endif
