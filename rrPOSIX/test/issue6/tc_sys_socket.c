/*===-- Berkeley Sockets ---------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 伯克利套接字。
 *
 * \version 2019-03-19
 * \since 2019-02-15
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>

#include <check.h>

#include "ts_issue6.h"

/**
 * \brief 配置套接字地址。
 * \param[in]  af   地址族（address family）
 * \param[in]  addr 地址，若为空则指定为任意（any），若为 `loopback`
 * \param[in]  port 端口
 * \param[out] dst  套接字地址指针（socket address pointer）
 * \returns `-1` 失败\n
 *           `0` 成功
 */
static int inet_conf(const sa_family_t af, const char *addr, const uint16_t port, struct sockaddr *const dst)
{
    if (!dst) {
        errno = EINVAL;
        return -1;
    }
    memset(dst, 0, sizeof(struct sockaddr));

    switch (af) {
    case AF_INET: {
        struct sockaddr_in *const rp = (struct sockaddr_in *)dst;
        rp->sin_family = af;
        rp->sin_port = htons(port);
        if (!addr || !strcmp(addr, "any")) {
            rp->sin_addr.s_addr = htonl(INADDR_ANY);
        } else if (!strcmp(addr, "loopback")) {
            rp->sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        } else {
            const int t = inet_pton(af, addr, &rp->sin_addr.s_addr);
            if (t == -1)
                return -1;
            if (t == 0) {
                errno = EINVAL;
                return -1;
            }
        }
        return 0;
    }
    case AF_INET6: {
        struct sockaddr_in6 *const rp = (struct sockaddr_in6 *)dst;
        rp->sin6_family = af;
        rp->sin6_port = htons(port);
        if (!addr || !strcmp(addr, "any")) {
            rp->sin6_addr = in6addr_any;
        } else if (!strcmp(addr, "loopback")) {
            rp->sin6_addr = in6addr_loopback;
        } else {
            const int t = inet_pton(af, addr, &rp->sin6_addr);
            if (t == -1)
                return -1;
            if (t == 0) {
                errno = EINVAL;
                return -1;
            }
        }
        return 0;
    }
    default:
        errno = EAFNOSUPPORT;
        return -1;
    }
}

/**
 * \brief 从套接字地址中解析出地址和端口。
 * \param[in]  src   套接字地址指针。
 * \param[out] addrp 地址指针。
 * \param[in]  addrs 地址尺寸。
 * \param[out] portp 端口指针。
 * \returns `-1` 失败\n
 *           `0` 成功
 */
static int inet_conv(const struct sockaddr *const src, char *const addrp, const socklen_t addrs, uint16_t *const portp)
{
    if (!src) {
        errno = EINVAL;
        return -1;
    }

    switch (src->sa_family) {
    case AF_INET: {
        struct sockaddr_in *const rp = (struct sockaddr_in *)src;
        if (portp)
            *portp = ntohs(rp->sin_port);
        if (addrp)
            if (!inet_ntop(rp->sin_family, &rp->sin_addr.s_addr, addrp, addrs))
                return -1;
        return 0;
    }
    case AF_INET6: {
        struct sockaddr_in6 *const rp = (struct sockaddr_in6 *)src;
        if (portp)
            *portp = ntohs(rp->sin6_port);
        if (addrp)
            if (!inet_ntop(rp->sin6_family, &rp->sin6_addr, addrp, addrs))
                return -1;
        return 0;
    }
    default:
        errno = EAFNOSUPPORT;
        return -1;
    }
}

static const int tcp_server_domain = PF_INET6;
static const uint16_t tcp_server_port = 49152;
static const int tcp_client_domain = PF_INET;

