/*===-- Generate UUID ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 生成通用唯一标识符。
 *
 * \version 2018-08-23
 * \since 2018-02-23
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/api.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 生成通用唯一标识符（ANSI 适配）。
 * \warning 该字串缓存在共用静态变量中，请即取即用。
 *
 * \returns 若成功，返回指向缓存的指针；
 *          若失败，返回空指针（`NULL`）。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
GenerateUuidA(VOID);

/**
 * \brief 生成通用唯一标识符（UNICODE 适配）。
 * \warning 该字串缓存在共用静态变量中，请即取即用。
 *
 * \returns 若成功，返回指向缓存的指针；
 *          若失败，返回空指针（`NULL`）。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
GenerateUuidW(VOID);

#ifdef _UNICODE
# define GenerateUuid GenerateUuidW
#else
# define GenerateUuid GenerateUuidA
#endif

#ifdef __cplusplus
}
#endif
