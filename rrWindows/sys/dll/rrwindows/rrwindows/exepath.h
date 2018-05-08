/*===-- Executable Path ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gExePath 当前进程的可执行文件路径
 * \ingroup gDLL
 *
 * \version 2018-05-08
 * \since 2018-05-08
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
extern "C" {
#endif

/**
 * \brief 当前进程的可执行文件路径（ANSI适配）。
 */
RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
ExecuteblePathA(VOID);

/**
 * \brief 当前进程的可执行文件路径（UNICODE适配）。
 */
RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
ExecuteblePathW(VOID);

#ifdef UNICODE
# define ExecuteblePath ExecuteblePathW
#else
# define ExecuteblePath ExecuteblePathA
#endif

/**
 * \brief 当前进程的可执行文件所在目录的路径（ANSI适配）。
 */
RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
ExecutebleDirectoryPathA(VOID);

/**
 * \brief 当前进程的可执行文件所在目录的路径（UNICODE适配）。
 */
RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
ExecutebleDirectoryPathW(VOID);

#ifdef UNICODE
# define ExecutebleDirectoryPath ExecutebleDirectoryPathW
#else
# define ExecutebleDirectoryPath ExecutebleDirectoryPathA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
