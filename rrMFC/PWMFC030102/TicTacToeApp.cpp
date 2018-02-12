/// \copyright The MIT License

#include "stdafx.h"
#include "TicTacToeApp.h"

#include "TicTacToeMainWnd.h"

BOOL CTicTacToeApp::InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CTicTacToeMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
