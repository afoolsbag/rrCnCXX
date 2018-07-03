/// \copyright The MIT License

#include "stdafx.h"
#include "BxsApp.h"

#include <mstcpip.h>
#pragma comment(lib, "ntdll.lib")

#include "rrwindows/dbgcon.h"
#include "rrwindows/exepath.h"

#include "ui/BxsDlg.h"

#// Constructors

BoxesApplication::
BoxesApplication()
{
    AllocDebugConsole();
    DcMeth();
}

BoxesApplication::
~BoxesApplication()
{
    DcMeth();
    FreeDebugConsole();
}

#// Operations

VOID BoxesApplication::
ReadOptionFromProfile()
{
    CString tmp;
    LPCTSTR terminator;
    IN_ADDR addr;

    tmp = GetProfileString(TEXT("service"), TEXT("addr"), TEXT("127.0.0.1"));
    RtlIpv4StringToAddress(tmp, FALSE, &terminator, &addr);
    Option.ServiceIpaddr = htonl(addr.s_addr);

    tmp = GetProfileString(TEXT("service"), TEXT("port"), TEXT("21520"));
    Option.ServiceIpport = static_cast<UINT16>(_tcstoul(tmp, NULL, 10));

    tmp = GetProfileString(TEXT("redis"), TEXT("addr"), TEXT("127.0.0.1"));

    RtlIpv4StringToAddress(tmp, FALSE, &terminator, &addr);
    Option.RedisIpaddr = htonl(addr.s_addr);

    tmp = GetProfileString(TEXT("redis"), TEXT("port"), TEXT("6379"));
    Option.RedisIpport = static_cast<UINT16>(_tcstoul(tmp, NULL, 10));

    tmp = GetProfileString(TEXT("rabbit"), TEXT("addr"), TEXT("127.0.0.1"));
    RtlIpv4StringToAddress(tmp, FALSE, &terminator, &addr);
    Option.RabbitIpaddr = htonl(addr.s_addr);

    tmp = GetProfileString(TEXT("rabbit"), TEXT("port"), TEXT("5672"));
    Option.RabbitIpport = static_cast<UINT16>(_tcstoul(tmp, NULL, 10));
}

VOID BoxesApplication::
WriteOptionToProfile()
{
    CString tmp;
    IN_ADDR addr;

    addr.s_addr = ntohl(Option.ServiceIpaddr);
    RtlIpv4AddressToString(&addr, tmp.GetBuffer(16));
    tmp.ReleaseBuffer();
    WriteProfileString(TEXT("service"), TEXT("addr"), tmp);

    tmp.Format(TEXT("%hu"), Option.ServiceIpport);
    WriteProfileString(TEXT("service"), TEXT("port"), tmp);

    addr.s_addr = ntohl(Option.RedisIpaddr);
    RtlIpv4AddressToString(&addr, tmp.GetBuffer(16));
    tmp.ReleaseBuffer();
    WriteProfileString(TEXT("redis"), TEXT("addr"), tmp);

    tmp.Format(TEXT("%hu"), Option.RedisIpport);
    WriteProfileString(TEXT("redis"), TEXT("port"), tmp);

    addr.s_addr = ntohl(Option.RabbitIpaddr);
    RtlIpv4AddressToString(&addr, tmp.GetBuffer(16));
    tmp.ReleaseBuffer();
    WriteProfileString(TEXT("rabbit"), TEXT("addr"), tmp);

    tmp.Format(TEXT("%hu"), Option.RabbitIpport);
    WriteProfileString(TEXT("rabbit"), TEXT("port"), tmp);
}


#// Overridables

BOOL BoxesApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DcMeth();

    // Initialization
    free(const_cast<LPTSTR>(m_pszProfileName));
    m_pszProfileName = _tcsdup(InitializationPath());

    BoxesDialog mainWnd;
    m_pMainWnd = &mainWnd;
    mainWnd.DoModal();

    return FALSE;
}
