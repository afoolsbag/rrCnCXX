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
    auto CONST StrToIpaddr = [](CONST CString &str) -> DWORD {
        LPCTSTR terminator;
        IN_ADDR addr;
        RtlIpv4StringToAddress(str, FALSE, &terminator, &addr);
        return htonl(addr.s_addr);
    };

    auto CONST StrToIpport = [](CONST CString &str) -> UINT16 {
        return static_cast<UINT16>(_tcstoul(str, NULL, 10));
    };

    Option.ServiceIpaddr = StrToIpaddr(GetProfileString(TEXT("service"), TEXT("addr"), TEXT("127.0.0.1")));
    Option.ServiceIpport = StrToIpport(GetProfileString(TEXT("service"), TEXT("port"), TEXT("21520")));

    Option.StretchMatching = GetProfileInt(TEXT("configuration"), TEXT("stretch_matching"), FALSE);
    Option.ToneshiftMatching = GetProfileInt(TEXT("configuration"), TEXT("toneshift_matching"), FALSE);
    Option.SharpenMatching = GetProfileInt(TEXT("configuration"), TEXT("sharpen_matching"), FALSE);
    Option.ContrastMatching = GetProfileInt(TEXT("configuration"), TEXT("contrast_matching"), FALSE);
    Option.Operation = GetProfileInt(TEXT("configuration"), TEXT("operation"), -1);
    Option.Confidence = GetProfileInt(TEXT("configuration"), TEXT("confidence"), 0);

    Option.PostgreIpaddr = StrToIpaddr(GetProfileString(TEXT("postgre"), TEXT("addr"), TEXT("127.0.0.1")));
    Option.PostgreIpport = StrToIpport(GetProfileString(TEXT("postgre"), TEXT("port"), TEXT("5432")));
    Option.RedisIpaddr = StrToIpaddr(GetProfileString(TEXT("redis"), TEXT("addr"), TEXT("127.0.0.1")));
    Option.RedisIpport = StrToIpport(GetProfileString(TEXT("redis"), TEXT("port"), TEXT("6379")));
    Option.RabbitIpaddr = StrToIpaddr(GetProfileString(TEXT("rabbit"), TEXT("addr"), TEXT("127.0.0.1")));
    Option.RabbitIpport = StrToIpport(GetProfileString(TEXT("rabbit"), TEXT("port"), TEXT("5672")));
    Option.HumanIpaddr = StrToIpaddr(GetProfileString(TEXT("human"), TEXT("addr"), TEXT("127.0.0.1")));
    Option.HumanIpport = StrToIpport(GetProfileString(TEXT("human"), TEXT("port"), TEXT("10021")));
    Option.VehicleIpaddr = StrToIpaddr(GetProfileString(TEXT("vehicle"), TEXT("addr"), TEXT("127.0.0.1")));
    Option.VehicleIpport = StrToIpport(GetProfileString(TEXT("vehicle"), TEXT("port"), TEXT("12569")));
}

VOID BoxesApplication::
WriteOptionToProfile()
{
    auto CONST IpaddrToStr = [](CONST DWORD ipaddr) -> CString {
        IN_ADDR addr;
        addr.s_addr = ntohl(ipaddr);
        CString tmp;
        RtlIpv4AddressToString(&addr, tmp.GetBuffer(16));
        tmp.ReleaseBuffer();
        return tmp;
    };

    auto CONST IpportToStr = [](CONST UINT16 ipport) -> CString {
        CString tmp;
        tmp.Format(TEXT("%hu"), ipport);
        return tmp;
    };

    WriteProfileString(TEXT("service"), TEXT("addr"), IpaddrToStr(Option.ServiceIpaddr));
    WriteProfileString(TEXT("service"), TEXT("port"), IpportToStr(Option.ServiceIpport));

    WriteProfileInt(TEXT("configuration"), TEXT("stretch_matching"), Option.StretchMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("toneshift_matching"), Option.ToneshiftMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("sharpen_matching"), Option.SharpenMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("contrast_matching"), Option.ContrastMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("operation"), Option.Operation);
    WriteProfileInt(TEXT("configuration"), TEXT("confidence"), Option.Confidence);

    WriteProfileString(TEXT("postgre"), TEXT("addr"), IpaddrToStr(Option.ServiceIpaddr));
    WriteProfileString(TEXT("postgre"), TEXT("port"), IpportToStr(Option.ServiceIpport));
    WriteProfileString(TEXT("redis"), TEXT("addr"), IpaddrToStr(Option.RedisIpaddr));
    WriteProfileString(TEXT("redis"), TEXT("port"), IpportToStr(Option.RedisIpport));
    WriteProfileString(TEXT("rabbit"), TEXT("addr"), IpaddrToStr(Option.RabbitIpaddr));
    WriteProfileString(TEXT("rabbit"), TEXT("port"), IpportToStr(Option.RabbitIpport));
    WriteProfileString(TEXT("human"), TEXT("addr"), IpaddrToStr(Option.HumanIpaddr));
    WriteProfileString(TEXT("human"), TEXT("port"), IpportToStr(Option.HumanIpport));
    WriteProfileString(TEXT("vehicle"), TEXT("addr"), IpaddrToStr(Option.VehicleIpaddr));
    WriteProfileString(TEXT("vehicle"), TEXT("port"), IpportToStr(Option.VehicleIpport));
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
