/** \copyright The MIT License */

#include "hello.hpp"

CMyApp myApp;

/*
 * 议题："delete CMainWindow" 在哪：
 *
 * 　　CMainWindow 继承自 CFreamWnd，而 CFreamWnd 在 OnNcDestroy 回调中会 "delete this"，
 * 因而无需关注。
 * 　　但，CFreamWnd 的父类 CWnd 没有此操作，因而直接继承于 CWnd 的类需要关注其销毁。
 */

/// Class My Application :: Initialize Instance.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cwinthread-class#m_pmainwnd>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#showwindow>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#updatewindow>.
 */
BOOL CMyApp::InitInstance()
{
    // 此函数基类函数默认操作直接返回 TURE，因而无需调用。
    m_pMainWnd = new CMainWindow;        // 创建窗口类；
    m_pMainWnd->ShowWindow(m_nCmdShow);  // 按给定方式，显示窗口；
    m_pMainWnd->UpdateWindow();          // 重绘窗口；
    return TRUE;                         // 返回 FALSE 可关闭应用。
}

/// Class My Application :: Exit Instance.
/** \sa <https://docs.microsoft.com/zh-cn/cpp/mfc/reference/cwinapp-class#exitinstance>. */
int CMyApp::ExitInstance()
{
    return CWinApp::ExitInstance();  // 调用基类函数；此函数返回值将作为退出代码。
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

/// Class Main Window :: Constructor.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create>. */
CMainWindow::CMainWindow()
{
    Create(                          // 创建窗口：
        NULL,                        // 默认框架；
        _T("The Hello Application")  // 自定义标题。
    );
}

/// Class Main Window :: On Paint.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cpaintdc-class>.
 *  \sa <https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#getclientrect>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cdc-class#drawtext>.
 */
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);

    CRect rect;
    GetClientRect(&rect);                   // 获取窗口用户区（矩形）；

    dc.DrawText(                            // 绘制文本（前景色）：
        _T("Hello, MFC"),                   // 文本内容；
        -1,                                 // 文本长度；
        &rect,                              // 绘制区域（背景色）；
        DT_SINGLELINE|DT_CENTER|DT_VCENTER  // 单行、水平居中，垂直居中。
    );
}
