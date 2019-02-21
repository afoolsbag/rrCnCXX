/*===-- Directory Management -----------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 目录管理。
 *
 * \version 2018-10-23
 * \since 2018-06-01
 * \authors zhengrr
 * \copyright The Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrWindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 递归创建目录（ANSI 适配）。
 * \param path 目录路径，不以反斜杠结尾。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError()` 获取扩展信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
CreateDirectoryRecursivelyA(
    _In_z_ PCSTR CONST path
);

/**
 * \brief 递归创建目录（UNICODE 适配）。
 * \param path 目录路径，不以反斜杠结尾。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError()` 获取扩展信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
CreateDirectoryRecursivelyW(
    _In_z_ PCWSTR CONST path
);

#ifdef _UNICODE
# define CreateDirectoryRecursively CreateDirectoryRecursivelyW
#else
# define CreateDirectoryRecursively CreateDirectoryRecursivelyA
#endif

/**
 * \brief 遍历删除目录（ANSI 适配）。
 * \param path 目录路径，不以反斜杠结尾。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError()` 获取扩展信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveDirectoryTraverselyA(
    _In_z_ PCSTR CONST path
);

/**
 * \brief 遍历删除目录（UNICODE 适配）。
 * \param path 目录路径，不以反斜杠结尾。
 * \returns `!FALSE` 成功\n
 *           `FALSE` 失败，调用 `GetLastError()` 获取扩展信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveDirectoryTraverselyW(
    _In_z_ PCWSTR CONST path
);

#ifdef _UNICODE
# define RemoveDirectoryTraversely RemoveDirectoryTraverselyW
#else
# define RemoveDirectoryTraversely RemoveDirectoryTraverselyA
#endif

#ifdef __cplusplus
}
#endif
