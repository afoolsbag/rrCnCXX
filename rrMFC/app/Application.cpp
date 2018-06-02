/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNAMIC(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon();
    DbgConPrtMeth(Red);
}

Application::
~Application()
{
    DbgConPrtMeth(Red);
    DelDbgCon();
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
    return FALSE;
}

INT Application::
ExitInstance()
{
    DbgConPrtMeth(Red);
    return CWinApp::ExitInstance();
}
