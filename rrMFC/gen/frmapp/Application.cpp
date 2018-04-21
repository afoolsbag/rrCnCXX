/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.inl"

#include "resource.h"
#include "ui/MainFrame.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
}

#// Overridables

Application::
~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(LightRed, TEXT("Application::InitApplication\n"));

    m_pMainWnd = DEBUG_NEW MainFrame;
    dynamic_cast<MainFrame *>(m_pMainWnd)->LoadFrame(MainFrame::IDR);
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

INT Application::
ExitInstance()
{
    DbgConPrt(LightRed, TEXT("Application::ExitInstance\n"));
    return CWinApp::ExitInstance();
}
