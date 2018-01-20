/**
 * \file
 * \sa ["Complete Winsock Client Code"](https://msdn.microsoft.com/library/ms737591). *Microsoft® Developer Network*.
 * \author zhengrr
 * \date 2016-12-23 – 2018-1-20
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
 * \sa ["connect function"](https://msdn.microsoft.com/library/ms737625). *Microsoft® Developer Network*.
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
	aiHints.ai_family = AF_INET;
	aiHints.ai_socktype = SOCK_STREAM;
	aiHints.ai_protocol = IPPROTO_TCP;

	ADDRINFOT *paiServer;
	codeError = GetAddrInfo(TEXT("127.0.0.1"), TEXT("10086"), &aiHints, &paiServer);
	if (NO_ERROR != codeError) {
		_ftprintf_s(stderr, TEXT("GetAddrInfo failed with error: %i\n"), codeError);
		WSACleanup();
		return EXIT_FAILURE;
	}

	SOCKET skt = INVALID_SOCKET;
	for (ADDRINFOT *iai = paiServer; iai != NULL; iai = iai->ai_next) {
		skt = socket(iai->ai_family, iai->ai_socktype, iai->ai_protocol);
		if (INVALID_SOCKET == skt) {
			_ftprintf_s(stderr, TEXT("socket failed with error: %i\n"), WSAGetLastError());
			WSACleanup();
			return EXIT_FAILURE;
		}

		if (SOCKET_ERROR == connect(skt, iai->ai_addr, iai->ai_addrlen)) {
			closesocket(skt);
			skt = INVALID_SOCKET;
			continue;
		}

		break;
	}

	FreeAddrInfo(paiServer);

	if (INVALID_SOCKET == skt) {
		_ftprintf_s(stderr, TEXT("Unable to connect to server!\n"));
		WSACleanup();
		return EXIT_FAILURE;
	}

	CHAR bufSend[] = "this is a test";
	INT bytesSend = send(skt, bufSend, sizeof(bufSend), 0);
	if (SOCKET_ERROR == bytesSend) {
		_ftprintf_s(stderr, TEXT("send failed with error: %i\n"), WSAGetLastError());
		closesocket(skt);
		WSACleanup();
		return EXIT_FAILURE;
	}
	_tprintf_s("Bytes sent: %i\n", bytesSend);

	CHAR bufRecv[512];
	INT bytesRecv;
	for (;;) {
		bytesRecv = recv(skt, bufRecv, sizeof(bufRecv), 0);

		if (SOCKET_ERROR == bytesRecv) {
			_ftprintf_s(stderr, TEXT("recv failed with error: %i\n"), WSAGetLastError());
			closesocket(skt);
			WSACleanup();
			return EXIT_FAILURE;
		}

		if (0 == bytesRecv) {
			_tprintf_s(TEXT("Connection closed.\n"));
			break;
		}

		_tprintf_s(TEXT("Bytes received: %i\n"), bytesRecv);
	}

	closesocket(skt);
	WSACleanup();
	return EXIT_SUCCESS;
}
