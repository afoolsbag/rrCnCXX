/// \copyright The MIT License

#include "stdafx.h"
#include "RulerApp.h"

#include "RulerMainWnd.h"

BOOL CRulerApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CRulerMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
