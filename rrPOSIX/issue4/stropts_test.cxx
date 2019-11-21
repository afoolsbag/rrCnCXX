//===-- Stream Operations ---------------------------------------*- C++ -*-===//
///
/// \defgroup gStrOpts 流操作
/// \ingroup gIssue4
///
/// \version 2019-06-04
/// \since 2019-03-19
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdio>
#include <cstring>

#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>

#include <gtest/gtest.h>

TEST(stropts, ioctl)
{
    // file descriptor
    const auto fd = socket(AF_INET, SOCK_DGRAM, 0);

    // interface req
    ifreq ifr = {};
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ - 1);

    ioctl(fd, SIOCGIFADDR, &ifr);

    close(fd);

    puts(inet_ntoa(reinterpret_cast<sockaddr_in *>(&ifr.ifr_addr)->sin_addr));
}
