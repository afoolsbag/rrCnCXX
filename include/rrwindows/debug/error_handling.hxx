//===-- Error Handling ------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 错误处理。
///
/// \sa <https://docs.microsoft.com/windows/win32/debug/error-handling>
///
/// \version 2019-11-28
/// \since 2018-01-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cstdint>
#include <string>
#include <system_error>

namespace rrwindows {

/// \brief 获取系统错误码对应的错误消息。
/// \param error_code 错误码。
inline std::string system_error_message(std::uint32_t error_code) noexcept;
inline std::wstring system_error_wmessage(std::uint32_t error_code) noexcept;

/// \brief 生成无效参数异常。
/// \param function_name 函数名。
inline std::invalid_argument invalid_argument_exception(const char *function_name);
inline std::invalid_argument invalid_argument_exception(const std::string &function_name);

/// \brief 生成系统错误码对应的错误异常。
/// \param pre_description 前置描述。
/// \param error_code      错误码。
inline std::system_error system_error_exception(const char *pre_description, std::uint32_t error_code);
inline std::system_error system_error_exception(const std::string &pre_description, std::uint32_t error_code);

}

#include "error_handling.inl"
