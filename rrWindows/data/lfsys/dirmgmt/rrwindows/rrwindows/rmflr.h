/*===-- Remove Folder ------------------------------------------*- C -*-===*//**
 *
 * \defgroup gRmFlr 删除文件夹
 * \ingroup gDirMgmt
 *
 * \version 2018-06-05
 * \since 2018-06-01
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
 * \brief 删除文件夹（ANSI适配）。
 * \param folderPath 文件夹路径，不以反斜杠结尾。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 */
RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
RemoveFolderA(
    _In_z_ LPCSTR CONST folderPath);

/**
 * \brief 删除文件夹（UNICODE适配）。
 * \param folderPath 文件夹路径，不以反斜杠结尾。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 */
RRWINDOWS_API _Success_(return == ERROR_SUCCESS) DWORD WINAPI
RemoveFolderW(
    _In_z_ LPCWSTR CONST folderPath);

#ifdef _UNICODE
# define RemoveFolder RemoveFolderW
#else
# define RemoveFolder RemoveFolderA
#endif

#ifdef __cplusplus
}
#endif

/** @} */