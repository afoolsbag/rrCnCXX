#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "WS2_32.Lib")

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsWinSock.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/**
 * \addtogroup gWinSock
 * @{
 */

static BOOL ConsoleOutput(PCTSTR CONST msg)
{
    HANDLE CONST hdl = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hdl == INVALID_HANDLE_VALUE)
        return FALSE;

    CONST size_t len = StringCchLengthS(msg);
    WriteConsole(hdl, msg, (DWORD)len, NULL, NULL);

    return TRUE;
}

static BOOL ConsoleError(PCTSTR CONST funcName, CONST INT errCode)
{
    HANDLE CONST hdl = GetStdHandle(STD_ERROR_HANDLE);
    if (hdl == INVALID_HANDLE_VALUE)
        return FALSE;

    TCHAR buf[256];
    CONST size_t cnt = sizeof buf / sizeof *buf;

    StringCchPrintf(buf, cnt, _T("%s failed: %d\n"), funcName, errCode);
    CONST size_t len = StringCchLengthS(buf);
    WriteConsole(hdl, buf, (DWORD)len, NULL, NULL);

    return TRUE;
}

static TCHAR TcpSvrAddr[] = _T("127.0.0.1");
static TCHAR TcpSvrPort[] = _T("49152");

static INT TcpSvrAccept(SOCKET CONST skt)
{
    INT ec = NOERROR;

    SOCKET CONST con = accept(skt, NULL, NULL);
    if (con == INVALID_SOCKET) {
        ec = WSAGetLastError();
        goto exit;
    }

    CHAR recv_buf[1024];
    if (recv(con, recv_buf, sizeof recv_buf, 0) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("recv()"), ec);
        goto exit_shutdown_socket;
    }

#ifdef _UNICODE
    PCWSTR CONST tmp = MultiByteAllocWideChar(CP_ACP, recv_buf);
    ConsoleOutput(tmp);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
#else
    ConsoleOutput(recv_buf);
#endif

    CONST CHAR send_buf[] = "TcpSvr: Welcome\n";
    if (send(con, send_buf, sizeof send_buf, 0) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("send()"), ec);
        goto exit_shutdown_socket;
    }

exit_shutdown_socket:
    shutdown(con, SD_BOTH);
    closesocket(con);
exit:
    return ec;
}

static DWORD WINAPI TcpSvrFunc(LPVOID CONST lpThreadParameter)
{
    UNREFERENCED_PARAMETER(lpThreadParameter);
    INT ec = NOERROR;

    ADDRINFOT hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    PADDRINFOT resp;
    if ((ec = GetAddrInfo(NULL, TcpSvrPort, &hints, &resp)) != NOERROR) {
        ConsoleError(_T("getAddrInfo()"), ec);
        goto exit;
    }

    SOCKET CONST skt = socket(resp->ai_family, resp->ai_socktype, resp->ai_protocol);
    if (skt == INVALID_SOCKET) {
        ec = WSAGetLastError();
        ConsoleError(_T("socket()"), ec);
        goto exit_free_addrinfo;
    }

    if (bind(skt, resp->ai_addr, (INT)resp->ai_addrlen) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("bind()"), ec);
        goto exit_close_socket;
    }

    if (listen(skt, SOMAXCONN) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("listen()"), ec);
        goto exit_close_socket;
    }

    while (TRUE) {
        TcpSvrAccept(skt);
        break;
    }

exit_close_socket:
    closesocket(skt);
exit_free_addrinfo:
    FreeAddrInfo(resp);
exit:
    if (ec != NOERROR)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static DWORD WINAPI TcpCltFunc(LPVOID CONST lpThreadParameter)
{
    UNREFERENCED_PARAMETER(lpThreadParameter);
    INT ec = NOERROR;

    ADDRINFOT hints;
    ZeroMemory(&hints, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    PADDRINFOT resp;
    if ((ec = GetAddrInfo(TcpSvrAddr, TcpSvrPort, &hints, &resp)) != NOERROR) {
        ConsoleError(_T("getAddrInfo()"), ec);
        goto exit;
    }

    SOCKET CONST skt = socket(resp->ai_family, resp->ai_socktype, resp->ai_protocol);
    if (skt == INVALID_SOCKET) {
        ec = WSAGetLastError();
        ConsoleError(_T("socket()"), ec);
        goto exit_free_addrinfo;
    }

    if (connect(skt, resp->ai_addr, (INT)resp->ai_addrlen) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("connect()"), ec);
        goto exit_close_socket;
    }

    CONST CHAR send_buf[] = "TcpClt: Hello\n";
    if (send(skt, send_buf, sizeof send_buf, 0) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("send()"), ec);
        goto exit_shutdown_socket;
    }

    CHAR recv_buf[1024];
    if (recv(skt, recv_buf, sizeof recv_buf, 0) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("recv()"), ec);
        goto exit_shutdown_socket;
    }

#ifdef _UNICODE
    PCWSTR CONST tmp = MultiByteAllocWideChar(CP_ACP, recv_buf);
    ConsoleOutput(tmp);
    HeapFree(GetProcessHeap(), 0, (PVOID)tmp);
#else
    ConsoleOutput(recv_buf);
#endif

exit_shutdown_socket:
    if (shutdown(skt, SD_BOTH) == SOCKET_ERROR) {
        ec = WSAGetLastError();
        ConsoleError(_T("shutdown()"), ec);
    }
exit_close_socket:
    closesocket(skt);
exit_free_addrinfo:
    FreeAddrInfo(resp);
exit:
    if (ec != NOERROR)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

START_TEST(tfTcp)
{
    WSADATA wsaData;
    CONST INT ec = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (ec)
        ck_abort_msg("WSAStartup() failed: %d", ec);

    HANDLE CONST thrdSvr = CreateThread(NULL, 0, TcpSvrFunc, NULL, 0, NULL);
    if (!thrdSvr)
        ck_abort_msg("CreateThread() failed: %lu", GetLastError());
    HANDLE CONST thrdClt = CreateThread(NULL, 0, TcpCltFunc, NULL, 0, NULL);
    if (!thrdClt)
        ck_abort_msg("CreateThread() failed: %lu", GetLastError());

    WaitForSingleObject(thrdSvr, INFINITE);
    WaitForSingleObject(thrdClt, INFINITE);

    if (WSACleanup())
        ck_abort_msg("WSACleanup() failed: %d", WSAGetLastError());
}
END_TEST;

START_TEST(tfGetFirstAdapterUnicastIPv4InternetAddress)
{
    CONST IN_ADDR ia = GetFirstAdapterUnicastIPv4InternetAddress();
    printf("%hhu.%hhu.%hhu.%hhu\n", ia.s_net, ia.s_host, ia.s_lh, ia.s_impno);
}
END_TEST;

/**
 * @}
 */

TCase *tcWindowsSockets2(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfTcp);
    tcase_add_test(tc, tfGetFirstAdapterUnicastIPv4InternetAddress);
    return tc;
}
