//===-- Windows Sockets 2 ---------------------------------------*- C+ -*-===//
///
/// \file
/// \brief Windows 套接字 2 版
///
/// \sa <https://docs.microsoft.com/windows/win32/winsock/windows-sockets-start-page-2>
///
/// \version 2019-07-08
/// \since 2019-01-04
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <string>
#include <vector>

#include "rrwindows/api.hxx"

namespace rrwindows {

constexpr std::size_t max_ipv4_len {15 + 1};
constexpr std::size_t max_ipv6_len {45 + 1};

/// \brief 查询“适配器－单播－网际协议”地址。
RRWINDOWS_API std::vector<std::string> RRWINDOWS_CALL query_adapter_unicast_internet_address();

}
