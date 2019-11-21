#pragma once

#include <set>
#include <string>
#include <utility>

#include "rrposix/api.hxx"

namespace rrposix {

/// \brief 网络接口“名－地址”对（network interface name-address pair）
using if_name_addr_pair = std::pair<std::string, std::string>;
/// \brief 网络接口“名－地址”对集（network interface name-address pair set）
using if_name_addr_pair_set = std::set<if_name_addr_pair>;

/// \brief 获取本机 IP 集。
RRPOSIX_API if_name_addr_pair_set get_local_ips();

}
