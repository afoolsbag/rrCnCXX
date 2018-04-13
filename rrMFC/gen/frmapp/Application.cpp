/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include <conio.h>

#include "resource.h"
#include "ui/MainFrame.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

Application::Application()
{
#ifdef DEBUG
    if (!AllocConsole())
        AfxMessageBox("Allocate console failed!", MB_ICONEXCLAMATION);
#endif//DEBUG
    _cputts(TEXT("Application::Constructor\n"));
}

Application::~Application()
{
    _cputts(TEXT("Application::Destructor\n"));
#ifdef DEBUG
    AfxDebugBreak();
    if (!FreeConsole())
        AfxMessageBox("Free console failed!", MB_ICONEXCLAMATION);
#endif//DEBUG
}

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();
    _cputts(TEXT("Application::InitApplication\n"));

    m_pMainWnd = DEBUG_NEW MainFrame;
    dynamic_cast<MainFrame *>(m_pMainWnd)->LoadFrame(IDR_MAIN_FRAME);
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

INT Application::ExitInstance()
{
    _cputts(TEXT("Application::ExitInstance\n"));
    return CWinApp::ExitInstance();
}
