/// \copyright The MIT License

#include "stdafx.h"
#include "App.h"

#include <vector>
#include <conio.h>

#include "rrwindows/conutil.h"
#include "rrwindows/dbgcon.h"
#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/unhdlexcfltr.h"

#// Constructors

Application::
Application()
{
    SetUnhandledExceptionFilter(ExceptionCrashHandler);
    AllocDebugConsole();
    DcMeth();
}

Application::
~Application()
{
    DcMeth();
    FreeDebugConsole();
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

    // Console
    if (SW_HIDE != m_nCmdShow)
        if (!AllocConsole())
            DpWarnFwLE(TEXT("AllocConsole"));
    if (!SetConsoleCtrlHandler(&Application::HandlerRoutine, TRUE))
        AfxMessageBoxFwLE(TEXT("SetConsoleCtrlHandler"));

    // Command Line Interface Loop
    SetConsoleForeGroundColor(LightAqua);
    ShowHello();
    TCHAR buf[512] = TEXT("");
    size_t len = 0;
    while (TRUE) {
        ConsoleColorPut(TEXT("\nEnter a command: "));
        _cgetts_s(buf, &len);
        std::vector<CString> tokens = TokenizeCommandLine(buf);
        if (tokens.empty())
            ShowUnknown(tokens);
        else if (CommandMatches(tokens[0], TEXT("clearscreen"), TEXT("cls")))
            ShowHello();
        else if (CommandMatches(tokens[0], TEXT("help"), TEXT("?")))
            ShowHelp(tokens);
        else if (CommandMatches(tokens[0], TEXT("status")))
            ShowStatus(tokens);
        else if (CommandMatches(tokens[0], TEXT("exit"), TEXT("close"), TEXT("quit")))
            break;
        else
            ShowUnknown(tokens);
#ifndef _UNICODE
        _cgetts_s(buf, &len);
#endif
    }

    return FALSE;
}

INT Application::
ExitInstance()
{
    if (SW_HIDE != m_nCmdShow)
        if (!FreeConsole())
            DpWarnFwLE(TEXT("FreeConsole"));
    DcMeth();
    return CWinApp::ExitInstance();
}

#// Implementation

BOOL WINAPI Application::
HandlerRoutine(DWORD dwCtrlType)
{
    switch (dwCtrlType) {
    case CTRL_C_EVENT://fall-through
    case CTRL_BREAK_EVENT:
        break;
    case CTRL_CLOSE_EVENT://fall-through
    case CTRL_LOGOFF_EVENT://fall-through
    case CTRL_SHUTDOWN_EVENT: {
        Application * pApp = dynamic_cast<Application *>(AfxGetApp());
        if (pApp && pApp->IsKindOf(RUNTIME_CLASS(Application)))
            pApp->ExitInstance();
        break;
    }
    default:
        break;
    }
    return TRUE;
}

std::vector<CString> Application::
TokenizeCommandLine(CONST CString &commandLine)
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

VOID Application::
ShowHello()
{
    ClearConsoleScreen();
    ConsoleColorPut(TEXT("\n")
                    TEXT("                        _/      _/  _/_/_/_/    _/_/_/   \n")
                    TEXT("   _/  _/_/  _/  _/_/  _/_/  _/_/  _/        _/          \n")
                    TEXT("  _/_/      _/_/      _/  _/  _/  _/_/_/    _/           \n")
                    TEXT(" _/        _/        _/      _/  _/        _/            \n")
                    TEXT("_/        _/        _/      _/  _/          _/_/_/       \n")
                    TEXT("\n")
                    TEXT("      _/_/                        _/  _/                        _/      _/                     \n")
                    TEXT("   _/    _/  _/_/_/    _/_/_/    _/        _/_/_/    _/_/_/  _/_/_/_/        _/_/    _/_/_/    \n")
                    TEXT("  _/_/_/_/  _/    _/  _/    _/  _/  _/  _/        _/    _/    _/      _/  _/    _/  _/    _/   \n")
                    TEXT(" _/    _/  _/    _/  _/    _/  _/  _/  _/        _/    _/    _/      _/  _/    _/  _/    _/    \n")
                    TEXT("_/    _/  _/_/_/    _/_/_/    _/  _/    _/_/_/    _/_/_/      _/_/  _/    _/_/    _/    _/     \n")
                    TEXT("         _/        _/                                                                          \n")
                    TEXT("        _/        _/                                                                           \n")
                    TEXT("\n"));
    ConsoleColorPut(White, TEXT("Command line interface is "), Green, TEXT("enabled"), White, TEXT(".\n"));
}

VOID Application::
ShowUnknown(CONST std::vector<CString> &tokens)
{
    if (!tokens.empty())
        ConsoleColorPut(White, TEXT("The command "), Aqua, static_cast<LPCTSTR>(tokens[0]), White, TEXT(" is unknown. "));
    ConsoleColorPut(White, TEXT("Enter "), Aqua, TEXT("help"), White, TEXT(" to list valid commands.\n"));
}

VOID Application::
ShowHelp(CONST std::vector<CString> &tokens)
{
    if (tokens.empty()) return;
    ConsoleColorPut(TEXT("Commands(case insensitivity):\n"));
    ConsoleColorPut(Aqua,
                    TEXT("   ?\n")
                    TEXT("   clearscreen\n")
                    TEXT("   close\n")
                    TEXT("   cls\n")
                    TEXT("   exit\n")
                    TEXT("   help\n")
                    TEXT("   quit\n")
                    TEXT("   status\n"));
}

VOID Application::
ShowStatus(CONST std::vector<CString> &tokens)
{
    if (tokens.empty()) return;
    ConsoleColorPut(TEXT("Status:\n"));
    ConsoleColorPrint(White,
                      TEXT("   Codepage input %u, output %u.\n"), GetConsoleCP(), GetConsoleOutputCP());
}
