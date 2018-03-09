/// \copyright The MIT License

#include "stdafx.h"
#include "VisualKeyboardApp.h"

#include "VisualKeyboardMainWnd.h"

BOOL CVisualKeyboardApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CVisualKeyboardMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
