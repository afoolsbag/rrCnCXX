/*===-- Executable Path ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gExePath 当前进程的可执行文件路径
 * \ingroup gDLL
 *
 * \version 2018-06-29
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
extern "C" {;
#endif

/**
 * \brief 当前进程的可执行文件路径（ANSI适配）。
 * \details 形如`path\\to\\folder\\file.exe`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutablePathA(VOID);

/**
 * \brief 当前进程的可执行文件路径（UNICODE适配）。
 * \details 形如`path\\to\\folder\\file.exe`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutablePathW(VOID);

#ifdef _UNICODE
# define ExecutablePath ExecutablePathW
#else
# define ExecutablePath ExecutablePathA
#endif

/**
 * \brief 当前进程的可执行文件所在目录的路径（ANSI适配）。
 * \details 形如`path\\to\\folder`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableDirectoryPathA(VOID);

/**
 * \brief 当前进程的可执行文件所在目录的路径（UNICODE适配）。
 * \details 形如`path\\to\\folder`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableDirectoryPathW(VOID);

#ifdef _UNICODE
# define ExecutableDirectoryPath ExecutableDirectoryPathW
#else
# define ExecutableDirectoryPath ExecutableDirectoryPathA
#endif

/**
 * \brief 当前进程的可执行文件名（ANSI适配）。
 * \details 形如`file.exe`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableNameA(VOID);

/**
 * \brief 当前进程的可执行文件名（UNICODE适配）。
 * \details 形如`file.exe`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableNameW(VOID);

#ifdef _UNICODE
# define ExecutableName ExecutableNameW
#else
# define ExecutableName ExecutableNameA
#endif

/**
 * \brief 当前进程的可执行文件的基础名（ANSI适配）。
 * \details 形如`file`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableBaseNameA(VOID);

/**
 * \brief 当前进程的可执行文件的基础名（UNICODE适配）。
 * \details 形如`file`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableBaseNameW(VOID);

#ifdef _UNICODE
# define ExecutableBaseName ExecutableBaseNameW
#else
# define ExecutableBaseName ExecutableBaseNameA
#endif

/**
 * \brief 当前进程的可执行文件的扩展名（ANSI适配）。
 * \details 形如`exe`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableExtensionNameA(VOID);

/**
 * \brief 当前进程的可执行文件的扩展名（UNICODE适配）。
 * \details 形如`exe`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ExecutableExtensionNameW(VOID);

#ifdef _UNICODE
# define ExecutableExtensionName ExecutableExtensionNameW
#else
# define ExecutableExtensionName ExecutableExtensionNameA
#endif

/**
 * \brief 当前进程的初始化文件路径（ANSI适配）。
 * \details 形如`path\\to\\folder\\file.ini`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
InitializationPathA(VOID);

/**
 * \brief 当前进程的初始化文件路径（UNICODE适配）。
 * \details 形如`path\\to\\folder\\file.ini`。
 * \warning 该头文件内所有函数共用同一字串缓存，请依次调用、勿同时使用。
 * \since 2018-06-02
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
InitializationPathW(VOID);

#ifdef _UNICODE
# define InitializationPath InitializationPathW
#else
# define InitializationPath InitializationPathA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
