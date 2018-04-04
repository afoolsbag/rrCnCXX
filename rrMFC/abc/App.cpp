/// \copyright The MIT License

#include "stdafx.h"
#include "App.h"

#include "MainWnd.h"

BOOL CApp::InitInstance()
{
    // 基类函数默认操作直接返回`TURE` 
    CWinApp::InitInstance();

    // 创建窗口 
    // https://docs.microsoft.com/cpp/mfc/reference/cwinthread-class#m_pmainwnd
    m_pMainWnd = new CMainWnd;

    // 显示窗口 
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#showwindow
    m_pMainWnd->ShowWindow(m_nCmdShow);

    // 重绘窗口 
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#updatewindow
    m_pMainWnd->UpdateWindow();

    // 返回`FALSE`可关闭应用 
    return TRUE;
}

INT CApp::ExitInstance()
{
    // 调用基类函数，此函数返回值将作为退出状态 
    return CWinApp::ExitInstance();
}
