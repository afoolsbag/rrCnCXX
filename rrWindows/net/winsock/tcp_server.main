/**
 * \file
 * \sa ["Complete Winsock Server Code"](https://msdn.microsoft.com/library/ms737593). *Microsoft® Developer Network*.
 * \author zhengrr
 * \date 2016-12-23 – 2018-1-22
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

/**
 * \sa ["WSAStartup function"](https://msdn.microsoft.com/library/ms742213). *Microsoft® Developer Network*.
 * \sa ["WSACleanup function"](https://msdn.microsoft.com/library/ms741549). *Microsoft® Developer Network*.
 * \sa ["WSAGetLastError function"](https://msdn.microsoft.com/library/ms741580). *Microsoft® Developer Network*.
 * \sa ["addrinfo structure"](https://msdn.microsoft.com/library/ms737530). *Microsoft® Developer Network*.
 * \sa ["getaddrinfo function"](https://msdn.microsoft.com/library/ms738520). *Microsoft® Developer Network*.
 * \sa ["freeaddrinfo function"](https://msdn.microsoft.com/library/ms737931). *Microsoft® Developer Network*.
 * \sa ["socket function"](https://msdn.microsoft.com/library/ms740506). *Microsoft® Developer Network*.
 * \sa ["closesocket function"](https://msdn.microsoft.com/library/ms737582). *Microsoft® Developer Network*.
 * \sa ["bind function"](https://msdn.microsoft.com/library/ms737550). *Microsoft® Developer Network*.
 * \sa ["listen function"](https://msdn.microsoft.com/library/ms739168). *Microsoft® Developer Network*.
 * \sa ["accept function"](https://msdn.microsoft.com/library/ms737526). *Microsoft® Developer Network*.
 * \sa ["recv function"](https://msdn.microsoft.com/library/ms740121). *Microsoft® Developer Network*.
 * \sa ["send function"](https://msdn.microsoft.com/library/ms740149). *Microsoft® Developer Network*.
 * \sa ["shutdown function"](https://msdn.microsoft.com/library/ms740481). *Microsoft® Developer Network*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	INT codeError;

	WSADATA dWsa;
	codeError = WSAStartup(MAKEWORD(2, 2), &dWsa);
	if (NO_ERROR != codeError) {
		_ftprintf_s(stderr, TEXT("WSAStartup failed with error: %i\n"), codeError);
		return EXIT_FAILURE;
	}

	ADDRINFOT aiHints;
	ZeroMemory(&aiHints, sizeof(aiHints));
	aiHints.ai_flags = AI_PASSIVE;
	aiHints.ai_family = AF_INET;
	aiHints.ai_socktype = SOCK_STREAM;
	aiHints.ai_protocol = IPPROTO_TCP;

	ADDRINFOT *paiServer;
	codeError = GetAddrInfo(NULL, TEXT("10086"), &aiHints, &paiServer);
	if (NO_ERROR != codeError) {
		_ftprintf_s(stderr, TEXT("GetAddrInfo failed with error: %i\n"), codeError);
		WSACleanup();
		return EXIT_FAILURE;
	}

	SOCKET sktListen = socket(paiServer->ai_family, paiServer->ai_socktype, paiServer->ai_protocol);
	if (INVALID_SOCKET == sktListen) {
		_ftprintf_s(stderr, TEXT("socket failed with error: %i\n"), WSAGetLastError());
		FreeAddrInfo(paiServer);
		WSACleanup();
		return EXIT_FAILURE;
	}

	if (SOCKET_ERROR == bind(sktListen, paiServer->ai_addr, paiServer->ai_addrlen)) {
		_ftprintf_s(stderr, TEXT("bind failed with error: %i\n"), WSAGetLastError());
		closesocket(sktListen);
		FreeAddrInfo(paiServer);
		WSACleanup();
		return EXIT_FAILURE;
	}

	FreeAddrInfo(paiServer);

	if (SOCKET_ERROR == listen(sktListen, SOMAXCONN)) {
		_ftprintf_s(stderr, TEXT("listen failed with error: %i\n"), WSAGetLastError());
		closesocket(sktListen);
		WSACleanup();
		return EXIT_FAILURE;
	}

	SOCKET sktAccept = accept(sktListen, NULL, NULL);
	if (INVALID_SOCKET == sktAccept) {
		_ftprintf_s(stderr, TEXT("accept failed with error: %i\n"), WSAGetLastError());
		closesocket(sktListen);
		WSACleanup();
		return EXIT_FAILURE;
	}

	closesocket(sktListen);

	CHAR bufRecv[512];
	INT bytesRecv;
	INT bytesSend;
	for (;;) {
		bytesRecv = recv(sktAccept, bufRecv, sizeof(bufRecv), 0);

		if (SOCKET_ERROR == bytesRecv) {
			_ftprintf_s(stderr, TEXT("recv failed with error: %i\n"), WSAGetLastError());
			closesocket(sktAccept);
			WSACleanup();
			return EXIT_FAILURE;
		}

		if (0 == bytesRecv) {
			_tprintf_s(TEXT("Connection closed.\n"));
			break;
		}

		_tprintf_s(TEXT("Bytes received: %i\n"), bytesRecv);

		bytesSend = send(sktAccept, bufRecv, bytesRecv, 0);

		if (SOCKET_ERROR == bytesSend) {
			_ftprintf_s(stderr, TEXT("send failed with error: %i\n"), WSAGetLastError());
			closesocket(sktAccept);
			WSACleanup();
			return EXIT_FAILURE;
		}

		_tprintf_s(TEXT("Bytes send: %i\n"), bytesSend);
	}

	if (SOCKET_ERROR == shutdown(sktAccept, SD_SEND)) {
		_ftprintf_s(stderr, TEXT("shutdown failed with error: %i\n"), WSAGetLastError());
		closesocket(sktAccept);
		WSACleanup();
		return EXIT_FAILURE;
	}

	closesocket(sktAccept);
	WSACleanup();
	return EXIT_SUCCESS;
}
