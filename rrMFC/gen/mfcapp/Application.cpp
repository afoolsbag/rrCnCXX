/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "ui/MainWindow.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new MainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

INT Application::ExitInstance()
{
    return CWinApp::ExitInstance();
}
