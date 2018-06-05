/*===-- Create Folder ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gCr8Flr 创建文件夹
 * \ingroup gDirMgmt
 *
 * \version 2018-06-05
 * \since 2018-06-05
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
 * \brief 创建文件夹（ANSI适配）。
 * \param folderPath 文件夹路径，不以反斜杠结尾。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 */
RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
CreateFolderA(
    _In_z_ LPCSTR CONST folderPath);

/**
 * \brief 创建文件夹（UNICODE适配）。
 * \param folderPath 文件夹路径，不以反斜杠结尾。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 */
RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
CreateFolderW(
    _In_z_ LPCWSTR CONST folderPath);

#ifdef _UNICODE
# define CreateFolder CreateFolderW
#else
# define CreateFolder CreateFolderA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
