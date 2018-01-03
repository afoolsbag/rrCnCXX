/** \file
 *  \author zhengrr
 *  \date 2016-12-24 – 2018-1-2
 *  \copyright The MIT License */

#include <stdio.h>

#include <tchar.h>
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

#define BUFFER_SIZE 512

int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[])
{
        int codeError;

        WSADATA dataWinSocketApp;
        SOCKADDR_IN netAddressSocket;
        SOCKET refSocket;

        /* Initializing Windows Socket
         * <https://msdn.microsoft.com/ms742213> */
        _tprintf_s(_T("Startuping windows socket..."));
        codeError = WSAStartup(MAKEWORD(2, 2), &dataWinSocketApp);
        if (NO_ERROR != codeError) {
                _tprintf_s(_T(" error, WSAStartup() failed with error %d.\n"), codeError);
                return EXIT_FAILURE;
        }
        _tprintf_s(_T(" done.\n"));


        /* Creating Socket
         * <https://msdn.microsoft.com/ms740506> */
        _tprintf_s(_T("Creating socket..."));
        refSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (INVALID_SOCKET == refSocket) {
                _tprintf_s(_T(" error, socket() failed with error %d.\n"), WSAGetLastError());
                WSACleanup();
                return EXIT_FAILURE;
        }
        _tprintf_s(_T(" done.\n"));


        /* 绑定地址
         * <https://msdn.microsoft.com/ms737550> */
        ZeroMemory(&networkSocketAddress, sizeof networkSocketAddress);
        networkSocketAddress.sin_family = AF_INET;
        networkSocketAddress.sin_addr.s_addr = htonl(INADDR_ANY);
        networkSocketAddress.sin_port = htons(10096);
        codeError = bind(
                refSocket,
                (PSOCKADDR)&networkSocketAddress,
                sizeof networkSocketAddress
        );
        if (SOCKET_ERROR == codeError) {
                _ASSERTE(codeError && FALSE);
                closesocket(refSocket);
                WSACleanup();
                return EXIT_FAILURE;
        }

        /* 收流与处理 */
        char buf[512];
        while (TRUE) {
                _tprintf_s(_T("*** Waiting for data..."));
                ZeroMemory(buf, sizeof buf);
                SOCKADDR_IN ano;
                int anolen = sizeof ano;
                int datalen;

                datalen = recvfrom(skt, buf, sizeof buf, 0, (PSOCKADDR)&ano, &anolen);
                if (SOCKET_ERROR == datalen) {
                        _tprintf_s(_T(" error, recvfrom() failed with error %d.\n"), WSAGetLastError());
                        closesocket(skt);
                        WSACleanup();
                        return EXIT_FAILURE;
                }

                _tprintf_s(_T("\n >> Received packet from %hhu.%hhu.%hhu.%hhu:%hu.\n"),
                           ano.sin_addr.s_net, ano.sin_addr.s_host, ano.sin_addr.s_lh, ano.sin_addr.s_impno, ntohs(ano.sin_port));
                _tprintf_s(_T("    Message: %s\n"), buf);

                _tprintf_s(_T("  < Sending echo..."));
                if (SOCKET_ERROR == sendto(skt, buf, datalen, 0, (PSOCKADDR)&ano, anolen)) {
                        _tprintf_s(_T(" error, sendto() failed with error %d.\n"), WSAGetLastError());
                        closesocket(skt);
                        WSACleanup();
                        return EXIT_FAILURE;
                }
                _tprintf_s(_T(" done.\n"));
        }

        /* 关闭套接字 */
        closesocket(skt);

        /* 清理 Windows Socket */
        WSACleanup();

        return EXIT_SUCCESS;
}
