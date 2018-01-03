/** \file
 *  \author zhengrr
 *  \date 2016-12-23 – 26
 *  \copyright The MIT License
 */
#include <stdio.h>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <tchar.h>

#pragma comment(lib, "Ws2_32.lib")

static USHORT get_in_port(PSOCKADDR addr)
{
        if (AF_INET == addr->sa_family)
                return ((PSOCKADDR_IN)addr)->sin_port;
        else if (AF_INET6 == addr->sa_family)
                return ((PSOCKADDR_IN6)addr)->sin6_port;
        else
                return -1;
}

static int tmain(int argc, _TCHAR *argv[], _TCHAR *envp[])
{
        /* 启动 Windows Socket */
        WSADATA data;
        int rwsas = WSAStartup(MAKEWORD(2, 2), &data);  // Result of WSAStartup
        if (NO_ERROR != rwsas) {
                _tprintf_s(_T("'WSAStartup' failed with error %d.\n"), rwsas);
                return EXIT_FAILURE;
        }

        /* 确定监听套接字信息 */
        ADDRINFOA hints;
        ZeroMemory(&hints, sizeof hints);
        hints.ai_family = AF_INET;        // IPv4
        hints.ai_socktype = SOCK_STREAM;  // TCP
        hints.ai_protocol = IPPROTO_TCP;  // TCP
        hints.ai_flags = AI_PASSIVE;
        PADDRINFOA info;
        int rgai = getaddrinfo(NULL, "10096", &hints, &info);
        if (NO_ERROR != rgai) {
                _tprintf_s(_T("'getaddrinfo' failed with error %d.\n"), rgai);
                WSACleanup();
                return EXIT_FAILURE;
        }

        /* 创建监听套接字 */
        SOCKET lskt;  // listening socket
        if (INVALID_SOCKET == (lskt = socket(info->ai_family, info->ai_socktype, info->ai_protocol))) {
                _tprintf_s(_T("'socket' failed with error %d.\n"), WSAGetLastError());
                freeaddrinfo(info);
                WSACleanup();
                return EXIT_FAILURE;
        }

        /* 监听套接字绑定地址与端口 */
        if (SOCKET_ERROR == bind(lskt, info->ai_addr, info->ai_addrlen)) {
                _tprintf_s(_T("'bind' failed with error %d.\n"), WSAGetLastError());
                closesocket(lskt);
                freeaddrinfo(info);
                WSACleanup();
                return EXIT_FAILURE;
        }
        _tprintf_s(_T("Listen to port %d is ready.\n"), ntohs(get_in_port(info->ai_addr)));

        freeaddrinfo(info);  // 释放监听套接字信息

        /* 监听套接字开始监听 */
        if (SOCKET_ERROR == listen(lskt, SOMAXCONN)) {
                _tprintf_s(_T("'listen' failed with error %d.\n"), WSAGetLastError());
                closesocket(lskt);
                WSACleanup();
                return EXIT_FAILURE;
        }

        /* 创建收容套接字，调用收容函数，阻塞并等待套接字请求 */
        SOCKET askt;  // accept socket
        if (INVALID_SOCKET == (askt = accept(lskt, NULL, NULL))) {
                _tprintf_s(_T("'accept' failed with error %d.\n"), WSAGetLastError());
                closesocket(lskt);
                WSACleanup();
                return EXIT_FAILURE;
        }
        _tprintf_s(_T("A new request has arrived.\n"));

        closesocket(lskt);

        char recvbuf[512];
        int rr;
        do {
                rr = recv(askt, recvbuf, sizeof recvbuf, 0);
                if (0 < rr) {
                        printf("Bytes received: %d.\n", rr);
                        int rs = send(askt, recvbuf, rr, 0);
                        if (SOCKET_ERROR == rs) {
                                printf("'send' failed with error %d.\n", WSAGetLastError());
                                closesocket(askt);
                                WSACleanup();
                                return EXIT_FAILURE;
                        }
                        printf("Bytes sent: %d\n", rs);
                } else if (rr == 0) {
                        printf("Connection closed.\n");
                } else {
                        printf("'recv' failed with error %d.\n", WSAGetLastError());
                        closesocket(askt);
                        WSACleanup();
                        return 1;
                }
        } while (rr > 0);

        /* 断开连接并关闭套接字 */
        if (SOCKET_ERROR == shutdown(askt, SD_SEND)) {
                printf("'shutdown' failed with error %d.\n", WSAGetLastError());
                closesocket(askt);
                WSACleanup();
                return 1;
        }

        closesocket(askt);

        WSACleanup();

        return EXIT_SUCCESS;
}

#ifdef ENTRY_SWITCH
int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) { return tmain(argc, argv, envp); }
#endif// ENTRY SWITCH
