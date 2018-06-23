/*===-- Traverse Folder ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gTravFlr 遍历文件夹
 * \ingroup gFMgmt
 *
 * \version 2018-06-23
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

typedef DWORD(CALLBACK *OnFileFoundCallbackTypeA)(LPCSTR CONST path, LPWIN32_FIND_DATAA CONST pData);
typedef DWORD(CALLBACK *OnFileFoundCallbackTypeW)(LPCWSTR CONST path, LPWIN32_FIND_DATAW CONST pData);
#ifdef _UNICODE
# define OnFileFoundCallbackType OnFileFoundCallbackTypeW
#else
# define OnFileFoundCallbackType OnFileFoundCallbackTypeA
#endif

EXTERN_C_START

/**
 * \brief 遍历文件夹（ANSI适配）。
 * \param folderPath  欲遍历的文件夹路径，不以反斜杠结尾。
 * \param OnFileFound 当找到文件（文件夹）时的回调。
 * \param recurse     递归。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 *
 * \sa ["FindFirstFile function"](https://msdn.microsoft.com/library/aa364418). *Microsoft® Developer Network*.
 * \sa ["FindNextFile function"](https://msdn.microsoft.com/library/aa364428). *Microsoft® Developer Network*.
 * \sa ["FindClose function"](https://msdn.microsoft.com/library/aa364413). *Microsoft® Developer Network*.
 */
RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
TraverseFolderA(
    _In_z_                   LPCSTR CONST folderPath,
    _In_   OnFileFoundCallbackTypeA CONST OnFileFound,
    _In_                      CONST BOOL  recurse);

/**
 * \brief 遍历文件夹（UNICODE适配）。
 * \param folderPath  欲遍历的文件夹路径，不以反斜杠结尾。
 * \param OnFileFound 当找到文件（文件夹）时的回调。
 * \param recurse     递归。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 */
RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
TraverseFolderW(
    _In_z_                  LPCWSTR CONST folderPath,
    _In_   OnFileFoundCallbackTypeW CONST OnFileFound,
    _In_                      CONST BOOL  recurse);

#ifdef _UNICODE
# define TraverseFolder TraverseFolderW
#else
# define TraverseFolder TraverseFolderA
#endif

EXTERN_C_END

/** @} */
