/*===-- Generate UUID ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gGenUuid 生成通用唯一标识符
 * \ingroup gRPC
 *
 * \version 2018-05-02
 * \since 2018-02-23
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef RRWINDOWS_RPC_SHARED
# ifdef RRWINDOWS_RPC_EXPORTS
#  define RRWINDOWS_RPC_API __declspec(dllexport)
# else
#  define RRWINDOWS_RPC_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_RPC_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 生成通用唯一标识符（ANSI适配）。
 * \warning 该字串缓存在公用静态变量中，请即取即用。
 *
 * \returns 若成功，返回指向缓存的指针；
 *          若失败，返回空指针（`NULL`）。
 * 
 * \sa ["UuidCreate function"](https://msdn.microsoft.com/library/aa379205). *Microsoft® Developer Network*.
 * \sa ["UuidToString function"](https://msdn.microsoft.com/library/aa379352). *Microsoft® Developer Network*.
 * \sa ["RpcStringFree function"](https://msdn.microsoft.com/library/aa378483). *Microsoft® Developer Network*.
 */
RRWINDOWS_RPC_API _Success_(return != NULL) LPCSTR WINAPI
GenerateUuidA(VOID);

/**
 * \brief 生成通用唯一标识符（UNICODE适配）。
 * \warning 该字串缓存在公用静态变量中，请即取即用。
 *
 * \returns 若成功，返回指向缓存的指针；
 *          若失败，返回空指针（`NULL`）。
 */
RRWINDOWS_RPC_API _Success_(return != NULL) LPCWSTR WINAPI
GenerateUuidW(VOID);

#ifdef UNICODE
# define GenerateUuid GenerateUuidW
#else
# define GenerateUuid GenerateUuidA
#endif

#ifdef __cplusplus
}
#endif
