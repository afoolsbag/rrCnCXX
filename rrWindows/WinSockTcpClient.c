/** \file
 *  \author zhengrr
 *  \date 2016-12-23 – 2018-1-2
 *  \copyright The MIT License */

#include <stdio.h>

#include <tchar.h>

#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_ADDRESS "127.0.0.1"
#define DEFAULT_PORT "10096"
#define BUFFER_SIZE 512

int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[])
{
    int codeError;

    WSADATA dataWinsock;                // data of windows socket
    ADDRINFOA hintsAddrInfo;            // hints of address information
    PADDRINFOA pAddrInfo = NULL;        // pointer of address information
    PADDRINFOA iAddrInfo = NULL;        // iterator of address information
    SOCKET refSocket = INVALID_SOCKET;  // descriptor referencing of socket
    char *bufSend = "Hello another.";   // buffer of send
    int numBytesSend;                   // number of bytes send
    char bufRecv[BUFFER_SIZE];          // buffer of receive
    int sizeBufRecv;                    // size of buffer receive
    int numBytesRecv;                   // number of bytes receive


    ADDRINFOA hintAddrInfo;


    /* 初始化套接字 */
    _tprintf_s(_T("Startuping windows socket..."));
    codeError = WSAStartup(MAKEWORD(2, 2), &dataWinsock);
    if (codeError != NO_ERROR) {
        _tprintf_s(_T(" error, WSAStartup() failed with error %d."), codeError);
        return EXIT_FAILURE;
    }
    _tprintf_s(_T(" done.\n"));


    /* 获取服务器地址与端口 */
    ZeroMemory(&hintsAddrInfo, sizeof hintsAddrInfo);
    hintsAddrInfo.ai_family = AF_UNSPEC;      // IPv4 or IPv6
    hintsAddrInfo.ai_socktype = SOCK_STREAM;  // TCP
    hintsAddrInfo.ai_protocol = IPPROTO_TCP;  // TCP
    codeError = getaddrinfo(DEFAULT_ADDRESS, DEFAULT_PORT, &hintsAddrInfo,
                            &pAddrInfo);
    if (codeError != NO_ERROR) {
        _tprintf_s(_T("'getaddrinfo' failed with error %d.\n"), codeError);
        WSACleanup();
        return EXIT_FAILURE;
    }

    /* 尝试连接，直至有一例成功 */
    for (iAddrInfo = pAddrInfo;
         iAddrInfo != NULL; iAddrInfo = iAddrInfo->ai_next) {
        refSocket = socket(iAddrInfo->ai_family, iAddrInfo->ai_socktype,
                           iAddrInfo->ai_protocol);
        if (refSocket == INVALID_SOCKET) {
            _tprintf_s(_T("'socket' failed with error %d.\n"),
                       WSAGetLastError());
            freeaddrinfo(pAddrInfo);
            WSACleanup();
            return EXIT_FAILURE;
        }

        codeError = connect(refSocket, iAddrInfo->ai_addr,
                            iAddrInfo->ai_addrlen);
        if (codeError == SOCKET_ERROR) {
            _tprintf_s(_T("'connect' failed with error %d.\n"), codeError);
            closesocket(refSocket);
            refSocket = INVALID_SOCKET;
            continue;
        }

        break;
    }

    freeaddrinfo(pAddrInfo);

    if (refSocket == INVALID_SOCKET) {
        _tprintf_s(_T("Unable to connect to server.\n"));
        WSACleanup();
        return EXIT_FAILURE;
    }

    /* 发送初始字串 */
    numBytesSend = send(refSocket, bufSend, sizeof bufSend, 0);
    if (numBytesSend == SOCKET_ERROR) {
        _tprintf_s(_T("'send' failed with error %d.\n"), numBytesSend);
        closesocket(refSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }
    printf("Bytes sent: %d\n", numBytesSend);

    do {
        numBytesRecv = recv(skt, bufRecv, sizeof recvbuf, 0);
        if (0 < rr)
            _tprintf_s(_T("Bytes received: %d.\n"), rr);
        else if (0 == rr)
            _tprintf_s(_T("Connection closed.\n"));
        else /*r < 0*/
            _tprintf_s(_T("'recv' failed with error %d.\n"),
                       WSAGetLastError());
    } while (0 < rr);

    closesocket(skt);

    WSACleanup();

    return EXIT_SUCCESS;
}