static int tcp_server_accept(const int fd)
{
    bool error = true;

    struct sockaddr src;
    socklen_t src_len = sizeof src;
    const int con = accept(fd, (struct sockaddr *)&src, &src_len);
    if (con == -1) {
        perror("accept() failed");
        goto exit;
    }

    char src_addr[INET6_ADDRSTRLEN];
    uint16_t src_port;
    if (inet_conv(&src, src_addr, sizeof src_addr, &src_port) == -1) {
        perror("inet_conv() failed");
        goto exit_close_con;
    }

    struct sockaddr cur;
    socklen_t cur_len = sizeof cur;
    if (getsockname(con, &cur, &cur_len) == -1) {
        perror("getsockname() failed");
        goto exit_close_con;
    }

    char cur_addr[INET6_ADDRSTRLEN];
    uint16_t cur_port;
    if (inet_conv(&cur, cur_addr, sizeof cur_addr, &cur_port) == -1) {
        perror("inet_conv() failed");
        goto exit_close_con;
    }

    char recv_buf[256];
    if (recv(con, recv_buf, sizeof recv_buf, 0) == -1) {
        perror("recv() failed");
        goto exit_close_con;
    }
    printf("[%s:%hu << %s:%hu] %s\n", cur_addr, cur_port, src_addr, src_port, recv_buf);

    char send_buf[] = "欢迎";
    if (send(con, send_buf, sizeof send_buf, 0) == -1) {
        perror("send() failed");
        goto exit_close_con;
    }
    printf("[%s:%hu >> %s:%hu] %s\n", cur_addr, cur_port, src_addr, src_port, send_buf);

    error = false;

exit_close_con:
    shutdown(con, SHUT_RDWR);
    close(con);
exit:
    if (error)
        return -1;
    return 0;
}

static void *tcp_server_func(void *data)
{
    const int skt = socket(tcp_server_domain, SOCK_STREAM, IPPROTO_TCP);
    if (skt == -1) {
        perror("skcket() failed");
        goto exit;
    }

    struct sockaddr lis;
    if (inet_conf(tcp_server_domain, "any", tcp_server_port, &lis) == -1) {
        perror("inet_conf() failed");
        goto exit_close_skt;
    }

    if (bind(skt, &lis, sizeof lis) == -1) {
        perror("bind() failed");
        goto exit_close_skt;
    }

    if (listen(skt, 10) == -1) {
        perror("listen() failed");
        goto exit_close_skt;
    }

    while (true) {
        tcp_server_accept(skt);
        break;
    }

exit_close_skt:
    close(skt);
exit:
    return NULL;
}

static void *tcp_client_func(void *data)
{
    const int skt = socket(tcp_client_domain, SOCK_STREAM, IPPROTO_TCP);
    if (skt == -1) {
        perror("skcket() failed");
        goto exit;
    }

    struct sockaddr dst;
    if (inet_conf(tcp_client_domain, "loopback", tcp_server_port, &dst) == -1) {
        perror("inet_conf() failed");
        goto exit_close_skt;
    }

    char dst_addr[INET_ADDRSTRLEN < INET6_ADDRSTRLEN ? INET6_ADDRSTRLEN : INET_ADDRSTRLEN];
    uint16_t dst_port;
    if (inet_conv(&dst, dst_addr, sizeof dst_addr, &dst_port) == -1) {
        perror("inet_conv() failed");
        goto exit_close_skt;
    }

    if (connect(skt, (const struct sockaddr *)&dst, sizeof dst) == -1) {
        perror("connect() failed");
        goto exit_close_skt;
    }

    struct sockaddr src;
    socklen_t len = sizeof src;
    if (getsockname(skt, &src, &len) == -1) {
        perror("getsockname() failed");
        goto exit_shutdown_skt;
    }

    char src_addr[INET_ADDRSTRLEN < INET6_ADDRSTRLEN ? INET6_ADDRSTRLEN : INET_ADDRSTRLEN];
    uint16_t src_port;
    if (inet_conv(&src, src_addr, sizeof src_addr, &src_port) == -1) {
        perror("inet_conv() failed");
        goto exit_shutdown_skt;
    }

    const char send_buf[] = "你好";
    if (send(skt, send_buf, sizeof send_buf, 0) == -1) {
        perror("send() failed");
        goto exit_shutdown_skt;
    }
    printf("[%s:%hu >> %s:%hu] %s\n", src_addr, src_port, dst_addr, dst_port, send_buf);

    char recv_buf[256];
    if (recv(skt, recv_buf, sizeof recv_buf, 0) == -1) {
        perror("recv() failed");
        goto exit_shutdown_skt;
    }
    printf("[%s:%hu >> %s:%hu] %s\n", src_addr, src_port, dst_addr, dst_port, recv_buf);

exit_shutdown_skt:
    shutdown(skt, SHUT_RDWR);
exit_close_skt:
    close(skt);
exit:
    return NULL;
}

