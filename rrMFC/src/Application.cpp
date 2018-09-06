/// \copyright The Unlicense

#include "stdafx.h"
#include "Application.h"

#include <random>
#include <vector>
#include <conio.h>
#include <mstcpip.h>
#pragma comment(lib, "ntdll.lib")

#define VTS_ACRONYM
#include "rrwindows/rrwindows.h"

#include "ui/btndlg/ButtonDialog.h"
#include "ui/ddxdlg/DdxDialog.h"
#include "ui/dlg/Dialog.h"
#include "ui/editdlg/EditDialog.h"
#include "ui/frm/Frame.h"
#include "ui/listdlg/ListDialog.h"
#include "ui/progbox/ProgressBox.h"
#include "ui/propsht/PropertyPage1.h"
#include "ui/propsht/PropertyPage2.h"
#include "ui/propsht/PropertyPage3.h"
#include "ui/tabdlg/TabDialog.h"
#include "ui/treedlg/TreeDialog.h"
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
        if (pApp != nullptr && pApp->IsKindOf(RUNTIME_CLASS(rrMFC::Application)))
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
std::vector<CString> TokenizeCommandLine(const CString &commandLine)
{
    std::vector<CString> tokens;
    for (int pos = 0;;) {
        const CString token = commandLine.Tokenize(TEXT("\t\n\v\r "), pos);
        if (token.IsEmpty())
            break;
        else
            tokens.push_back(token);
    }
    return tokens;
}

/// \brief 符号匹配（单匹配）。
bool TokenMatches(const CString &command, const CString &target)
{
    if (!command.CompareNoCase(target))
        return true;
    return false;
}

/// \brief 符号匹配（双匹配）。
bool TokenMatches(const CString &command, const CString &target, const CString &target2)
{
    if (!command.CompareNoCase(target))
        return true;
    if (!command.CompareNoCase(target2))
        return true;
    return false;
}

