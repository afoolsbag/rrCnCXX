//===-- Windows Networking --------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Windows 网络。
///
/// \sa <https://docs.microsoft.com/windows/win32/wnet/windows-networking-wnet->
///
/// \version 2019-07-08
/// \since 2018-02-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <filesystem>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 连接共享文件夹，开启访问权限。
/// \param shared_folder_path 共享文件夹路径。
/// \param username           用户名。
/// \param password           密码。
RRWINDOWS_API void RRWINDOWS_CALL connect_shared_folder(const char *shared_folder_path, const char *username, const char *password);
inline void connect_shared_folder(const std::string &shared_folder_path, const std::string &username, const std::string &password) { return connect_shared_folder(shared_folder_path.c_str(), username.c_str(), password.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL connect_shared_folder(const wchar_t *shared_folder_path, const wchar_t *username, const wchar_t *password);
inline void connect_shared_folder(const std::wstring &shared_folder_path, const std::wstring &username, const std::wstring &password) { return connect_shared_folder(shared_folder_path.c_str(), username.c_str(), password.c_str()); }

/// \brief 断开共享文件夹，关闭访问权限。
/// \warning 该操作将强制关闭连接，不论连接是否正在被使用。
/// \param shared_folder_path 共享文件夹路径。
RRWINDOWS_API void RRWINDOWS_CALL disconnect_shared_folder(const char *shared_folder_path);
inline void disconnect_shared_folder(const std::string &shared_folder_path) { return disconnect_shared_folder(shared_folder_path); }
RRWINDOWS_API void RRWINDOWS_CALL disconnect_shared_folder(const wchar_t *shared_folder_path);
inline void disconnect_shared_folder(const std::wstring &shared_folder_path) { return disconnect_shared_folder(shared_folder_path); }

}
