/*===-- Access Shared Folder -----------------------------------*- C -*-===*//**
 *
 * \defgroup gAcsShrFlr 访问共享文件夹
 * \ingroup gWNet
 *
 * \version 2018-06-26
 * \since 2018-02-23
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
 * \brief 连接共享文件夹（ANSI适配）。
 *        开启访问权限。
 *
 * \param sharedFolderPath 共享文件夹路径。
 * \param username         用户名。
 * \param password         密码。
 * \returns 成功与否。
 *
 * \sa ["NETRESOURCE structure"](https://msdn.microsoft.com/library/aa385353). *MSDN*.
 * \sa ["WNetAddConnection2 function"](https://msdn.microsoft.com/library/aa385413). *MSDN*.
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL WINAPI
ConnectSharedFolderA(
    _In_z_   LPCSTR CONST sharedFolderPath,
    _In_opt_ LPCSTR CONST username,
    _In_opt_ LPCSTR CONST password);

/**
 * \brief 连接共享文件夹（UNICODE适配）。
 *        开启访问权限。
 *
 * \param sharedFolderPath 共享文件夹路径。
 * \param username         用户名。
 * \param password         密码。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ConnectSharedFolderW(
    _In_z_   LPCWSTR CONST sharedFolderPath,
    _In_opt_ LPCWSTR CONST username,
    _In_opt_ LPCWSTR CONST password);

#ifdef _UNICODE
# define ConnectSharedFolder ConnectSharedFolderW
#else
# define ConnectSharedFolder ConnectSharedFolderA
#endif

/**
 * \brief 断开共享文件夹（ANSI适配）。
 *        关闭访问权限。
 * \warning 该操作将强制关闭连接，不论连接是否正在被使用。
 *
 * \param sharedFolderPath 共享文件夹路径。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 *
 * \sa ["WNetCancelConnection2 function"](https://msdn.microsoft.com/library/aa385427). *MSDN*.
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
DisconnectSharedFolderA(
    _In_z_ CONST LPCSTR sharedFolderPath);

/**
 * \brief 断开共享文件夹（UNICODE适配）。
 *        关闭访问权限。
 * \warning 该操作将强制关闭连接，不论连接是否正在被使用。
 *
 * \param sharedFolderPath 共享文件夹路径。
 * \returns 成功返回`ERROR_SUCCESS`，失败返回错误码。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
DisconnectSharedFolderW(
    _In_z_ CONST LPCWSTR sharedFolderPath);

#ifdef _UNICODE
# define ConnectSharedFolder ConnectSharedFolderW
#else
# define ConnectSharedFolder ConnectSharedFolderA
#endif

#ifdef __cplusplus
}
#endif

/** @} */
