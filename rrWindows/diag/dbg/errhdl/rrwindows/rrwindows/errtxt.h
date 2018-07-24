/*===-- Error Text ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gErrTxt 错误文本
 * \ingroup gErrHdl
 *
 * \sa ["GetLastError function"](https://msdn.microsoft.com/library/ms679360). *MSDN*.
 * \sa ["FormatMessage function"](https://msdn.microsoft.com/library/ms679351). *MSDN*.
 *
 * \version 2018-07-24
 * \since 2018-01-15
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
 * \brief 获取错误码对应的描述字符串（ANSI适配）。
 * \warning 该字符串缓存在公用静态变量中，请即取即用。
 * \warning 预设的缓存尺寸可能不足。
 *
 * \param errorCode 错误码。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ErrorTextOfA(
    _In_ CONST DWORD errorCode
);
/**
 * \brief 获取错误码对应的描述字符串（UNICODE适配）。
 * \warning 该字符串缓存在公用静态变量中，请即取即用。
 * \warning 预设的缓存尺寸可能不足。
 *
 * \param errorCode 错误码。
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ErrorTextOfW(
    _In_ CONST DWORD errorCode
);
#ifdef _UNICODE
# define ErrorTextOf ErrorTextOfW
#else
# define ErrorTextOf ErrorTextOfA
#endif

#ifdef __cplusplus
}
#endif

/**
 * \brief 获取当前线程最新错误的描述字符串。
 * \warning 该字符串缓存在公用静态变量中，请即取即用。
 * \warning 预设的缓存尺寸可能不足。
 *
 * \returns !NULL 字符串指针；\n
 *           NULL 失败。
 */
FORCEINLINE
_Success_(return != NULL)
LPCTSTR
WINAPI_INLINE
GetLastErrorText(VOID)
{
    return ErrorTextOf(GetLastError());
}

/** @} */
