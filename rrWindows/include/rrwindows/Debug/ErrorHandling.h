/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 目录管理。
 *
 * \version 2018-10-19
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
 * \brief 错误消息（ANSI 适配）。
 * \param[in]  err 错误码。
 * \param[out] msg 局部字符串指针。
 * \returns `+` 成功，值为局部字符串的字符数 +1；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当局部字符串不再使用时，调用者有责任调用 `LocalFree` 释放资源。
 */
FORCEINLINE
_Success_(return > 0)
DWORD
WINAPI_INLINE
ErrorMessageA(
    _In_     CONST DWORD err,
    _Outptr_ PSTR *CONST msg)
{
    CONST DWORD length = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, err, LANG_USER_DEFAULT,
        (PSTR)msg, 0, NULL);
    if (2 <= length)  /* remove tail "\r\n" */
        (*msg)[length - 2] = '\0';
    return length + 1;
}

/**
 * \brief 错误消息（UNICODE 适配）。
 * \param[in]  err 错误码。
 * \param[out] msg 局部字符串指针。
 * \returns `+` 成功，值为局部字符串的字符数 +1；\n
 *          `0` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当局部字符串不再使用时，调用者有责任调用 `LocalFree` 释放资源。
 */
FORCEINLINE
_Success_(return > 0)
DWORD
WINAPI_INLINE
ErrorMessageW(
    _In_     CONST DWORD  err,
    _Outptr_ PWSTR *CONST msg)
{
    CONST DWORD length = FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, err, LANG_USER_DEFAULT,
        (PWSTR)msg, 0, NULL);
    if (2 <= length)  /* remove tail L"\r\n" */
        (*msg)[length - 2] = L'\0';
    return length + 1;
}

#ifdef _UNICODE
# define ErrorMessage ErrorMessageW
#else
# define ErrorMessage ErrorMessageA
#endif

#ifdef __cplusplus
}
#endif
