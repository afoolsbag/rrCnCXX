/**
 * \file
 * \author zhengrr
 * \date 2016-12-24 – 2018-1-22
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
 * \sa ["recvfrom function"](https://msdn.microsoft.com/library/ms740120). *Microsoft® Developer Network*.
 * \sa ["sendto function"](https://msdn.microsoft.com/library/ms740148). *Microsoft® Developer Network*.
 */
int _tmain(int argc, TCHAR *argv[], TCHAR *envp[])
{
	INT codeError;

	WSADATA dWsa;
	codeError = WSAStartup(MAKEWORD(2, 2), &dWsa);
	if (NO_ERROR != codeError) {
		_ftprintf_s(stderr, TEXT("WSAStartup failed with error: %d\n"), codeError);
		return EXIT_FAILURE;
	}

	ADDRINFOT aiHints;
	ZeroMemory(&aiHints, sizeof(aiHints));
	aiHints.ai_flags = AI_PASSIVE;
	aiHints.ai_family = AF_INET;
	aiHints.ai_socktype = SOCK_DGRAM;
	aiHints.ai_protocol = IPPROTO_UDP;

	ADDRINFOT *paiServer;
	codeError = GetAddrInfo(NULL, TEXT("10086"), &aiHints, &paiServer);
	if (NO_ERROR != codeError) {
		_ftprintf_s(stderr, TEXT("GetAddrInfo failed with error: %d\n"), codeError);
		WSACleanup();
		return EXIT_FAILURE;
	}

	SOCKET skt = socket(paiServer->ai_family, paiServer->ai_socktype, paiServer->ai_protocol);
	if (INVALID_SOCKET == skt) {
		_ftprintf_s(stderr, TEXT("socket failed with error: %d\n"), WSAGetLastError());
		FreeAddrInfo(paiServer);
		WSACleanup();
		return EXIT_FAILURE;
	}

	if (SOCKET_ERROR == bind(skt, paiServer->ai_addr, paiServer->ai_addrlen)) {
		_ftprintf_s(stderr, TEXT("bind failed with error: %d\n"), WSAGetLastError());
		closesocket(skt);
		FreeAddrInfo(paiServer);
		WSACleanup();
		return EXIT_FAILURE;
	}

	FreeAddrInfo(paiServer);

	CHAR bufRecv[1024];
	INT bytesRecv;
	SOCKADDR saClient;
	INT sizsaClient = sizeof(saClient);
	INT bytesSend;
	for (;;) {
		ZeroMemory(bufRecv, sizeof(bufRecv));

		bytesRecv = recvfrom(skt, bufRecv, sizeof(bufRecv), 0, &saClient, &sizsaClient);
		if (SOCKET_ERROR == bytesRecv) {
			_ftprintf_s(stderr, TEXT("recvfrom failed with error: %d\n"), WSAGetLastError());
			closesocket(skt);
			WSACleanup();
			return EXIT_FAILURE;
		}

		_tprintf_s(TEXT("New udp packet, %d bytes received:\n"), bytesRecv);

		if (AF_INET == saClient.sa_family) {
			const SOCKADDR_IN *const saIpv4 = (SOCKADDR_IN *) &saClient;
			TCHAR addrIpv4[INET_ADDRSTRLEN];
			InetNtop(saIpv4->sin_family, &saIpv4->sin_addr, addrIpv4, sizeof(addrIpv4));
			const UINT16 portIpv4 = ntohs(saIpv4->sin_port);
			_tprintf_s(TEXT(" from %s:%hu\n"), addrIpv4, portIpv4);
		} else if (AF_INET6 == saClient.sa_family) {
			const SOCKADDR_IN6 *const saIpv6 = (SOCKADDR_IN6 *) &saClient;
			TCHAR addrIpv6[INET6_ADDRSTRLEN];
			InetNtop(saIpv6->sin6_family, &saIpv6->sin6_addr, addrIpv6, sizeof(addrIpv6));
			const UINT16 portIpv6 = ntohs(saIpv6->sin6_port);
			_tprintf_s(TEXT(" from %s:%hu\n"), addrIpv6, portIpv6);
		}

		_tprintf_s(TEXT(" message: %s\n"), bufRecv);

		_putts(TEXT(" sending echo..."));

		bytesSend = sendto(skt, bufRecv, bytesRecv, 0, (SOCKADDR *) &saClient, sizsaClient);

		if (SOCKET_ERROR == bytesSend) {
			_ftprintf_s(stderr, TEXT("sendto failed with error: %d\n"), WSAGetLastError());
			closesocket(skt);
			WSACleanup();
			return EXIT_FAILURE;
		}

		_tprintf_s(TEXT(" done, %d bytes sent.\n"), bytesSend);

		_putts(TEXT(""));
	}

	closesocket(skt);
	WSACleanup();
	return EXIT_SUCCESS;
}
