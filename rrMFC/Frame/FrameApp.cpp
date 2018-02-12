/// \copyright The MIT License

#include "Frame/stdafx.h"
#include "Frame/FrameApp.h"

#include "Frame/FrameMainWnd.h"

BOOL CFrameApp::InitInstance()
{
    // 此函数基类函数默认操作直接返回`TURE`，因而无需调用
    CWinApp::InitInstance();

    // 创建窗口类
    m_pMainWnd = new CFrameMainWnd;
    // https://docs.microsoft.com/cpp/mfc/reference/cwinthread-class#m_pmainwnd

    // 按给定方式，显示窗口
    m_pMainWnd->ShowWindow(m_nCmdShow);
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#showwindow

    // 重绘窗口
    m_pMainWnd->UpdateWindow();
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#updatewindow

    // 返回`FALSE`可关闭应用
    return TRUE;
}

INT CFrameApp::ExitInstance()
{
    // 调用基类函数，此函数返回值将作为退出代码
    return CWinApp::ExitInstance();
}
