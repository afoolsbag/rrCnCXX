/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon(Red, TEXT("Application::"));
    DbgConPrt(LightRed, TEXT("Constructor\n"));
}

Application::
~Application()
{
    DbgConPrt(Red, TEXT("Application::"));
    DelDbgCon(LightRed, TEXT("Destructor\n"));
}

#// Overridables

BOOL Application::
InitApplication()
{
    DbgConPrt(Red, TEXT("Application::"));
    DbgConPrt(LightRed, TEXT("InitApplication\n"));
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(Red, TEXT("Application::"));
    DbgConPrt(LightRed, TEXT("InitInstance\n"));
    return FALSE;
}

INT Application::
ExitInstance()
{
    DbgConPrt(Red, TEXT("Application::"));
    DbgConPrt(LightRed, TEXT("ExitInstance\n"));
    return CWinApp::ExitInstance();
}
