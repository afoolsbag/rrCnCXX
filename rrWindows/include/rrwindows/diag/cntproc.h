/*===-- Count Process ------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 计数进程。
 *
 * \version 2018-08-23
 * \since 2018-04-28
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/api.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 按可执行文件计数进程（ANSI适配）。
 *
 * \param exeName 可执行文件名，如`foobar.exe`。
 * \returns <0   失败，调用`GetLastError()`获取扩展错误信息；\n
 *           0<= 计数；
 */
RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
CountProcessesByExecutableA(
    _In_z_ LPCSTR CONST exeName
);

/**
 * \brief 按可执行文件计数进程（UNICODE适配）。
 *
 * \param exeName 可执行文件名，如`foobar.exe`。
 * \returns <0   失败，调用`GetLastError()`获取扩展错误信息；\n
 *           0<= 计数；
 */
RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
CountProcessesByExecutableW(
    _In_z_ LPCWSTR CONST exeName
);

#ifdef _UNICODE
# define CountProcessesByExecutable CountProcessesByExecutableW
#else
# define CountProcessesByExecutable CountProcessesByExecutableA
#endif

#ifdef __cplusplus
}
#endif
