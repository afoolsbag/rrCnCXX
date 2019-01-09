/*===-- Tool Help Library --------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 工具帮助库。
 *
 * \version 2019-01-08
 * \since 2018-04-28
 * \authors zhengrr
 * \copyright Unlicense
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
 * \brief 按可执行文件计数进程（ANSI 适配）。
 *
 * \param executableName 可执行文件名，如 `foobar.exe`。
 * \returns `(-, 0)` 失败，调用 `GetLastError()` 获取扩展错误信息；\n
 *          `[0, +)` 计数。
 */
RRWINDOWS_API
_Success_(0 <= return)
INT
WINAPI
CountProcessesByExecutableA(
    _In_z_ PCSTR CONST executableName
);

/**
 * \brief 按可执行文件计数进程（UNICODE 适配）。
 *
 * \param executableName 可执行文件名，如 `foobar.exe`。
 * \returns `(-, 0)` 失败，调用 `GetLastError()` 获取扩展错误信息；\n
 *          `[0, +)` 计数。
 */
RRWINDOWS_API
_Success_(0 <= return)
INT
WINAPI
CountProcessesByExecutableW(
    _In_z_ PCWSTR CONST executableName
);

#ifdef _UNICODE
# define CountProcessesByExecutable CountProcessesByExecutableW
#else
# define CountProcessesByExecutable CountProcessesByExecutableA
#endif

#ifdef __cplusplus
}
#endif
