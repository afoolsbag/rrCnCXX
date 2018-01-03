/** \file
 *  \author zhengrr
 *  \date 2016-11-11 – 12-26
 *  \copyright The MIT License
 */
#include <stdio.h>

#include <tchar.h>
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

static int tmain(int argc, _TCHAR *argv[], _TCHAR *envp[])
{
        /* 启动 Windows Socket */
        _tprintf_s(_T("*** Startuping windows socket..."));
        WSADATA data;  // Windows Socket Api Data
        int rwsas = WSAStartup(MAKEWORD(2, 2), &data);
        if (NO_ERROR != rwsas) {
                _tprintf_s(_T(" error, WSAStartup() failed with error %d.\n"), rwsas);
                return EXIT_FAILURE;
        }
        _tprintf_s(_T(" done.\n"));

        /* 创建套接字 */
        _tprintf_s(_T("*** Creating socket..."));
        SOCKET skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (INVALID_SOCKET == skt) {
                _tprintf_s(_T(" error, socket() failed with error %d.\n"), WSAGetLastError());
                WSACleanup();
                return EXIT_FAILURE;
        }
        _tprintf_s(_T(" done.\n"));

        /* 绑定地址 */
        _tprintf_s(_T("*** Binding address..."));
        SOCKADDR_IN addr;
        ZeroMemory(&addr, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons(10096);
        if (SOCKET_ERROR == bind(skt, (PSOCKADDR)&addr, sizeof addr)) {
                _tprintf_s(_T(" error, bind() failed with error %d.\n"), WSAGetLastError());
                closesocket(skt);
                WSACleanup();
                return EXIT_FAILURE;
        }
        _tprintf_s(_T(" done with port %hu.\n"), ntohs(addr.sin_port));

        /* 配置套接字 */
        DWORD so_val;
        int so_len = sizeof so_val;
        const DWORD so_keepalive_mask = 0x0000000000000011L;

        BOOL so_keepalive = TRUE;

        _tprintf_s(_T("*** Getting socket option KEEPALIVE..."));
        if (SOCKET_ERROR == getsockopt(skt, SOL_SOCKET, SO_KEEPALIVE, (char *)&so_val, &so_len))
                _tprintf_s(_T(" error, getsockopt() failed with error %d.\n"), WSAGetLastError());
        else
                _tprintf_s(_T(" done, SO_KEEPALIVE: %s.\n"), so_val & so_keepalive_mask ? _T("ON") : _T("OFF"));

        _tprintf_s(_T("*** Setting socket option KEEPALIVE..."));
        if (SOCKET_ERROR == setsockopt(skt, SOL_SOCKET, SO_KEEPALIVE, (char *)&so_keepalive, sizeof so_keepalive))
                _tprintf_s(_T(" error, setsockopt() failed with error %d.\n"), WSAGetLastError());
        else
                _tprintf_s(_T(" done with SO_KEEPALIVE %s.\n"), so_keepalive ? _T("ON") : _T("OFF"));

        _tprintf_s(_T("*** Getting socket option KEEPALIVE..."));
        if (SOCKET_ERROR == getsockopt(skt, SOL_SOCKET, SO_KEEPALIVE, (char *)&so_val, &so_len))
                _tprintf_s(_T(" error, getsockopt() failed with error %d.\n"), WSAGetLastError());
        else
                _tprintf_s(_T(" done, SO_KEEPALIVE: %s.\n"), so_val & so_keepalive_mask ? _T("ON") : _T("OFF"));

        ///* 配置套接字 */ {
        //    *env << "H264VideoUDPSource: Setting socket option RECBUF...";
        //    int so_rcvbuf {1 << 24};
        //    if (SOCKET_ERROR == setsockopt(skt, SOL_SOCKET, SO_RCVBUF, reinterpret_cast<const char *>(&so_rcvbuf), sizeof so_rcvbuf))
        //        *env << " error, setsockopt() failed with error " << WSAGetLastError() << ".\n";
        //    else
        //        *env << " done with value " << so_rcvbuf << ".\n";
        //
        //    *env << "H264VideoUDPSource: Setting socket option REUSEADDR...";
        //    BOOL so_reuseaddr {TRUE};
        //    if (SOCKET_ERROR == setsockopt(skt, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char *>(&so_reuseaddr), sizeof so_reuseaddr))
        //        *env << " error, setsockopt() failed with error " << WSAGetLastError() << ".\n";
        //    else
        //        *env << "done with value " << (so_reuseaddr ? "ON" : "OFF") << ".\n";
        //}

        /* 关闭套接字、关闭 Windows Socket */
        closesocket(skt);
        WSACleanup();
        return EXIT_SUCCESS;
}

#ifdef ENTRY_SWITCH
int _tmain(int argc, _TCHAR *argv[], _TCHAR *envp[]) { return tmain(argc, argv, envp); }
#endif// ENTRY SWITCH
