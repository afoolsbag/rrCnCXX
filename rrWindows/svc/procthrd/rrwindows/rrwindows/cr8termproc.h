/*===-- Create/Terminate Process -------------------------------*- C -*-===*//**
 *
 * \defgroup gCr8TermProc 创建、终止进程
 * \ingroup gProcThrd
 *
 * \version 2018-07-13
 * \since 2018-05-07
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/macro.h"
#include "rrwindows/rrwindowsapi.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 运行可执行文件（ANSI适配，4参数）。
 *
 * \param path    路径；
 * \param command 命令，可为`NULL`；
 * \param startin 起始位置，可为`NULL`；
 * \param show    显示或隐藏。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableA4(
    _In_z_     LPCSTR CONST path,
    _In_opt_z_ LPCSTR CONST command,
    _In_opt_z_ LPCSTR CONST startin,
    _In_        CONST BOOL  show);

/**
 * \brief 运行可执行文件（ANSI适配，3参数）。
 *
 * \param path    路径；
 * \param command 命令，可为`NULL`；
 * \param startin 起始位置，可为`NULL`。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
RunExecutableA3(
    _In_z_     LPCSTR CONST path,
    _In_opt_z_ LPCSTR CONST command,
    _In_z_     LPCSTR CONST startin)
{
    return RunExecutableA4(path, command, startin, TRUE);
}

/**
 * \brief 运行可执行文件（ANSI适配，2参数）。
 *
 * \param path    路径；
 * \param command 命令，可为`NULL`。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
RunExecutableA2(
    _In_z_     LPCSTR CONST path,
    _In_opt_z_ LPCSTR CONST command)
{
    return RunExecutableA3(path, command, NULL);
}

/**
 * \brief 运行可执行文件（ANSI适配，1参数）。
 *
 * \param path 路径。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
RunExecutableA1(
    _In_z_ LPCSTR CONST path)
{
    return RunExecutableA2(path, NULL);
}

/**
 * \brief 运行可执行文件（ANSI适配，便利宏）。
 *
 * \param path    路径；
 * \param command 可选的，命令，可为`NULL`；
 * \param startin 可选的，起始位置，可为`NULL`；
 * \param show    可选的，显示或隐藏。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
#define RunExecutableA(...) EXPAND(VAFUNC4(__VA_ARGS__, RunExecutableA4, RunExecutableA3, RunExecutableA2, RunExecutableA1)(__VA_ARGS__))

/**
 * \brief 运行可执行文件（UNICODE适配，4参数）。
 *
 * \param path    路径；
 * \param command 命令，可为`NULL`；
 * \param startin 起始位置，可为`NULL`；
 * \param show    显示或隐藏。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RunExecutableW4(
    _In_z_     LPCWSTR CONST path,
    _In_opt_z_ LPCWSTR CONST command,
    _In_opt_z_ LPCWSTR CONST startin,
    _In_         CONST BOOL  show);

/**
 * \brief 运行可执行文件（UNICODE适配，3参数）。
 *
 * \param path    路径；
 * \param command 命令，可为`NULL`；
 * \param startin 起始位置，可为`NULL`。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
RunExecutableW3(
    _In_z_     LPCWSTR CONST path,
    _In_opt_z_ LPCWSTR CONST command,
    _In_opt_z_ LPCWSTR CONST startin)
{
    return RunExecutableW4(path, command, startin, TRUE);
}

/**
 * \brief 运行可执行文件（UNICODE适配，2参数）。
 *
 * \param path    路径；
 * \param command 命令，可为`NULL`。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
RunExecutableW2(
    _In_z_     LPCWSTR CONST path,
    _In_opt_z_ LPCWSTR CONST command)
{
    return RunExecutableW3(path, command, NULL);
}

/**
 * \brief 运行可执行文件（UNICODE适配，1参数）。
 *
 * \param path 路径。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI_INLINE
RunExecutableW1(
    _In_z_ LPCWSTR CONST path)
{
    return RunExecutableW2(path, NULL);
}

/**
 * \brief 运行可执行文件（UNICODE适配，便利宏）。
 *
 * \param path    路径；
 * \param command 可选的，命令，可为`NULL`；
 * \param startin 可选的，起始位置，可为`NULL`；
 * \param show    可选的，显示或隐藏。
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 */
#define RunExecutableW(...) EXPAND(VAFUNC4(__VA_ARGS__, RunExecutableW4, RunExecutableW3, RunExecutableW2, RunExecutableW1)(__VA_ARGS__))

#ifdef _UNICODE
# define RunExecutable RunExecutableW
#else
# define RunExecutable RunExecutableA
#endif

/**
 * \brief 杀死可执行文件进程（ANSI适配）。
 * \details 尝试终止指定可执行文件的所有进程，不会因对单个进程的终止失败而中断。
 *
 * \param exeName 可执行文件名，如`foobar.exe`。
 * \returns <0  内部错误，可调用`GetLastError()`获取扩展错误信息；\n
 *           0  全部终止成功；\n
 *           0< 终止失败计数；
 */
RRWINDOWS_API
_Success_(return >= 0)
INT
WINAPI
KillExecutableA(
    _In_z_ CONST LPCSTR exeName
);
/**
 * \brief 杀死可执行文件进程（UNICODE适配）。
 * \details 尝试终止指定可执行文件的所有进程，不会因对单个进程的终止失败而中断。
 *
 * \param exeName 可执行文件名，如`foobar.exe`。
 * \returns <0  内部错误，可调用`GetLastError()`获取扩展错误信息；\n
 *           0  全部终止成功；\n
 *           0< 终止失败计数；
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

/** @} */
