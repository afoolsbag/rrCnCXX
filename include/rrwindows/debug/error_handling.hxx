//===-- Error Handling ------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 错误处理。
///
/// \sa <https://docs.microsoft.com/windows/win32/debug/error-handling>
///
/// \version 2019-07-08
/// \since 2018-01-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cassert>
#include <cstdint>
#include <string>
#include <system_error>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 获取系统错误码对应的错误消息。
/// \param error_code      错误码。
RRWINDOWS_API std::string RRWINDOWS_CALL system_error_message(std::uint32_t error_code) noexcept;
RRWINDOWS_API std::wstring RRWINDOWS_CALL system_error_wmessage(std::uint32_t error_code) noexcept;

/// \brief 生成无效参数异常。
/// \param function_name 函数名。
inline std::invalid_argument invalid_argument_exception(const char *function_name)
{
    assert(function_name);
    assert(function_name[0] != '\0');
    return std::invalid_argument {std::string("invalid argument at invoke ").append(function_name)};
}
inline std::invalid_argument invalid_argument_exception(const std::string &function_name)
{
    assert(!function_name.empty());
    return std::invalid_argument {std::string("invalid argument at invoke ").append(function_name)};
}

/// \brief 生成系统错误码对应的错误异常。
/// \param pre_description 前置描述。
/// \param error_code      错误码。
inline std::system_error system_error_exception(const char *pre_description, std::uint32_t error_code)
{
    assert(pre_description);
    return std::system_error {static_cast<int>(error_code), std::system_category(), pre_description};
}
inline std::system_error system_error_exception(const std::string &pre_description, std::uint32_t error_code)
{
    return std::system_error {static_cast<int>(error_code), std::system_category(), pre_description};
}

}