/// \brief 符号匹配（三匹配）。
bool TokenMatches(const CString &command, const CString &target, const CString &target2, const CString &target3)
{
    if (!command.CompareNoCase(target))
        return true;
    if (!command.CompareNoCase(target2))
        return true;
    if (!command.CompareNoCase(target3))
        return true;
    return false;
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

void Application::
ReadConfigsFromProfile()
{
    auto const StrToIpaddr = [](const CString &str) -> DWORD {
        LPCTSTR terminator;
        IN_ADDR addr;
        RtlIpv4StringToAddress(str, FALSE, &terminator, &addr);
        return htonl(addr.s_addr);
    };

    auto const StrToIpport = [](const CString &str) -> UINT16 {
        return static_cast<UINT16>(_tcstoul(str, nullptr, 10));
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
    auto const IpaddrToStr = [](const DWORD ipaddr) -> CString {
        IN_ADDR addr;
        addr.s_addr = ntohl(ipaddr);
        CString tmp;
        RtlIpv4AddressToString(&addr, tmp.GetBuffer(16));
        tmp.ReleaseBuffer();
        return tmp;
    };

    auto const IpportToStr = [](const UINT16 ipport) -> CString {
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
    for (;;) {
        _cputts(WHT("\nEnter a command: ") VTS_FGCYAB);
        _cgetts_s(buf, &len);
        CliLcl = TokenizeCommandLine(buf);
        if (CliLcl.empty())
            CliUnknownCommand();
        else if (TokenMatches(CliLcl[0], TEXT("ClearScreen"), TEXT("CLS")))
            CliWelcome();
        else if (TokenMatches(CliLcl[0], TEXT("Help"), TEXT("?")))
            CliHelp();
        else if (TokenMatches(CliLcl[0], TEXT("Status")))
            CliStatus();
        else if (TokenMatches(CliLcl[0], TEXT("ButtonDialog"), TEXT("BTNDLG"), TEXT("BTN")))
            CliButtonDialog();
        else if (TokenMatches(CliLcl[0], TEXT("EditDialog"), TEXT("EDITDLG"), TEXT("EDIT")))
            CliEditDialog();
        else if (TokenMatches(CliLcl[0], TEXT("ListDialog"), TEXT("LISTDLG"), TEXT("LIST")))
            CliListDialog();
        else if (TokenMatches(CliLcl[0], TEXT("TabDialog"), TEXT("TABDLG"), TEXT("TAB")))
            CliTabDialog();
        else if (TokenMatches(CliLcl[0], TEXT("TreeDialog"), TEXT("TREEDLG"), TEXT("TREE")))
            CliTreeDialog();
        else if (TokenMatches(CliLcl[0], TEXT("DdxDialog"), TEXT("DDXDLG"), TEXT("DDX")))
            CliDdxDialog();
        else if (TokenMatches(CliLcl[0], TEXT("ProgressBox"), TEXT("PROGBOX"), TEXT("PROG")))
            CliProgressBox();
        else if (TokenMatches(CliLcl[0], TEXT("PropertySheet"), TEXT("PROPSHT"), TEXT("PROP")))
            CliPropertySheet();
        else if (TokenMatches(CliLcl[0], TEXT("Window"), TEXT("WND")))
            CliWindow();
        else if (TokenMatches(CliLcl[0], TEXT("Frame"), TEXT("FRM")))
            CliFrame();
        else if (TokenMatches(CliLcl[0], TEXT("Dialog"), TEXT("DLG")))
            CliDialog();
        else if (TokenMatches(CliLcl[0], TEXT("Exit"), TEXT("Elose"), TEXT("Quit")))
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

int Application::
ExitInstance()
{
    if (SW_HIDE != m_nCmdShow)
        DpWarnExpectTrue(FreeConsole());
    DcMeth();
    return CWinApp::ExitInstance();
}

#// Implementation

void Application::
CliWelcome() const
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

void Application::
CliUnknownCommand() const
{
    if (!CliLcl.empty())
        _tcprintf_s(WHT("The command ") CYA("%s") WHT(" is unknown. "), static_cast<LPCTSTR>(CliLcl[0]));
    _cputts(WHT("Enter ") CYA("HELP") WHT(" or ") CYA("?") WHT(" to list valid commands.\n"));
}

void Application::
CliHelp() const
{
    _cputts(
        WHT("Commands, case insensitivity:\n")
        CYA("    CLEARSCREEN") WHT("(") CYA("CLS") WHT(")\n")
        CYA("    HELP") WHT("(") CYA("?") WHT(")\n")
        CYA("    STATUS\n")
        CYA("    BUTTONDIALOG") WHT("(") CYA("BTNDLG") WHT(",") CYA("BTN") WHT(")\n")
        CYA("    EDITDIALOG") WHT("(") CYA("EDITDLG") WHT(",") CYA("EDIT") WHT(")\n")
        CYA("    LISTDIALOG") WHT("(") CYA("LISTDLG") WHT(",") CYA("LIST") WHT(")\n")
        CYA("    TABDIALOG") WHT("(") CYA("TABDLG") WHT(",") CYA("TAB") WHT(")\n")
        CYA("    TREEDIALOG") WHT("(") CYA("TREEDLG") WHT(",") CYA("TREE") WHT(")\n")
        CYA("    DDXDIALOG") WHT("(") CYA("DDXDLG") WHT(",") CYA("DDX") WHT(")\n")
        CYA("    PROGRESSBOX") WHT("(") CYA("PROGBOX") WHT(",") CYA("PROG") WHT(")\n")
        CYA("    PROPERTYSHEET") WHT("(") CYA("PROPSHT") WHT(",") CYA("PROP") WHT(")\n")
        CYA("    WINDOW") WHT("(") CYA("WND") WHT(")\n")
        CYA("    FRAME") WHT("(") CYA("FRM") WHT(")\n")
        CYA("    DIALOG") WHT("(") CYA("DLG") WHT(")\n")
        CYA("    EXIT") WHT("(") CYA("CLOSE") WHT(",") CYA("QUIT") WHT(")\n")
    );
}

void Application::
CliStatus() const
{
    _cputts(
        WHT("Status:\n"));
    _tcprintf_s(
        WHT("    Codepage input %u, output %u.\n"), GetConsoleCP(), GetConsoleOutputCP());
}

void Application::
CliButtonDialog() const
{
    ButtonDialog dlg;
    dlg.DoModal();
}

void Application::
CliEditDialog() const
{
    EditDialog dlg;
    dlg.DoModal();
}

void Application::
CliListDialog() const
{
    ListDialog dlg;
    dlg.DoModal();
}

void Application::
CliTabDialog() const
{
    TabDialog dlg;
    dlg.DoModal();
}

void Application::
CliTreeDialog() const
{
    TreeDialog dlg;
    dlg.DoModal();
}

void Application::
CliDdxDialog() const
{
    DdxDialog dlg;
    dlg.DoModal();
}

void Application::
CliProgressBox() const
{
    ProgressBox box;
    box.SetThreadFunction(std::bind([](ProgressBox *const pProgBox) -> UINT {
        pProgBox->SetTitle(TEXT("Target"));
        pProgBox->SetTotal(TEXT("Total progress"));
        pProgBox->SetTotal(0, 100);
        pProgBox->SetCurrent(TEXT("Current progress"));
        pProgBox->SetCurrent(0, 100);
        INT total = 0;
        INT current = 0;

        std::random_device rndDev;
        std::mt19937 rndGen(rndDev());
        std::uniform_int_distribution<> rndDist(1, 6);
        for (;;) {
            current += rndDist(rndGen);
            if (100 <= current) {
                current -= 100;
                ++total;
            }
            pProgBox->SetCurrent(current);
            pProgBox->SetTotal(total);
            if (100 <= total)
                break;
            Sleep(1);
        }
        return EXIT_SUCCESS;
    }, std::placeholders::_1));
    box.DoModal();
}

void Application::
CliPropertySheet()
{
    ReadConfigsFromProfile();

    CPropertySheet sheet(TEXT("Properties Sheet"));

    PropertyPage1 page1;
    page1.ReadFrom(Configs);
    sheet.AddPage(&page1);

    PropertyPage2 page2;
    page2.ReadFrom(Configs);
    sheet.AddPage(&page2);

    PropertyPage3 page3;
    page3.ReadFrom(Configs);
    sheet.AddPage(&page3);

    CONST INT_PTR result = sheet.DoModal();
    switch (result) {
    case IDOK:
        page1.WriteTo(&Configs);
        page2.WriteTo(&Configs);
        page3.WriteTo(&Configs);
        WriteConfigsToProfile();
        break;
    case IDCANCEL:
        break;
    default:
        DpErrorUSR(result);
        break;
    }
}

void Application::
CliWindow()
{
    CliExitFlag = CliExitType::Window;
}

void Application::
CliFrame()
{
    CliExitFlag = CliExitType::Frame;
}

void Application::
CliDialog()
{
    CliExitFlag = CliExitType::Dialog;
}

void Application::
CliExit()
{
    CliExitFlag = CliExitType::Exit;
}

}//namespace rrmfc
