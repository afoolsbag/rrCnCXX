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
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(Red, TEXT("Application::"));
    DbgConPrt(LightRed, TEXT("InitInstance\n"));

    m_pMainWnd = DEBUG_NEW MainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}
