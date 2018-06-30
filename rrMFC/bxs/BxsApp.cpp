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

    tmp = GetProfileString(TEXT("service"), TEXT("addr"), TEXT("127.0.0.1"));
    IN_ADDR addr;
    LPCTSTR terminator;
    RtlIpv4StringToAddress(tmp, FALSE, &terminator, &addr);
    Option.ServiceIpaddress = htonl(addr.s_addr);


    tmp = GetProfileString(TEXT("service"), TEXT("port"), TEXT("21520"));
    Option.ServiceIpport = static_cast<UINT16>(_tcstoul(tmp, NULL, 10));
}

VOID BoxesApplication::
WriteOptionToProfile()
{
    CString tmp;

    IN_ADDR addr;
    addr.s_addr = ntohl(Option.ServiceIpaddress);
    RtlIpv4AddressToString(&addr, tmp.GetBuffer(16));
    tmp.ReleaseBuffer();
    WriteProfileString(TEXT("service"), TEXT("addr"), tmp);

    tmp.Format(TEXT("%hu"), Option.ServiceIpport);
    WriteProfileString(TEXT("service"), TEXT("port"), tmp);
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
