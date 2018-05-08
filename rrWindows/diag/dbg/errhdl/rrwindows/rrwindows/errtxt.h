/*===-- Error Text ---------------------------------------------*- C -*-===*//**
 *
 * \defgroup gErrTxt 错误文本
 * \ingroup gErrHdl
 *
 * \sa ["GetLastError function"](https://msdn.microsoft.com/library/ms679360). *Microsoft® Developer Network*.
 * \sa ["FormatMessage function"](https://msdn.microsoft.com/library/ms679351). *Microsoft® Developer Network*.
 *
 * \version 2018-05-08
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
extern "C" {
#endif

/**
 * \brief 获取错误码对应的描述字串（ANSI适配）。
 * \warning 该字串缓存在公用静态变量中，请即取即用。
 * \warning 预设的缓存尺寸可能不足。
 *
 * \returns 若成功，返回指向缓存的指针；
 *          若失败，返回空指针（`NULL`）。
 */
RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
ErrorTextOfA(
    _In_ CONST DWORD errorCode);

/**
 * \brief 获取错误码对应的描述字串（UNICODE适配）。
 * \warning 该字串缓存在公用静态变量中，请即取即用。
 * \warning 预设的缓存尺寸可能不足。
 *
 * \returns 若成功，返回指向缓存的指针；
 *          若失败，返回空指针（`NULL`）。
 */
RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
ErrorTextOfW(
    _In_ CONST DWORD errorCode);

#ifdef UNICODE
# define ErrorTextOf ErrorTextOfW
#else
# define ErrorTextOf ErrorTextOfA
#endif

#define GetLastErrorText() ErrorTextOf(GetLastError())

#ifdef __cplusplus
}
#endif

/** @} */
