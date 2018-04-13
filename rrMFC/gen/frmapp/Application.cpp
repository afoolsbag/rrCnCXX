/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "resource.h"
#include "ui/MainFrame.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

Application::Application()
{}

Application::~Application()
{}

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

#ifdef DEBUG
    if (!AllocConsole())
        AfxMessageBox("Allocate console failed!", MB_ICONEXCLAMATION);
#endif

    m_pMainWnd = DEBUG_NEW MainFrame;
    dynamic_cast<MainFrame *>(m_pMainWnd)->LoadFrame(IDR_MAIN_FRAME);
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

INT Application::ExitInstance()
{
#ifdef DEBUG
    AfxDebugBreak();
    if (!FreeConsole())
        AfxMessageBox("Free console failed!", MB_ICONEXCLAMATION);
#endif

    return CWinApp::ExitInstance();
}
