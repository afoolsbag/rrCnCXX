/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon();
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("Constructor\n"));
}

Application::
~Application()
{
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("Destructor\n"));
    DelDbgCon();
}

#// Overridables

BOOL Application::
InitApplication()
{
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("InitApplication\n"));
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("InitInstance\n"));
    return FALSE;
}

INT Application::
ExitInstance()
{
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("ExitInstance\n"));
    return CWinApp::ExitInstance();
}
