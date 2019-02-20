/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 目录管理。
 *
 * \version 2018-10-23
 * \since 2018-01-15
 * \authors zhengrr
 * \copyright The Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 分配错误消息（ANSI 适配）。
 * \param errorCode 错误码。
 * \returns `!NULL` 成功，局部字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当局部字符串不再使用时，调用者有责任调用 `LocalFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCSTR
WINAPI_INLINE
AllocErrorMessageA(
    _In_ CONST DWORD errorCode)
{
    PSTR local = NULL;
    CONST DWORD length = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, LANG_USER_DEFAULT,
        (PSTR)&local, 0, NULL);
    if (2 <= length)  /* 屏蔽回车换行（"\r\n"） */
        local[length - 2] = '\0';
    return local;
}

/**
 * \brief 分配错误消息（UNICODE 适配）。
 * \param errorCode 错误码。
 * \returns `!NULL` 成功，局部字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当局部字符串不再使用时，调用者有责任调用 `LocalFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCWSTR
WINAPI_INLINE
AllocErrorMessageW(
    _In_ CONST DWORD errorCode)
{
    PWSTR local = NULL;
    CONST DWORD length = FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, LANG_USER_DEFAULT,
        (PWSTR)&local, 0, NULL);
    if (2 <= length)  /* 屏蔽回车换行（L"\r\n"） */
        local[length - 2] = L'\0';
    return local;
}

#ifdef _UNICODE
# define AllocErrorMessage AllocErrorMessageW
#else
# define AllocErrorMessage AllocErrorMessageA
#endif

#ifdef __cplusplus
}
#endif
