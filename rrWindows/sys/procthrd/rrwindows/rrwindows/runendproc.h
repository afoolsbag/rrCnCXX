/*===-- Run/End Process ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gRunEndProc 运行、终止进程
 * \ingroup gProcThrd
 *
 * \version 2018-06-23
 * \since 2018-05-07
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 运行进程（ANSI适配）。
 *
 * \param exePath 可执行程序路径。
 * \returns 成功与否。
 *
 * \sa ["CreateProcess function"](https://msdn.microsoft.com/library/ms682425). *Microsoft® Developer Network*.
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunProcessA(
    _In_z_ LPCSTR CONST exePath,
    _In_z_ LPCSTR CONST exeParameters);

/**
 * \brief 运行进程（UNICODE适配）。
 *
 * \param exePath 可执行程序路径。
 * \returns 成功与否。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunProcessW(
    _In_z_ LPCWSTR CONST exePath,
    _In_z_ LPCWSTR CONST exeParameters);

#ifdef _UNICODE
# define RunProcess RunProcessW
#else
# define RunProcess RunProcessA
#endif

/**
 * \brief 终止进程（ANSI适配）。
 *        尝试终止所有同名进程，不会因对单个进程的终止失败而中止。
 *
 * \param exeName 可执行程序名。
 * \returns 若成功终止所有同名进程，返回`TRUE`；
 *          有任一同名进程终止失败，返回`FALSE`。
 *
 * \sa ["OpenProcess function"](https://msdn.microsoft.com/library/ms684320). *Microsoft® Developer Network*.
 * \sa ["TerminateProcess function"](https://msdn.microsoft.com/library/ms686714). *Microsoft® Developer Network*.
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
EndProcessA(
    _In_z_ CONST LPCSTR exeName);

/**
 * \brief 终止进程（UNICODE适配）。
 *        尝试终止所有同名进程，不会因对单个进程的终止失败而中止。
 *
 * \param exeName 可执行程序名。
 * \returns 若成功终止所有同名进程，返回`TRUE`；
 *          有任一同名进程终止失败，返回`FALSE`。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
EndProcessW(
    _In_z_ CONST LPCWSTR exeName);

#ifdef _UNICODE
# define EndProcess EndProcessW
#else
# define EndProcess EndProcessA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
