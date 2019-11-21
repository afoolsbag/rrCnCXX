//===-- Version Information -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 版本信息。
///
/// \sa <https://docs.microsoft.com/windows/win32/menurc/version-information>
///
/// \version 2019-07-08
/// \since 2018-07-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <array>
#include <filesystem>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 获取指定文件的产品版本信息。
/// \details Version Information > Fixed Information > File Version Information
/// \returns std::array{major, minor, patch, tweak}
/// \version 2019-07-06
/// \since 2018-07-13
RRWINDOWS_API std::array<std::uint16_t, 4> RRWINDOWS_CALL get_file_file_version_information(const char *path);
RRWINDOWS_API std::array<std::uint16_t, 4> RRWINDOWS_CALL get_file_file_version_information(const wchar_t *path);
inline std::array<std::uint16_t, 4> get_file_file_version_information(const std::filesystem::path &path) { return get_file_file_version_information(path.c_str()); }

/// \brief 获取指定文件的产品版本信息。
/// \details Version Information > Fixed Information > Product Version Information
/// \returns std::array{major, minor, patch, tweak}
/// \version 2019-07-02
/// \since 2018-07-13
RRWINDOWS_API std::array<std::uint16_t, 4> RRWINDOWS_CALL get_file_product_version_information(const char *path);
RRWINDOWS_API std::array<std::uint16_t, 4> RRWINDOWS_CALL get_file_product_version_information(const wchar_t *path);
inline std::array<std::uint16_t, 4> get_file_product_version_information(const std::filesystem::path &path) { return get_file_product_version_information(path.c_str()); }

}
