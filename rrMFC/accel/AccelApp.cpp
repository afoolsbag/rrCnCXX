/// \copyright The MIT License

#include "stdafx.h"
#include "AccelApp.h"

#include "AccelMainWnd.h"

BOOL CAccelApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CAccelMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
