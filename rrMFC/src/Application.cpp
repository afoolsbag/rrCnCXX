/// \copyright The Unlicense

#include "stdafx.h"
#include "Application.h"

#include <vector>
#include <conio.h>

#include <mstcpip.h>
#pragma comment(lib, "ntdll.lib")

#define VTS_ACRONYM
#include "rrwindows/rrwindows.h"

#include "ui/dlg/Dialog.h"
#include "ui/frm/Frame.h"
#include "ui/wnd/Window.h"

namespace {

/// \sa <https://docs.microsoft.com/windows/console/handlerroutine>
BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
    switch (dwCtrlType) {
    case CTRL_C_EVENT://fall-through
    case CTRL_BREAK_EVENT:
        break;
    case CTRL_CLOSE_EVENT://fall-through
    case CTRL_LOGOFF_EVENT://fall-through
    case CTRL_SHUTDOWN_EVENT: {
        rrMFC::Application * pApp = dynamic_cast<rrMFC::Application *>(AfxGetApp());
        if (pApp && pApp->IsKindOf(RUNTIME_CLASS(rrMFC::Application)))
            pApp->ExitInstance();
        break;
    }
    default:
        DpErrorUSR(dwCtrlType);
        break;
    }
    return TRUE;
}

/// \brief 符号化命令行（按空白符）。
std::vector<CString> TokenizeCommandLine(CONST CString &commandLine)
{
    std::vector<CString> tokens;
    for (INT pos = 0;;) {
        CONST CString token = commandLine.Tokenize(TEXT("\t\n\v\r "), pos);
        if (token.IsEmpty())
            break;
        else
            tokens.push_back(token);
    }
    return tokens;
}

/// \brief 符号匹配（单匹配）。
BOOL TokenMatches(CONST CString &command, CONST CString &target)
{
    if (!command.CompareNoCase(target))
        return TRUE;
    return FALSE;
}

/// \brief 符号匹配（双匹配）。
BOOL TokenMatches(CONST CString &command, CONST CString &target, CONST CString &target2)
{
    if (!command.CompareNoCase(target))
        return TRUE;
    if (!command.CompareNoCase(target2))
        return TRUE;
    return FALSE;
}

/// \brief 符号匹配（三匹配）。
BOOL TokenMatches(CONST CString &command, CONST CString &target, CONST CString &target2, CONST CString &target3)
{
    if (!command.CompareNoCase(target))
        return TRUE;
    if (!command.CompareNoCase(target2))
        return TRUE;
    if (!command.CompareNoCase(target3))
        return TRUE;
    return FALSE;
}

}//namespace

namespace rrMFC {

namespace RegisteredMessages {

UINT Custom = RegisterWindowMessage(TEXT("rrMFC::RegisteredMessages::Custom"));

}//namespace RegisteredMessages

IMPLEMENT_DYNAMIC(Application, CWinApp)

#// Constructors

Application::
Application()
{
    SetUnhandledExceptionFilter(ExceptionCrashHandler);

    DcAlloc();
    DcMeth();
}

Application::
~Application()
{
    DcMeth();
    DcFree();
}

#// Operations

VOID Application::
ReadConfigsFromProfile()
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

    Configs.ServiceIpaddr = StrToIpaddr(GetProfileString(TEXT("service"), TEXT("addr"), TEXT("127.0.0.1")));
    Configs.ServiceIpport = StrToIpport(GetProfileString(TEXT("service"), TEXT("port"), TEXT("21520")));

    Configs.StretchMatching = GetProfileInt(TEXT("configuration"), TEXT("stretch_matching"), FALSE);
    Configs.ToneshiftMatching = GetProfileInt(TEXT("configuration"), TEXT("toneshift_matching"), FALSE);
    Configs.SharpenMatching = GetProfileInt(TEXT("configuration"), TEXT("sharpen_matching"), FALSE);
    Configs.ContrastMatching = GetProfileInt(TEXT("configuration"), TEXT("contrast_matching"), FALSE);
    Configs.Operation = GetProfileInt(TEXT("configuration"), TEXT("operation"), -1);
    Configs.Confidence = GetProfileInt(TEXT("configuration"), TEXT("confidence"), 0);