START_TEST(tf_tcp)
{
    pthread_t thrd_server;
    ck_assert(!pthread_create(&thrd_server, NULL, tcp_server_func, NULL));

    pthread_t thrd_client;
    ck_assert(!pthread_create(&thrd_client, NULL, tcp_client_func, NULL));

    ck_assert(!pthread_join(thrd_server, NULL));
    ck_assert(!pthread_join(thrd_client, NULL));
}
END_TEST;

static const int udp_server_domain = PF_INET6;
static const uint16_t udp_server_port = 49153;
static const int udp_client_domain = PF_INET;

static void *udp_server_func(void *data)
{
    const int skt = socket(udp_server_domain, SOCK_DGRAM, IPPROTO_UDP);
    if (skt == -1) {
        perror("skcket() failed");
        goto exit;
    }

    struct sockaddr lis;
    if (inet_conf(udp_server_domain, "any", udp_server_port, &lis) == -1) {
        perror("inet_conf() failed");
        goto exit_close_skt;
    }

    char lis_addr[INET6_ADDRSTRLEN];
    uint16_t lis_port;
    if (inet_conv(&lis, lis_addr, sizeof lis_addr, &lis_port) == -1) {
        perror("inet_conv() failed");
        goto exit_close_skt;
    }

    if (bind(skt, &lis, sizeof lis) == -1) {
        perror("bind() failed");
        goto exit_close_skt;
    }

    while (true) {
        char recv_buf[65535];
        struct sockaddr src;
        socklen_t len = sizeof src;
        if (recvfrom(skt, recv_buf, sizeof recv_buf, 0, &src, &len) == -1) {
            perror("recvfrom() failed");
            goto exit_close_skt;
        }

        char src_addr[INET6_ADDRSTRLEN];
        uint16_t src_port;
        if (inet_conv(&src, src_addr, sizeof src_addr, &src_port) == -1) {
            perror("inet_conv() failed");
            goto exit_close_skt;
        }

        printf("[%s:%hu << %s:%hu] %s\n", lis_addr, lis_port, src_addr, src_port, recv_buf);

        break;
    }

exit_close_skt:
    close(skt);
exit:
    return NULL;
}

static void *udp_client_func(void *data)
{
    const int skt = socket(udp_client_domain, SOCK_DGRAM, IPPROTO_UDP);
    if (skt == -1) {
        perror("skcket() failed");
        goto exit;
    }

    struct sockaddr dst;
    if (inet_conf(tcp_client_domain, "loopback", udp_server_port, &dst) == -1) {
        perror("inet_conf() failed");
        goto exit_close_skt;
    }
    char dst_addr[INET_ADDRSTRLEN < INET6_ADDRSTRLEN ? INET6_ADDRSTRLEN : INET_ADDRSTRLEN];
    uint16_t dst_port;
    if (inet_conv(&dst, dst_addr, sizeof dst_addr, &dst_port) == -1) {
        perror("inet_conv() failed");
        goto exit_close_skt;
    }

    const char send_buf[] = "D.Va 爱你哟～";
    if (sendto(skt, send_buf, sizeof send_buf, 0, (struct sockaddr *)&dst, sizeof dst) == -1) {
        perror("sendto() failed");
        goto exit_close_skt;
    }
    printf("[? >> %s:%hu] %s\n", dst_addr, dst_port, send_buf);

exit_close_skt:
    close(skt);
exit:
    return NULL;
}

START_TEST(tf_udp)
{
    pthread_t thrd_server;
    ck_assert(!pthread_create(&thrd_server, NULL, udp_server_func, NULL));

    pthread_t thrd_client;
    ck_assert(!pthread_create(&thrd_client, NULL, udp_client_func, NULL));

    ck_assert(!pthread_join(thrd_server, NULL));
    ck_assert(!pthread_join(thrd_client, NULL));
}
END_TEST;

TCase *tc_sys_socket(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_tcp);
    tcase_add_test(tc, tf_udp);
    return tc;
}
