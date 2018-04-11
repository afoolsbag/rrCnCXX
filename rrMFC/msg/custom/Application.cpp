/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "ui/HiddenWindow.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

BOOL Application::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new HiddenWindow;
#if TRUE
    m_pMainWnd->ShowWindow(SW_HIDE);
#else
    m_pMainWnd->ShowWindow(m_nCmdShow);
#endif
    m_pMainWnd->UpdateWindow();

    return TRUE;
}
