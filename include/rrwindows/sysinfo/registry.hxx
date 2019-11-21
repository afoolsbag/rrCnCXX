//===-- Registry ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 注册表。
///
/// \sa <https://docs.microsoft.com/windows/win32/sysinfo/registry>
///
/// \version 2019-07-08
/// \since 2018-01-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <string>
#include <filesystem>

#include "rrwindows/api.hxx"

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL write_ini(const char *path, const char *section, const char *key, const char *value);
inline void write_ini(const std::filesystem::path &path, const std::string &section, const std::string &key, const std::string &value) { return write_ini(path.string().c_str(), section.c_str(), key.c_str(), value.c_str()); }
RRWINDOWS_API void RRWINDOWS_CALL write_ini(const wchar_t *path, const wchar_t *section, const wchar_t *key, const wchar_t *value);
inline void write_ini(const std::filesystem::path &path, const std::wstring &section, const std::wstring &key, const std::wstring &value) { return write_ini(path.wstring().c_str(), section.c_str(), key.c_str(), value.c_str()); }

RRWINDOWS_API std::string RRWINDOWS_CALL read_ini(const char *path, const char *section, const char *key, const char *default_value);
inline std::string read_ini(const std::filesystem::path &path, const std::string &section, const std::string &key, const std::string &default_value) { return read_ini(path.string().c_str(), section.c_str(), key.c_str(), default_value.c_str()); }
RRWINDOWS_API std::wstring RRWINDOWS_CALL read_ini(const wchar_t *path, const wchar_t *section, const wchar_t *key, const wchar_t *default_value);
inline std::wstring read_ini(const std::filesystem::path &path, const std::wstring &section, const std::wstring &key, const std::wstring &default_value) { return read_ini(path.wstring().c_str(), section.c_str(), key.c_str(), default_value.c_str()); }

RRWINDOWS_API int RRWINDOWS_CALL read_ini(const char *path, const char *section, const char *key, int default_value);
inline int read_ini(const std::filesystem::path &path, const std::string &section, const std::string &key, int default_value) { return read_ini(path.string().c_str(), section.c_str(), key.c_str(), default_value); }
RRWINDOWS_API int RRWINDOWS_CALL read_ini(const wchar_t *path, const wchar_t *section, const wchar_t *key, int default_value);
inline int read_ini(const std::filesystem::path &path, const std::wstring &section, const std::wstring &key, int default_value) { return read_ini(path.wstring().c_str(), section.c_str(), key.c_str(), default_value); }

}
