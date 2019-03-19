/*===-- Stream Operations --------------------------------------*- C -*-===*//**
 *
 * \defgroup gStrOpts 流操作
 * \ingroup gIssue4
 *
 * \version 2019-03-19
 * \since 2019-03-19
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <string.h>

#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>

#include <check.h>

#include "ts_issue4.h"

START_TEST(tf_ioctl)
{
    // file descriptor
    const int fd = socket(AF_INET, SOCK_DGRAM, 0);

    // interface req
    struct ifreq ifr = {};
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ - 1);

    ioctl(fd, SIOCGIFADDR, &ifr);

    close(fd);

    puts(inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}
END_TEST;

TCase *tc_stropts(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_ioctl);
    return tc;
}
