/** \file
 *  \author zhengrr
 *  \date 2016-12-24 – 26
 *  \copyright The MIT License
 */
#include <stdio.h>

#include <WinSock2.h>
#include <tchar.h>
#include <minwinbase.h>

#pragma comment(lib, "Ws2_32.lib")

static int tmain(int argc, _TCHAR *argv[], _TCHAR *envp[])
{
        _tprintf_s(_T("*** Startuping windows socket..."));
        WSADATA data;
        int rwsas = WSAStartup(MAKEWORD(2, 2), &data);  // Result of WSAStartup
        if (NO_ERROR != rwsas) {
                _tprintf_s(_T(" error, WSAStartup() failed with error %d.\n"), rwsas);
                return EXIT_FAILURE;
        }
        _tprintf_s(_T(" done.\n"));

        _tprintf_s(_T("*** Creating socket..."));
        SOCKET skt = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (INVALID_SOCKET == skt) {
                _tprintf_s(_T(" error, socket() failed with error %d.\n"), WSAGetLastError());
                WSACleanup();
                return EXIT_FAILURE;
        }
        _tprintf_s(_T(" done.\n"));

        SOCKADDR_IN addr;
        ZeroMemory(&addr, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_port = htons(10096);
        int addrlen = sizeof addr;

        char buf[512];
        while (TRUE) {
                _tprintf_s(_T("*** New session:\n"));
                ZeroMemory(buf, sizeof buf);
                _tprintf_s(_T("    Please enter a message: "));
                gets_s(buf, sizeof buf);

                _tprintf_s(_T(" << Sending packet to %hhu.%hhu.%hhu.%hhu:%hu..."),
                           addr.sin_addr.s_net, addr.sin_addr.s_host, addr.sin_addr.s_lh, addr.sin_addr.s_impno, ntohs(addr.sin_port));
                if (SOCKET_ERROR == sendto(skt, buf, strlen(buf), 0, (PSOCKADDR)&addr, addrlen)) {
                        _tprintf_s(_T(" error, sendto() failed with error %d.\n"), WSAGetLastError());
                        closesocket(skt);
                        WSACleanup();
                        return EXIT_FAILURE;
                }
                _tprintf_s(_T(" done.\n"));

                _tprintf_s(_T("    Waiting for echo..."));
                ZeroMemory(buf, sizeof buf);
                if (SOCKET_ERROR == recvfrom(skt, buf, sizeof buf, 0, (PSOCKADDR)&addr, &addrlen)) {
                        _tprintf_s(_T(" error, recvfrom() failed with error %d.\n"), WSAGetLastError());
                        closesocket(skt);
                        WSACleanup();
                        return EXIT_FAILURE;
                }
                _tprintf_s(_T("\n  > Received packet from %hhu.%hhu.%hhu.%hhu:%hu\n"),
                           addr.sin_addr.s_net, addr.sin_addr.s_host, addr.sin_addr.s_lh, addr.sin_addr.s_impno, ntohs(addr.sin_port));
                _tprintf_s(_T("    Echo message: %s\n"), buf);
        }

        closesocket(skt);

        WSACleanup();

        return EXIT_SUCCESS;
}

#ifdef ENTRY_SWITCH
int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) { return tmain(argc, argv, envp); }
#endif// ENTRY SWITCH
