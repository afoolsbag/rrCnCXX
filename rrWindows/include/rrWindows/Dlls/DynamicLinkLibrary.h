/*===-- Dynamic-Link Libraries ---------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 动态链接库。
 *
 * \version 2018-11-19
 * \since 2018-05-08
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 分配当前进程可执行文件路径，额外 `Count` 参数（ANSI 适配）。
 * \details 形如 `path\\to\\folder\\file.exe`。
 * \param[out] heapCount 分配的堆字符数。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PSTR
WINAPI
AllocExecutablePath_CountA(
    _Out_opt_ PSIZE_T CONST heapCount
);

/**
 * \brief 分配当前进程可执行文件路径，额外 `Count` 参数（UNICODE 适配）。
 * \details 形如 `path\\to\\folder\\file.exe`。
 * \param[out] heapCount 分配的堆字符数。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
AllocExecutablePath_CountW(
    _Out_opt_ PSIZE_T CONST heapCount
);

#ifdef _UNICODE
# define AllocExecutablePath_Count AllocExecutablePath_CountW
#else
# define AllocExecutablePath_Count AllocExecutablePath_CountA
#endif

/**
 * \brief 分配当前进程可执行文件路径（ANSI 适配）。
 * \details 形如 `path\\to\\folder\\file.exe`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCSTR
WINAPI_INLINE
AllocExecutablePathA(VOID)
{
    return AllocExecutablePath_CountA(NULL);
}

/**
 * \brief 分配当前进程可执行文件路径（UNICODE 适配）。
 * \details 形如 `path\\to\\folder\\file.exe`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCWSTR
WINAPI_INLINE
AllocExecutablePathW(VOID)
{
    return AllocExecutablePath_CountW(NULL);
}

#ifdef _UNICODE
# define AllocExecutablePath AllocExecutablePathW
#else
# define AllocExecutablePath AllocExecutablePathA
#endif

/**
 * \brief 分配当前进程可执行文件所在目录路径（ANSI 适配）。
 * \details 形如 `path\\to\\folder`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocExecutableDirectoryPathA(VOID);

/**
 * \brief 分配当前进程可执行文件所在目录路径（UNICODE 适配）。
 * \details 形如 `path\\to\\folder`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocExecutableDirectoryPathW(VOID);

#ifdef _UNICODE
# define AllocExecutableDirectoryPath AllocExecutableDirectoryPathW
#else
# define AllocExecutableDirectoryPath AllocExecutableDirectoryPathA
#endif

/**
 * \brief 分配当前进程可执行文件名，额外 `Count` 参数（ANSI 适配）。
 * \details 形如 `file.exe`。
 * \param[out] heapCount 分配的堆字符数。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PSTR
WINAPI
AllocExecutableName_CountA(
    _Out_opt_ PSIZE_T CONST heapCount
);

/**
 * \brief 分配当前进程可执行文件名，额外 `Count` 参数（UNICODE 适配）。
 * \details 形如 `file.exe`。
 * \param[out] heapCount 分配的堆字符数。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
AllocExecutableName_CountW(
    _Out_opt_ PSIZE_T CONST heapCount
);

#ifdef _UNICODE
# define AllocExecutableName_Count AllocExecutableName_CountW
#else
# define AllocExecutableName_Count AllocExecutableName_CountA
#endif

/**
 * \brief 分配当前进程可执行文件名（ANSI 适配）。
 * \details 形如 `file.exe`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCSTR
WINAPI_INLINE
AllocExecutableNameA(VOID)
{
    return AllocExecutableName_CountA(NULL);
}

/**
 * \brief 分配当前进程可执行文件名（UNICODE 适配）。
 * \details 形如 `file.exe`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
FORCEINLINE
_Success_(return != NULL)
PCWSTR
WINAPI_INLINE
AllocExecutableNameW(VOID)
{
    return AllocExecutableName_CountW(NULL);
}

#ifdef _UNICODE
# define AllocExecutableName AllocExecutableNameW
#else
# define AllocExecutableName AllocExecutableNameA
#endif

/**
 * \brief 分配当前进程可执行文件基本名（ANSI 适配）。
 * \details 形如 `file`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocExecutableBaseNameA(VOID);

/**
 * \brief 分配当前进程可执行文件基本名（UNICODE 适配）。
 * \details 形如 `file`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocExecutableBaseNameW(VOID);

#ifdef _UNICODE
# define AllocExecutableBaseName AllocExecutableBaseNameW
#else
# define AllocExecutableBaseName AllocExecutableBaseNameA
#endif

/**
 * \brief 分配当前进程可执行文件扩展名（ANSI 适配）。
 * \details 形如 `exe`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocExecutableExtensionNameA(VOID);

/**
 * \brief 分配当前进程可执行文件扩展名（UNICODE 适配）。
 * \details 形如 `exe`。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocExecutableExtensionNameW(VOID);

#ifdef _UNICODE
# define AllocExecutableExtensionName AllocExecutableExtensionNameW
#else
# define AllocExecutableExtensionName AllocExecutableExtensionNameA
#endif

/**
 * \brief 分配当前进程初始化文件路径（ANSI 适配）。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
AllocInitializationPathA(VOID);

/**
 * \brief 分配当前进程初始化文件路径（UNICODE 适配）。
 * \returns `!NULL` 成功，堆字符串指针；\n
 *           `NULL` 失败，调用 `GetLastError` 获取扩展信息。
 * \post 若函数成功，当堆字符串不再使用时，调用者有责任调用 `HeapFree` 释放资源。
 */
RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
AllocInitializationPathW(VOID);

#ifdef _UNICODE
# define AllocInitializationPath AllocInitializationPathW
#else
# define AllocInitializationPath AllocInitializationPathA
#endif

#ifdef __cplusplus
}
#endif
