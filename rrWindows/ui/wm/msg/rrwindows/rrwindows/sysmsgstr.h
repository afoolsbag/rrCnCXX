/*===-- System Message String ----------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 系统消息字串。
 *
 * \version 2018-05-04
 * \since 2018-04-13
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 系统消息号转字串（ANSI适配）。
 */
RRWINDOWS_API LPCSTR WINAPI
SystemMessageStringA(
    _In_ CONST UINT messageNumber);

/**
 * \brief 系统消息号转字串（UNICODE适配）。
 */
RRWINDOWS_API LPCWSTR WINAPI
SystemMessageStringW(
    _In_ CONST UINT messageNumber);

#ifdef UNICODE
# define SystemMessageString SystemMessageStringW
#else
# define SystemMessageString SystemMessageStringA
#endif

/**
 * \brief 系统消息号转字串（缩写）。
 */
#define SysMsgStr SystemMessageString

#ifdef __cplusplus
}
#endif
