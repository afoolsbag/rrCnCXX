/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include <conio.h>
#include <vector>

#include "rrwindows/conutil.h"
#include "rrwindows/dbgcon.h"

namespace {

static std::vector<CString> SpliteCommand(const CString &command)
{
    std::vector<CString> tokens;
    INT pos = 0;
    while (TRUE) {
        CONST CString token = command.Tokenize(TEXT("\t\n\r "), pos);
        if (token.IsEmpty()) break;
        tokens.push_back(token);
    }
    return tokens;
}

}//namespace

IMPLEMENT_DYNAMIC(Application, CWinApp)

#// Constructors

Application::
Application()
{
    AllocConsole();
    DbgConPrtMeth(Red);
}

Application::
~Application()
{
    DbgConPrtMeth(Red);
    FreeConsole();
}

#// Overridables

BOOL Application::
InitApplication()
{
    DbgConPrtMeth(Red);
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    // Command Line UI Loop
    SetConsoleForeGroundColor(LightAqua);
    ShowHello();
    TCHAR buf[512] = TEXT("");
    size_t len = 0;
    while (TRUE) {
        ConColPrt(White, TEXT("\nEnter a command: ")); _cgetts_s(buf, &len);
        std::vector<CString> tokens = SpliteCommand(buf);
        if (tokens.empty()) continue;
        if (!tokens[0].CompareNoCase(TEXT("clearscreen")) || !tokens[0].CompareNoCase(TEXT("cls")))
            ShowHello();
        else if (!tokens[0].CompareNoCase(TEXT("?")) || !tokens[0].CompareNoCase(TEXT("help")))
            ShowHelp(tokens.size() < 2 ? TEXT("") : tokens[1]);
        else if (!tokens[0].CompareNoCase(TEXT("status")))
            ShowStatus();
        else if (!tokens[0].CompareNoCase(TEXT("quit")) || !tokens[0].CompareNoCase(TEXT("exit")))
            break;
        else
            ShowUnknown(tokens[0]);
#ifndef _UNICODE
        _cgetts_s(buf, &len);
#endif
    }

    return FALSE;
}

INT Application::
ExitInstance()
{
    DbgConPrtMeth(Red);
    return CWinApp::ExitInstance();
}

#// Implementation

VOID Application::
ShowHello()
{
    ClearConsoleScreen();
    ConColPut(White,
              TEXT("\n")
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
    ConColPut(White,
              TEXT("Command line interface is ")); ConColPut(Green, TEXT("enabled")); ConColPut(White, TEXT(".\n"));
}

VOID Application::
ShowHelp(CONST CString &param)
{
    if (!param.CompareNoCase(TEXT("console"))) {
        ConColPrt(White,
                  TEXT("Codepage: input %u, output %u.\n"), GetConsoleCP(), GetConsoleOutputCP());
    } else {
        ConColPut(White,
                  TEXT("Commands(case insensitivity):\n"));
        ConColPut(Aqua,
                  TEXT("   ?\n")
                  TEXT("   clearscreen\n")
                  TEXT("   cls\n")
                  TEXT("   exit\n")
                  TEXT("   help [console]\n")
                  TEXT("   quit\n")
                  TEXT("   status\n"));
    }
}

VOID Application::
ShowStatus()
{
    ConColPut(White,
              TEXT("Status:\n"));
    ConColPut(LightRed,
              TEXT("   Resource A: 97%%\n"));
    ConColPut(Green,
              TEXT("   Resource B: 42%%\n"));
    ConColPut(Yellow,
              TEXT("   Resource C: 66%%\n"));
    ConColPut(White,
              TEXT("   Progress 0: [## 74%% ###################################################################..........................]\n")
              TEXT("   Progress 1: [## 53%% ##############################################...............................................]\n")
              TEXT("   Progress 2: [## 88%% #################################################################################............]\n")
              TEXT("   Progress 3: [## 46%% #######################################......................................................]\n")
              TEXT("   Progress 4: [## 24%% #################............................................................................]\n")
              TEXT("   Progress 5: [##  5%% .............................................................................................]\n")
              TEXT("   Progress 6: [## 92%% #####################################################################################........]\n")
              TEXT("   Progress 7: [## 13%% ######.......................................................................................]\n"));
}

VOID Application::
ShowUnknown(CONST CString &command)
{
    ConColPut(White, TEXT("The command "));
    ConColPut(Aqua, static_cast<LPCTSTR>(command));
    ConColPut(White, TEXT(" is unknown. Enter "));
    ConColPut(Aqua, TEXT("help"));
    ConColPut(White, TEXT(" to list valid commands.\n"));
}
