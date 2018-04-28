/*===-- Check Process Running ----------------------------------*- C -*-===*//**
 *
 * \defgroup gCkProcRun 检查进程正在运行否
 * \ingroup gToolHelp
 *
 * \version 2018-04-28
 * \since 2018-04-28
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef RRWINDOWS_CKPROCRUN_SHARED
# ifdef RRWINDOWS_CKPROCRUN_EXPORTS
#  define RRWINDOWS_CKPROCRUN_API __declspec(dllexport)
# else
#  define RRWINDOWS_CKPROCRUN_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_CKPROCRUN_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 检查进程正在运行否（ANSI适配）。
 *
 * \param exeFileFullName 应用程序文件全名，如`foobar.exe`。
 * \returns 若正在运行，返回其一实例进程标识号；
 *          若没有运行，返回`FALSE`。
 */
RRWINDOWS_CKPROCRUN_API
_Success_(return != 0)
DWORD WINAPI
CheckProcessRunningA(
    _In_z_ LPCSTR CONST exeFileFullName);

/**
 * \brief 检查进程正在运行否（UNICODE适配）。
 *
 * \param exeFileFullName 应用程序文件全名，如`foobar.exe`。
 * \returns 若正在运行，返回其一实例进程标识号；
 *          若没有运行，返回`FALSE`。
 */
RRWINDOWS_CKPROCRUN_API
_Success_(return != 0)
DWORD WINAPI
CheckProcessRunningW(
    _In_z_ LPCWSTR CONST exeFileFullName);

#ifdef UNICODE
# define CheckProcessRunning CheckProcessRunningW
#else
# define CheckProcessRunning CheckProcessRunningA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
