/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

#include "ui/MainWindow.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

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
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    m_pMainWnd = DEBUG_NEW MainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}
