#include "rrposix/get_local_ips.hxx"

#include <cerrno>
#include <cstring>
#include <array>
#include <memory>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <ifaddrs.h>

using namespace std;

namespace rrposix {

RRPOSIX_API if_name_addr_pair_set get_local_ips() {
    static const auto &allocifaddrs = [] {
        ifaddrs *tmp{nullptr};  // interface address(es) head
        if (getifaddrs(&tmp) != 0)
            throw runtime_error{"getifaddrs failed: "s + strerror(errno)};
        return tmp;
    };
    unique_ptr<ifaddrs, decltype(&freeifaddrs)> ifas{allocifaddrs(), &freeifaddrs};

    if_name_addr_pair_set ips;  // ip name-address pairs
    for (const auto *ifap = ifas.get(); ifap != nullptr; ifap = ifap->ifa_next) {
        switch (ifap->ifa_addr->sa_family) {
            case AF_INET: {
                array<char, INET_ADDRSTRLEN> buf{};
                const auto &name = ifap->ifa_name;
                if (!name)
                    throw runtime_error{"null name in ifaddrs."};
                const auto &address = inet_ntop(ifap->ifa_addr->sa_family,
                                                &reinterpret_cast<const sockaddr_in *>(ifap->ifa_addr)->sin_addr,
                                                buf.data(),
                                                buf.size());
                if (!address)
                    throw runtime_error{"inet_ntop failed: "s + strerror(errno)};
                ips.insert(make_pair(name, address));
                break;
            }
            case AF_INET6: {
                array<char, INET6_ADDRSTRLEN> buf{};
                const auto &name = ifap->ifa_name;
                if (!name)
                    throw runtime_error{"null name in ifaddrs."};
                const auto &address = inet_ntop(ifap->ifa_addr->sa_family,
                                                &reinterpret_cast<const sockaddr_in6 *>(ifap->ifa_addr)->sin6_addr,
                                                buf.data(),
                                                buf.size());
                if (!address)
                    throw runtime_error{"inet_ntop failed: "s + strerror(errno)};
                ips.insert(make_pair(name, address));
                break;
            }
            default:
                continue;
        }
    }
    return ips;
}

}
