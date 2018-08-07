/*===-- Folder Free Space --------------------------------------*- C -*-===*//**
 *
 * \defgroup gFlrFS 文件夹可用空间。
 * \ingroup gFMgmt
 *
 * \version 2018-06-29
 * \since 2018-01-15
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

RRWINDOWS_API
_Success_(return != 0)
ULARGE_INTEGER
WINAPI
GetFolderFreeSpaceA(
    _In_z_ LPCSTR CONST folderPath);

RRWINDOWS_API
_Success_(return != 0)
ULARGE_INTEGER
WINAPI
GetFolderFreeSpaceW(
    _In_z_ LPCWSTR CONST folderPath);

#ifdef _UNICODE
# define GetFolderFreeSpace GetFolderFreeSpaceW
#else
# define GetFolderFreeSpace GetFolderFreeSpaceA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
