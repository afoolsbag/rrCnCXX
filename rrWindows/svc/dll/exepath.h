/*===-- Executable Path ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gExePath 当前进程的可执行文件路径
 * \ingroup gDLL
 *
 * \version 2018-08-22
 * \since 2018-05-08
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrWindows/rrwindowsapi.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 当前进程的可执行文件路径（ANSI 适配）。
 * \details 形如 `path\\to\\folder\\file.exe`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutablePathA(VOID);
/**
 * \brief 当前进程的可执行文件路径（UNICODE 适配）。
 * \details 形如 `path\\to\\folder\\file.exe`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
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
 * \brief 当前进程的可执行文件所在目录的路径（ANSI 适配）。
 * \details 形如 `path\\to\\folder`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableDirectoryPathA(VOID);
/**
 * \brief 当前进程的可执行文件所在目录的路径（UNICODE 适配）。
 * \details 形如 `path\\to\\folder`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
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
 * \brief 当前进程的可执行文件名（ANSI 适配）。
 * \details 形如 `file.exe`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableNameA(VOID);
/**
 * \brief 当前进程的可执行文件名（UNICODE 适配）。
 * \details 形如 `file.exe`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
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
 * \brief 当前进程的可执行文件的基础名（ANSI 适配）。
 * \details 形如 `file`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableBaseNameA(VOID);
/**
 * \brief 当前进程的可执行文件的基础名（UNICODE 适配）。
 * \details 形如 `file`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
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
 * \brief 当前进程的可执行文件的扩展名（ANSI 适配）。
 * \details 形如 `exe`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ExecutableExtensionNameA(VOID);
/**
 * \brief 当前进程的可执行文件的扩展名（UNICODE 适配）。
 * \details 形如 `exe`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
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
 * \brief 当前进程的初始化文件路径（ANSI 适配）。
 * \details 形如 `path\\to\\folder\\file.ini`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
InitializationPathA(VOID);
/**
 * \brief 当前进程的初始化文件路径（UNICODE 适配）。
 * \details 形如 `path\\to\\folder\\file.ini`。
 * \warning 该字符串缓存在共用静态变量中，请即取即用。\n
 *          预设的缓存尺寸可能不足。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
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
