/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

#include "ui/MainWindow.h"

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
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(LightRed, TEXT("Application::InitInstance\n"));
    m_pMainWnd = DEBUG_NEW MainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