    Configs.PostgreIpaddr = StrToIpaddr(GetProfileString(TEXT("postgre"), TEXT("addr"), TEXT("127.0.0.1")));
    Configs.PostgreIpport = StrToIpport(GetProfileString(TEXT("postgre"), TEXT("port"), TEXT("5432")));
    Configs.RedisIpaddr = StrToIpaddr(GetProfileString(TEXT("redis"), TEXT("addr"), TEXT("127.0.0.1")));
    Configs.RedisIpport = StrToIpport(GetProfileString(TEXT("redis"), TEXT("port"), TEXT("6379")));
    Configs.RabbitIpaddr = StrToIpaddr(GetProfileString(TEXT("rabbit"), TEXT("addr"), TEXT("127.0.0.1")));
    Configs.RabbitIpport = StrToIpport(GetProfileString(TEXT("rabbit"), TEXT("port"), TEXT("5672")));
    Configs.HumanIpaddr = StrToIpaddr(GetProfileString(TEXT("human"), TEXT("addr"), TEXT("127.0.0.1")));
    Configs.HumanIpport = StrToIpport(GetProfileString(TEXT("human"), TEXT("port"), TEXT("10021")));
    Configs.VehicleIpaddr = StrToIpaddr(GetProfileString(TEXT("vehicle"), TEXT("addr"), TEXT("127.0.0.1")));
    Configs.VehicleIpport = StrToIpport(GetProfileString(TEXT("vehicle"), TEXT("port"), TEXT("12569")));
}

VOID Application::
WriteConfigsToProfile()
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

    WriteProfileString(TEXT("service"), TEXT("addr"), IpaddrToStr(Configs.ServiceIpaddr));
    WriteProfileString(TEXT("service"), TEXT("port"), IpportToStr(Configs.ServiceIpport));

    WriteProfileInt(TEXT("configuration"), TEXT("stretch_matching"), Configs.StretchMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("toneshift_matching"), Configs.ToneshiftMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("sharpen_matching"), Configs.SharpenMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("contrast_matching"), Configs.ContrastMatching);
    WriteProfileInt(TEXT("configuration"), TEXT("operation"), Configs.Operation);
    WriteProfileInt(TEXT("configuration"), TEXT("confidence"), Configs.Confidence);

    WriteProfileString(TEXT("postgre"), TEXT("addr"), IpaddrToStr(Configs.ServiceIpaddr));
    WriteProfileString(TEXT("postgre"), TEXT("port"), IpportToStr(Configs.ServiceIpport));
    WriteProfileString(TEXT("redis"), TEXT("addr"), IpaddrToStr(Configs.RedisIpaddr));
    WriteProfileString(TEXT("redis"), TEXT("port"), IpportToStr(Configs.RedisIpport));
    WriteProfileString(TEXT("rabbit"), TEXT("addr"), IpaddrToStr(Configs.RabbitIpaddr));
    WriteProfileString(TEXT("rabbit"), TEXT("port"), IpportToStr(Configs.RabbitIpport));
    WriteProfileString(TEXT("human"), TEXT("addr"), IpaddrToStr(Configs.HumanIpaddr));
    WriteProfileString(TEXT("human"), TEXT("port"), IpportToStr(Configs.HumanIpport));
    WriteProfileString(TEXT("vehicle"), TEXT("addr"), IpaddrToStr(Configs.VehicleIpaddr));
    WriteProfileString(TEXT("vehicle"), TEXT("port"), IpportToStr(Configs.VehicleIpport));
}

#// Overridables

BOOL Application::
InitApplication()
{
    DcMeth();
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DcMeth();

    // Control Handler
    AfxMessageBoxExpectTrue(SetConsoleCtrlHandler(&HandlerRoutine, TRUE));

    // Profile
    free(const_cast<LPTSTR>(m_pszProfileName));
    m_pszProfileName = _tcsdup(InitializationPath());

    // Command Line Interface
    while (SW_HIDE == m_nCmdShow)
        Sleep(INFINITE);

    DpWarnExpectTrue(AllocConsole());
    DpWarnExpectTrue(EnableVirtualTerminalMode());
    SetConsoleForeGroundColor(LightAqua);

    CliWelcome();
    TCHAR buf[512] = TEXT("");
    size_t len = 0;
    while (TRUE) {
        _cputts(WHT("\nEnter a command: ") VTS_FGCYAB);
        _cgetts_s(buf, &len);
        CliLcl = TokenizeCommandLine(buf);
        if (CliLcl.empty())
            CliUnknownCommand();
        else if (TokenMatches(CliLcl[0], TEXT("clearscreen"), TEXT("cls")))
            CliWelcome();
        else if (TokenMatches(CliLcl[0], TEXT("help"), TEXT("?")))
            CliHelp();
        else if (TokenMatches(CliLcl[0], TEXT("status")))
            CliStatus();
        else if (TokenMatches(CliLcl[0], TEXT("button"), TEXT("btn")))
            CliButton();
        else if (TokenMatches(CliLcl[0], TEXT("window"), TEXT("wnd")))
            CliWindow();
        else if (TokenMatches(CliLcl[0], TEXT("frame"), TEXT("frm")))
            CliFrame();
        else if (TokenMatches(CliLcl[0], TEXT("dialog"), TEXT("dlg")))
            CliDialog();
        else if (TokenMatches(CliLcl[0], TEXT("exit"), TEXT("close"), TEXT("quit")))
            CliExit();
        else
            CliUnknownCommand();
        if (CliExitFlag != CliExitType::Loop)
            break;
        NON_UNICODE_ONLY(_cgetts_s(buf, &len));
    }

    // Main Window
    switch (CliExitFlag) {
    case CliExitType::Exit:
        return FALSE;
    case CliExitType::Window:
        m_pMainWnd = DEBUG_NEW Window;
        m_pMainWnd->ShowWindow(m_nCmdShow);
        m_pMainWnd->UpdateWindow();
        return TRUE;
    case CliExitType::Frame:
        m_pMainWnd = DEBUG_NEW Frame;
        dynamic_cast<Frame *>(m_pMainWnd)->LoadFrame(Frame::IDR);
        m_pMainWnd->ShowWindow(m_nCmdShow);
        m_pMainWnd->UpdateWindow();
        return TRUE;
    case CliExitType::Dialog:
        m_pMainWnd = DEBUG_NEW Dialog;
        dynamic_cast<Dialog *>(m_pMainWnd)->DoModal();
        return FALSE;
    default:
        DpErrorUSR(CliExitFlag);
        return FALSE;
    }
}

