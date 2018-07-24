/*===-- System Code String -------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 系统代码字符串。
 *
 * \version 2018-07-24
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
extern "C" {;
#endif

/*-System-Message-String------------------------------------------------------*/

/**
 * \brief 系统消息号转字串（ANSI适配）。
 */
RRWINDOWS_API
LPCSTR
WINAPI
SystemMessageStringA(
    _In_ CONST UINT messageNumber);

/**
 * \brief 系统消息号转字串（UNICODE适配）。
 */
RRWINDOWS_API
LPCWSTR
WINAPI
SystemMessageStringW(
    _In_ CONST UINT messageNumber);

#ifdef _UNICODE
# define SystemMessageString SystemMessageStringW
#else
# define SystemMessageString SystemMessageStringA
#endif

/*-System-Command-String------------------------------------------------------*/

/**
 * \brief 系统命令标识转字串（ANSI适配）。
 */
RRWINDOWS_API
LPCSTR
WINAPI
SystemCommandStringA(
    _In_ CONST UINT commandId);

/**
 * \brief 系统命令标识转字串（UNICODE适配）。
 */
RRWINDOWS_API
LPCWSTR
WINAPI
SystemCommandStringW(
    _In_ CONST UINT commandId);

#ifdef _UNICODE
# define SystemCommandString SystemCommandStringW
#else
# define SystemCommandString SystemCommandStringA
#endif

/*-System-Command-Notification-String-----------------------------------------*/

/**
 * \brief 系统命令通知转字串（ANSI适配）。
 */
RRWINDOWS_API
LPCSTR
WINAPI
SystemCommandNotificationStringA(
    _In_ CONST INT commandNotificationCode);

/**
 * \brief 系统命令通知转字串（UNICODE适配）。
 */
RRWINDOWS_API
LPCWSTR
WINAPI
SystemCommandNotificationStringW(
    _In_ CONST INT commandNotificationCode);

#ifdef _UNICODE
# define SystemCommandNotificationString SystemCommandNotificationStringW
#else
# define SystemCommandNotificationString SystemCommandNotificationStringW
#endif

#ifdef __cplusplus
}
#endif

