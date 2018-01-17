/**
 * \file
 * \sa ["Complete Winsock Client Code"](https://msdn.microsoft.com/library/ms737591). *Microsoft® Developer Network*.
 * \author zhengrr
 * \date 2016-12-23 – 2018-1-17
 * \copyright The MIT License
 */

#include <stdio.h>

#include <tchar.h>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_ADDRESS "127.0.0.1"
#define DEFAULT_PORT "10096"
#define BUFFER_SIZE 512

/**
 * \sa ["WSAStartup function"](https://msdn.microsoft.com/library/ms742213). *Microsoft® Developer Network*.
 * \sa [""](https://msdn.microsoft.com/library/). *Microsoft® Developer Network*.
 */
int _tmain(int argc, TCHAR *argv[], TCHAR *envp[])
{

	/* Windows Sockets 2 API */

	WSADATA dWinsock = {0};
	if (NO_ERROR != WSAStartup(MAKEWORD(2, 2), &dWinsock))
		return EXIT_FAILURE;

	ADDRINFOT hints = {0};
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	PADDRINFOT pResult = {0};
	if (NO_ERROR != GetAddrInfo(TEXT("127.0.0.1"), TEXT("10096"), &hints, &pResult)) {
		WSACleanup();
		return EXIT_FAILURE;
	}
	
	SOCKET skt = INVALID_SOCKET;
	for (PADDRINFOT i = pResult; i != NULL; i = i->ai_next) {
		skt = socket(i->ai_family, i->ai_socktype, i->ai_protocol);
		if (INVALID_SOCKET == skt) {
			WSACleanup();
			return EXIT_FAILURE;
		}

		if (SOCKET_ERROR == connect(skt, i->ai_addr, i->ai_addrlen)) {
			closesocket(skt);
			skt = INVALID_SOCKET;
			continue;
		}

		break;
	}

	FreeAddrInfo(pResult);

	if (INVALID_SOCKET == skt) {
		WSACleanup();
		return EXIT_FAILURE;
	}

	/* 发送初始字串 */
	char *sendbuf = "this is a test";
	if (SOCKET_ERROR == send(refSocket, bufSend, sizeof bufSend, 0)) {
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
