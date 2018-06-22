/// \copyright The MIT License

#include "stdafx.h"
#include "App.h"

#include <conio.h>
#include <vector>

#include "rrwindows/conutil.h"
#include "rrwindows/dbgcon.h"

#// Constructors

Application::
Application()
{
    NewDebugConsole();
    DbgConMeth();
}

Application::
~Application()
{
    DbgConMeth();
    DeleteDebugConsole();
}

#// Overridables

BOOL Application::
InitApplication()
{
    DbgConMeth();
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConMeth();
    if (SW_HIDE != m_nCmdShow)
        AllocConsole();

    // Command Line Interface Loop
    SetConsoleForeGroundColor(LightAqua);
    ShowHello();
    TCHAR buf[512] = TEXT("");
    size_t len = 0;
    while (TRUE) {
        ConColPut(TEXT("\nEnter a command: "));
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
        FreeConsole();
    DbgConMeth();
    return CWinApp::ExitInstance();
}

#// Implementation

std::vector<CString> Application::
TokenizeCommandLine(CONST CString& commandLine)
{
    std::vector<CString> tokens;
    INT pos = 0;
    while (TRUE) {
        CONST CString token = commandLine.Tokenize(TEXT("\t\n\v\r "), pos);
        if (token.IsEmpty()) break;
        tokens.push_back(token);
    }
    return tokens;
}

VOID Application::
ShowHello()
{
    ClearConsoleScreen();
    ConColPut(TEXT("\n")
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
    ConColPut(White, TEXT("Command line interface is "), Green, TEXT("enabled"), White, TEXT(".\n"));
}

VOID Application::
ShowUnknown(CONST std::vector<CString> &tokens)
{
    if (!tokens.empty())
        ConColPut(White, TEXT("The command "), Aqua, static_cast<LPCTSTR>(tokens[0]), White, TEXT(" is unknown. "));
    ConColPut(White, TEXT("Enter "), Aqua, TEXT("help"), White, TEXT(" to list valid commands.\n"));
}

VOID Application::
ShowHelp(CONST std::vector<CString> &tokens)
{
    if (tokens.empty()) return;
    ConColPut(TEXT("Commands(case insensitivity):\n"));
    ConColPut(Aqua,
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
    ConColPut(TEXT("Status:\n"));
    ConColPrt(White,
              TEXT("   Codepage input %u, output %u.\n"), GetConsoleCP(), GetConsoleOutputCP());
}
