/*===-- Windows Sockets 2 --------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief Windows 套接字 2 版
 *
 * \version 2019-01-04
 * \since 2019-01-04
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <inaddr.h>

#include "rrWindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 获取首个“适配器－单播－网际协议第四版”地址。
 */
RRWINDOWS_API
IN_ADDR
WINAPI
GetFirstAdapterUnicastIPv4InternetAddress(VOID);

#ifdef __cplusplus
}
#endif
