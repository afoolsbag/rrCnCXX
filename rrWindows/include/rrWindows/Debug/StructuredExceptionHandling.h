/*===-- Structured Exception Handling --------------------------*- C -*-===*//**
 *
 * \file
 * \brief 结构化异常处理。
 *
 * \version 2019-02-19
 * \since 2018-06-27
 * \authors zhengrr
 * \copyright Unlicense
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
 * \brief 未处理异常过滤器。
 * \details 生成转储文件：\n
 *          首先尝试存储在 `%TEMP%\\dump\\ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss.dmp`，\n
 *          其次尝试存储在 `StartIn\\crash.dmp`。
 */
RRWINDOWS_API
LONG
WINAPI
ExceptionCrashHandler(
    _In_ EXCEPTION_POINTERS *CONST ExceptionInfo
);

#ifdef __cplusplus
}
#endif
