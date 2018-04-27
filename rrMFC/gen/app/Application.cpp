/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
}

Application::
~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

#// Overridables

BOOL Application::
InitApplication()
{
    DbgConPrt(LightRed, TEXT("Application::InitApplication\n"));
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(LightRed, TEXT("Application::InitInstance\n"));
    return FALSE;
}

INT Application::
ExitInstance()
{
    DbgConPrt(LightRed, TEXT("Application::ExitInstance\n"));
    return CWinApp::ExitInstance();
}
