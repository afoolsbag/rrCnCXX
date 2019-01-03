/*===-- Processes and Threads ----------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 进程和线程。
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

#include "rrwindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 运行可执行文件（ANSI 适配）。
 *
 * \param path    路径；
 * \param command 命令，可为 `NULL`；
 * \param startIn 起始位置，可为 `NULL`；
 * \param show    显示或隐藏。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，调用 `GetLastError()` 获取扩展信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableA(
    _In_z_     LPCSTR CONST path,
    _In_opt_z_ LPCSTR CONST command,
    _In_opt_z_ LPCSTR CONST startIn,
    _In_        CONST BOOL  show
);

/**
 * \brief 运行可执行文件（UNICODE 适配）。
 *
 * \param path    路径；
 * \param command 命令，可为 `NULL`；
 * \param startIn 起始位置，可为 `NULL`；
 * \param show    显示或隐藏。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调 `GetLastError()` 获取扩展信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableW(
    _In_z_     LPCWSTR CONST path,
    _In_opt_z_ LPCWSTR CONST command,
    _In_opt_z_ LPCWSTR CONST startIn,
    _In_         CONST BOOL  show
);

#ifdef _UNICODE
# define RunExecutable RunExecutableW
#else
# define RunExecutable RunExecutableA
#endif

/**
 * \brief 杀死可执行文件进程（ANSI 适配）。
 * \details 尝试终止指定可执行文件的所有进程，不会因对单个进程的终止失败而中断。
 *          可将返回值视作残余的进程数。
 *
 * \param exeName 可执行文件名，如`foobar.exe`。
 * \returns `<0`  内部错误，调用 `GetLastError()` 获取扩展信息；\n
 *           `0`  全部终止成功；\n
 *           `0<` 终止失败计数。
 */
RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
KillExecutableA(
    _In_z_ CONST LPCSTR exeName
);

/**
 * \brief 杀死可执行文件进程（UNICODE 适配）。
 * \details 尝试终止指定可执行文件的所有进程，不会因对单个进程的终止失败而中断。
 *          可将返回值视作残余的进程数。
 *
 * \param exeName 可执行文件名，如`foobar.exe`。
 * \returns `<0`  内部错误，调用 `GetLastError()` 获取扩展信息；\n
 *           `0`  全部终止成功；\n
 *           `0<` 终止失败计数。
 */
RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
KillExecutableW(
    _In_z_ CONST LPCWSTR exeName
);

#ifdef _UNICODE
# define KillExecutable KillExecutableW
#else
# define KillExecutable KillExecutableA
#endif
#ifdef __cplusplus
}
#endif
