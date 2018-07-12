/*===-- Version Infomation -------------------------------------*- C -*-===*//**
 *
 * \defgroup gVerInfo 版本信息
 * \ingroup gVer
 *
 * \sa <https://docs.microsoft.com/windows/desktop/api/Winver/nf-winver-getfileversioninfosizea>
 * \sa <https://docs.microsoft.com/windows/desktop/api/Winver/nf-winver-getfileversioninfoa>
 * \sa <https://docs.microsoft.com/windows/desktop/api/Winver/nf-winver-verqueryvaluea>
 *
 * \version 2018-07-12
 * \since 2018-07-12
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
 * \brief 获取指定文件版本信息（ANSI适配）。
 * \returns 成功与否。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileVersionInformationA(
    _In_z_    LPCSTR CONST filePath,
    _Out_opt_ LPWORD CONST pMajor,
    _Out_opt_ LPWORD CONST pMinor,
    _Out_opt_ LPWORD CONST pPatch,
    _Out_opt_ LPWORD CONST pTweak);

/**
 * \brief 获取指定文件版本信息（UNICODE适配）。
 * \returns 成功与否。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileVersionInformationW(
    _In_z_   LPCWSTR CONST filePath,
    _Out_opt_ LPWORD CONST pMajor,
    _Out_opt_ LPWORD CONST pMinor,
    _Out_opt_ LPWORD CONST pPatch,
    _Out_opt_ LPWORD CONST pTweak);

#ifdef _UNICODE
# define GetFileVersionInformation GetFileVersionInformationW
#else
# define GetFileVersionInformation GetFileVersionInformationA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
