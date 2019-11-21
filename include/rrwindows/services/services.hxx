//===-- Services ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 服务。
///
/// \sa <https://docs.microsoft.com/windows/win32/rpc/rpc-start-page>
///
/// \version 2019-07-08
/// \since 2019-03-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

#include "rrwindows/api.hxx"

namespace rrwindows {

enum class service_status {
    not_exist, stopped, start_pending, stop_pending, running, continue_pending, pause_pending, paused
};

/// \brief 查询服务状态。
/// \param name 服务名。
/// \version 2019-07-07
/// \since 2019-03-29
RRWINDOWS_API service_status RRWINDOWS_CALL query_service_status(const char *name);
inline service_status query_service_status(const std::string &name) { return query_service_status(name.c_str()); }
RRWINDOWS_API service_status RRWINDOWS_CALL query_service_status(const wchar_t *name);
inline service_status query_service_status(const std::wstring &name) { return query_service_status(name.c_str()); }

/// \brief 安装服务。
/// \param name        服务标识名
/// \param display     服务展示名
/// \param description 服务描述
/// \param path        二进制文件路径
RRWINDOWS_API void RRWINDOWS_CALL install_service(const char *name, const char *display, const char *description, const char *path);
inline void install_service(const std::string &name, const std::string &display, const std::string &description, const std::filesystem::path &path) { return install_service(name.c_str(), display.c_str(), description.c_str(), path.string().c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL install_service(const wchar_t *name, const wchar_t *display, const wchar_t *description, const wchar_t *path);
inline void install_service(const std::wstring &name, const std::wstring &display, const std::wstring &description, const std::filesystem::path &path) { return install_service(name.c_str(), display.c_str(), description.c_str(), path.wstring().c_str()); }

/// \brief 启动服务。
/// \param name 服务名；
/// \param argc 参数计数；
/// \param argv 参数列表，可为 `nullptr`
/// \version 2019-07-05
/// \since 2019-03-29
RRWINDOWS_API void RRWINDOWS_CALL start_service(const char *name, std::size_t argc = 0, const char *argv[] = nullptr);
inline void start_service(const std::string &name, std::vector<std::string> args)
{
    const auto argv = std::make_unique<const char *[]>(args.size());
    for (std::size_t i = 0; i < args.size(); ++i)
        argv[i] = args[i].data();
    start_service(name.c_str(), args.size(), argv.get());
}
RRWINDOWS_API void RRWINDOWS_CALL start_service(const wchar_t *name, std::size_t argc = 0, const wchar_t *argv[] = nullptr);
inline void start_service(const std::wstring &name, std::vector<std::wstring> args)
{
    const auto argv = std::make_unique<const wchar_t *[]>(args.size());
    for (std::size_t i = 0; i < args.size(); ++i)
        argv[i] = args[i].data();
    start_service(name.c_str(), args.size(), argv.get());
}

 /// \brief 停止服务。
 /// \param name 服务名。
 /// \version 2019-07-05
 /// \since 2019-03-29
RRWINDOWS_API void RRWINDOWS_CALL stop_service(const char *name);
inline void stop_service(const std::string &name) { return stop_service(name.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL stop_service(const wchar_t *name);
inline void stop_service(const std::wstring &name) { return stop_service(name.c_str()); }


/// \brief 暂停服务。
/// \param name 服务名。
/// \version 2019-07-05
/// \since 2019-03-29
RRWINDOWS_API void RRWINDOWS_CALL pause_service(const char *name);
inline void pause_service(const std::string &name) { return pause_service(name.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL pause_service(const wchar_t *name);
inline void pause_service(const std::wstring &name) { return pause_service(name.c_str()); }


/// \brief 继续服务。
/// \param name 服务名。
/// \version 2019-07-05
/// \since 2019-03-29
RRWINDOWS_API void RRWINDOWS_CALL continue_service(const char *name);
inline void continue_service(const std::string &name) { return continue_service(name.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL continue_service(const wchar_t *name);
inline void continue_service(const std::wstring &name) { return continue_service(name.c_str()); }

/// \brief 卸载服务。
/// \param name 服务名。
/// \version 2019-07-05
/// \since 2019-03-29
RRWINDOWS_API void RRWINDOWS_CALL remove_service(const char *name);
inline void remove_service(const std::string &name) { return remove_service(name.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL remove_service(const wchar_t *name);
inline void remove_service(const std::wstring &name) { return remove_service(name.c_str()); }

}
