/*===-- Version Infomation -------------------------------------*- C -*-===*//**
 *
 * \defgroup gVerInfo 版本信息
 * \ingroup gVer
 *
 * \sa <https://docs.microsoft.com/windows/desktop/menurc/versioninfo-resource>
 * \sa <https://docs.microsoft.com/windows/desktop/api/Winver/nf-winver-getfileversioninfosizea>
 * \sa <https://docs.microsoft.com/windows/desktop/api/Winver/nf-winver-getfileversioninfoa>
 * \sa <https://docs.microsoft.com/windows/desktop/api/Winver/nf-winver-verqueryvaluea>
 *
 * \version 2018-07-13
 * \since 2018-07-12
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
 * \brief 获取指定文件的固定信息（ANSI适配）。
 * \details Version Information > Fixed Information
 *
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 *
 * \since 2018-07-13
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileFixedInformationA(
    _In_z_          LPCSTR  CONST filePath,
    _Out_ VS_FIXEDFILEINFO *CONST pFixedInfo
);
/**
 * \brief 获取指定文件的固定信息（UNICODE适配）。
 * \details Version Information > Fixed Information
 *
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 *
 * \since 2018-07-13
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
GetFileFixedInformationW(
    _In_z_         LPCWSTR  CONST filePath,
    _Out_ VS_FIXEDFILEINFO *CONST pFixedInfo
);
#ifdef _UNICODE
# define GetFileFixedInformation GetFileFixedInformationW
#else
# define GetFileFixedInformation GetFileFixedInformationA
#endif

#ifdef __cplusplus
}
#endif

/**
 * \brief 获取指定文件的文件版本信息。
 * \details Version Information > Fixed Information > File Version Information
 *
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 * 
 * \since 2018-07-13
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI
GetFileFileVersionInformation(
    _In_z_   LPCTSTR CONST filePath,
    _Out_opt_ LPWORD CONST pMajor,
    _Out_opt_ LPWORD CONST pMinor,
    _Out_opt_ LPWORD CONST pPatch,
    _Out_opt_ LPWORD CONST pTweak)
{
    VS_FIXEDFILEINFO tmp;
    if (!GetFileFixedInformation(filePath, &tmp))
        return FALSE;
    if (NULL != pMajor)
        *pMajor = HIWORD(tmp.dwFileVersionMS);
    if (NULL != pMinor)
        *pMinor = LOWORD(tmp.dwFileVersionMS);
    if (NULL != pPatch)
        *pPatch = HIWORD(tmp.dwFileVersionLS);
    if (NULL != pTweak)
        *pTweak = LOWORD(tmp.dwFileVersionLS);
    return TRUE;
}

/**
 * \brief 获取指定文件的产品版本信息。
 * \details Version Information > Fixed Information > Product Version Information
 *
 * \returns !FALSE 成功；\n
 *           FALSE 失败，可调用`GetLastError()`获取扩展错误信息。
 * 
 * \since 2018-07-13
 */
FORCEINLINE
_Success_(return != FALSE)
BOOL
WINAPI
GetFileProductVersionInformation(
    _In_z_   LPCTSTR CONST filePath,
    _Out_opt_ LPWORD CONST pMajor,
    _Out_opt_ LPWORD CONST pMinor,
    _Out_opt_ LPWORD CONST pPatch,
    _Out_opt_ LPWORD CONST pTweak)
{
    VS_FIXEDFILEINFO tmp;
    if (!GetFileFixedInformation(filePath, &tmp))
        return FALSE;
    if (NULL != pMajor)
        *pMajor = HIWORD(tmp.dwProductVersionMS);
    if (NULL != pMinor)
        *pMinor = LOWORD(tmp.dwProductVersionMS);
    if (NULL != pPatch)
        *pPatch = HIWORD(tmp.dwProductVersionLS);
    if (NULL != pTweak)
        *pTweak = LOWORD(tmp.dwProductVersionLS);
    return TRUE;
}

/** @} */