INT Application::
ExitInstance()
{
    if (SW_HIDE != m_nCmdShow)
        DpWarnExpectTrue(FreeConsole());
    DcMeth();
    return CWinApp::ExitInstance();
}

#// Implementation

VOID Application::
CliWelcome() CONST
{
    _cputts(VTS_ED
            WHT("\n")
            WHT("                        _/      _/  _/_/_/_/    _/_/_/\n")
            WHT("   _/  _/_/  _/  _/_/  _/_/  _/_/  _/        _/       \n")
            WHT("  _/_/      _/_/      _/  _/  _/  _/_/_/    _/        \n")
            WHT(" _/        _/        _/      _/  _/        _/         \n")
            WHT("_/        _/        _/      _/  _/          _/_/_/    \n")
            WHT("\n")
            WHT("      _/_/                        _/  _/                        _/      _/                  \n")
            WHT("   _/    _/  _/_/_/    _/_/_/    _/        _/_/_/    _/_/_/  _/_/_/_/        _/_/    _/_/_/ \n")
            WHT("  _/_/_/_/  _/    _/  _/    _/  _/  _/  _/        _/    _/    _/      _/  _/    _/  _/    _/\n")
            WHT(" _/    _/  _/    _/  _/    _/  _/  _/  _/        _/    _/    _/      _/  _/    _/  _/    _/ \n")
            WHT("_/    _/  _/_/_/    _/_/_/    _/  _/    _/_/_/    _/_/_/      _/_/  _/    _/_/    _/    _/  \n")
            WHT("         _/        _/                                                                       \n")
            WHT("        _/        _/                                                                        \n")
            WHT("\n")
            WHT("Command line interface is ") GRN("enabled") WHT(".\n"));
}

VOID Application::
CliUnknownCommand() CONST
{
    if (!CliLcl.empty())
        _tcprintf_s(WHT("The command ") CYA("%s") WHT(" is unknown. "), static_cast<LPCTSTR>(CliLcl[0]));
    _cputts(WHT("Enter ") CYA("HELP") WHT(" or ") CYA("?") WHT(" to list valid commands.\n"));
}

VOID Application::
CliHelp() CONST
{
    _cputts(
        WHT("Commands, case insensitivity:\n")
        CYA("    CLEARSCREEN") WHT("(") CYA("CLS") WHT(")\n")
        CYA("    HELP") WHT("(") CYA("?") WHT(")\n")
        CYA("    STATUS\n")
        CYA("    BUTTON") WHT("(") CYA("BTN") WHT(")\n")
        CYA("    WINDOW") WHT("(") CYA("WND") WHT(")\n")
        CYA("    FRAME") WHT("(") CYA("FRM") WHT(")\n")
        CYA("    DIALOG") WHT("(") CYA("DLG") WHT(")\n")
        CYA("    EXIT") WHT("(") CYA("CLOSE") WHT(",") CYA("QUIT") WHT(")\n")
    );
}

VOID Application::
CliStatus() CONST
{
    _cputts(
        WHT("Status:\n"));
    _tcprintf_s(
        WHT("    Codepage input %u, output %u.\n"), GetConsoleCP(), GetConsoleOutputCP());
}

VOID Application::
CliButton()
{
//    ButtonDialog mnDlg;
//    mnDlg.DoModal();
}

VOID Application::
CliWindow()
{
    CliExitFlag = CliExitType::Window;
}

VOID Application::
CliFrame()
{
    CliExitFlag = CliExitType::Frame;
}

VOID Application::
CliDialog()
{
    CliExitFlag = CliExitType::Dialog;
}

VOID Application::
CliExit()
{
    CliExitFlag = CliExitType::Exit;
}

}//namespace rrmfc
