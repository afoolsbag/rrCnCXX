/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include <conio.h>

#include "rrwindows/conutil.h"
#include "rrwindows/dbgcon.h"

#include <string>

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
        _cputts(TEXT("\n"));
        ConColPrt(White, TEXT("Enter a command: ")); _cgetts_s(buf, &len);
        CString command(buf);
        command.Trim();
        if (!command.CompareNoCase(TEXT("clearscreen")) || !command.CompareNoCase(TEXT("cls")))
            ShowHello();
        else if (!command.CompareNoCase(TEXT("?")) || !command.CompareNoCase(TEXT("help")))
            ShowHelp();
        else if (!command.CompareNoCase(TEXT("status")))
            ShowStatus();
        else if (!command.CompareNoCase(TEXT("quit")) || !command.CompareNoCase(TEXT("exit")))
            break;
        else
            ShowUnknown(command);
        _cgetts_s(buf, &len);
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
    ConColPrt(White,
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
              TEXT("\n")
              TEXT("Command line interface is ")); ConColPrt(Green, TEXT("enabled")); ConColPrt(White, TEXT(".\n"));
}

VOID Application::
ShowHelp()
{
    ConColPrt(White,
              TEXT("Commands(case insensitivity):\n"));
    ConColPrt(Aqua,
              TEXT("   ?\n")
              TEXT("   clearscreen\n")
              TEXT("   cls\n")
              TEXT("   exit\n")
              TEXT("   help\n")
              TEXT("   quit\n")
              TEXT("   status\n"));
}

VOID Application::
ShowStatus()
{
    ConColPrt(White,
              TEXT("Status:\n"));
    ConColPrt(LightRed,
              TEXT("   Resource A: 97%%\n"));
    ConColPrt(Green,
              TEXT("   Resource B: 42%%\n"));
    ConColPrt(Yellow,
              TEXT("   Resource C: 66%%\n"));
    ConColPrt(White,
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
    ConColPrt(White, TEXT("The command ")); ConColPrt(Aqua, static_cast<LPCTSTR>(command)); ConColPrt(White, TEXT(" is unknown."));
    ConColPrt(White, TEXT(" Enter ")); ConColPrt(Aqua, TEXT("help")); ConColPrt(White, TEXT(" to list valid commands.\n"));
}
