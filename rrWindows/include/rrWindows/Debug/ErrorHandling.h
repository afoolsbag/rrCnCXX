/*===-- Error Handling -----------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 错误处理。
 *
 * \version 2019-03-27
 * \since 2018-01-15
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 格式化消息，Simplify 接口，ANSI 适配。
 * \details 该简化接口生成系统错误码对应的字符串。
 *
 * \param errorCode 错误码。
 * \returns `!NULL` 成功，指向局部字符串的指针；\n
 *           `NULL` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 *
 * \post 若函数成功，当局部字符串不再使用时，调用者有责任调用 `LocalFree()` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCSTR
WINAPI_INLINE
FormatMessageSA(
    _In_ DWORD errorCode)
{
    PSTR local = NULL;
    FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, LANG_USER_DEFAULT, (PSTR)&local, 0, NULL);
    return local;
}

/**
 * \brief 格式化消息，Simplify 接口，Unicode 适配。
 * \details 该简化接口生成系统错误码对应的字符串。
 *
 * \param errorCode 错误码。
 * \returns `!NULL` 成功，指向局部字符串的指针；\n
 *           `NULL` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 *
 * \post 若函数成功，当局部字符串不再使用时，调用者有责任调用 `LocalFree()` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCWSTR
WINAPI_INLINE
FormatMessageSW(
    _In_ DWORD errorCode)
{
    PWSTR local = NULL;
    FormatMessageW(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, LANG_USER_DEFAULT,
        (PWSTR)&local, 0, NULL);
    return local;
}

#ifdef _UNICODE
# define FormatMessageS FormatMessageSW
#else
# define FormatMessageS FormatMessageSA
#endif

/*------------------------------------------------------------------------------
 * 因使用了线程静态存储而无法导出的内部函数
 */

#ifdef RRWINDOWS_EXPORTS

/**
 * \brief 易失的错误消息，ANSI 适配。
 * \details 该函数生成系统错误码对应的字符串。
 *
 * \param errorCode 错误码。
 * \returns 指向字符串的指针。
 *
 * \warning 该函数使用线程静态存储作缓存，同线程内重复使用将使前一结果被覆盖，因而名为“易失”。
 */
_Ret_notnull_
PCSTR
WINAPI
VolatileErrorMessageA(
    _In_ DWORD errorCode);

/**
 * \brief 易失的错误消息，Unicode 适配。
 * \details 该函数生成系统错误码对应的字符串。
 *
 * \param errorCode 错误码。
 * \returns 指向字符串的指针。
 *
 * \warning 该函数使用线程静态存储作缓存，同线程内重复使用将使前一结果被覆盖，因而名为“易失”。
 */
_Ret_notnull_
PCWSTR
WINAPI
VolatileErrorMessageW(
    _In_ DWORD errorCode);

#ifdef _UNICODE
# define VolatileErrorMessage VolatileErrorMessageW
#else
# define VolatileErrorMessage VolatileErrorMessageA
#endif

#endif/*RRWINDOWS_EXPORTS*/

#ifdef __cplusplus
}
#endif
