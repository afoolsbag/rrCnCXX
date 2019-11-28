/// \copyright Unlicense

#pragma once
#include "error_handling.hxx"

#include <cassert>
#include <string>
#include <gsl/gsl>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace rrwindows {

inline std::string system_error_message(std::uint32_t error_code) noexcept
{
    LPSTR lpBuf = nullptr;
    CONST DWORD dwLen = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                       nullptr,
                                       static_cast<DWORD>(error_code),
                                       LANG_USER_DEFAULT,
                                       reinterpret_cast<LPSTR>(&lpBuf),
                                       0,
                                       nullptr);
    if (dwLen == 0)
        return std::string {"utility function "}.append(__FUNCTION__).append(" failed with code ").append(std::to_string(GetLastError()));
    const auto finally_local_free = gsl::finally([&] { LocalFree(lpBuf); });
    if (2 <= dwLen)
        lpBuf[dwLen - 2] = '\0';
    return lpBuf;
}

inline std::wstring system_error_wmessage(std::uint32_t error_code) noexcept
{
    LPWSTR lpBuf {nullptr};
    CONST DWORD dwLen = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                       nullptr,
                                       static_cast<DWORD>(error_code),
                                       LANG_USER_DEFAULT,
                                       reinterpret_cast<LPWSTR>(&lpBuf),
                                       0, nullptr);
    if (dwLen == 0)
        return std::wstring {L"utility function "}.append(__FUNCTIONW__).append(L" failed with code ").append(std::to_wstring(GetLastError()));
    const auto finally_local_free = gsl::finally([&] { LocalFree(lpBuf); });
    if (2 <= dwLen)
        lpBuf[dwLen - 2] = L'\0';
    return lpBuf;
}

inline std::invalid_argument invalid_argument_exception(const char *function_name)
{
    assert(function_name);
    assert(function_name[0] != '\0');
    return std::invalid_argument {std::string {"invalid argument at invoke "}.append(function_name)};
}

inline std::invalid_argument invalid_argument_exception(const std::string &function_name)
{
    assert(!function_name.empty());
    return std::invalid_argument {std::string {"invalid argument at invoke "}.append(function_name)};
}

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
