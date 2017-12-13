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

static int tmain(int argc, _TCHAR *argv[], _TCHAR *envp[])
{
        WSADATA data;
        int rwsas = WSAStartup(MAKEWORD(2, 2), &data);
        if (NO_ERROR != rwsas) {
                _tprintf_s(_T("'WSAStartup' failed with error %d.\n"), rwsas);
                return EXIT_FAILURE;
        }

        ADDRINFOA hints;
        ZeroMemory(&hints, sizeof hints);
        hints.ai_family = AF_UNSPEC;      // IPv4 or IPv6
        hints.ai_socktype = SOCK_STREAM;  // TCP
        hints.ai_protocol = IPPROTO_TCP;  // TCP
        PADDRINFOA info;
        int rgai = getaddrinfo("192.168.2.182", "10096", &hints, &info);
        if (NO_ERROR != rgai) {
                _tprintf_s(_T("'getaddrinfo' failed with error %d.\n"), rgai);
                WSACleanup();
                return EXIT_FAILURE;
        }

        PADDRINFOA infi;
        SOCKET skt = INVALID_SOCKET;
        for (infi = info; infi != NULL; infi = infi->ai_next) {
                if (INVALID_SOCKET == (skt = socket(infi->ai_family, infi->ai_socktype, infi->ai_protocol))) {
                        _tprintf_s(_T("'socket' failed with error %d.\n"), WSAGetLastError());
                        freeaddrinfo(info);
                        WSACleanup();
                        return EXIT_FAILURE;
                }

                if (SOCKET_ERROR == connect(skt, infi->ai_addr, infi->ai_addrlen)) {
                        _tprintf_s(_T("'connect' failed with error %d.\n"), WSAGetLastError());
                        closesocket(skt);
                        skt = INVALID_SOCKET;
                        continue;
                }

                break;
        }

        freeaddrinfo(info);

        if (INVALID_SOCKET == skt) {
                _tprintf_s(_T("Unable to connect to server.\n"));
                WSACleanup();
                return EXIT_FAILURE;
        }

        char *sendbuf = "HELLO ANOTHER";
        int rs = send(skt, sendbuf, sizeof sendbuf, 0);
        if (SOCKET_ERROR == rs) {
                _tprintf_s(_T("'send' failed with error %d.\n"), WSAGetLastError());
                closesocket(skt);
                WSACleanup();
                return EXIT_FAILURE;
        }
        printf("Bytes sent: %d\n", rs);

        char recvbuf[512];
        int rr;
        do {
                rr = recv(skt, recvbuf, sizeof recvbuf, 0);
                if (0 < rr)
                        _tprintf_s(_T("Bytes received: %d.\n"), rr);
                else if (0 == rr)
                        _tprintf_s(_T("Connection closed.\n"));
                else /*r < 0*/
                        _tprintf_s(_T("'recv' failed with error %d.\n"), WSAGetLastError());
        } while (0 < rr);

        closesocket(skt);

        WSACleanup();

        return EXIT_SUCCESS;
}

#ifdef ENTRY_SWITCH
int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) { return tmain(argc, argv, envp); }
#endif// ENTRY SWITCH
