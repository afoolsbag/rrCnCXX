/// \copyright The MIT License

#include "Window/stdafx.h"
#include "Window/WindowApp.h"

#include "Window/WindowMainWnd.h"

BOOL CWindowApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CWindowMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
