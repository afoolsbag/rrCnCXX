/** \file
 *  \brief *Programming Windows with MFC* 1.3 Hello.
 *  \author zhengrr
 *  \date 2017-12-8 – 14
 *  \copyright The MIT License
 */
#include <afxwin.h>

namespace {

/// Class MY APPlication.
/** \sa [Class WINdows APPlication](https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class). */
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();
};

/*
 * 议题：为什么是 AFX：
 *
 * 　　一言蔽之，历史遗留问题。"Microsoft Foundation Class Library" 提出太晚，而
 * 之前她的名字是 "Application Framework eXtensions"。
 *
 * 参见：<https://wikipedia.org/wiki/Application_Framework_eXtensions>。
 */

/// Class MAIN WINDOW.
/** \sa [Class FRAME WiNDow](https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class). */
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();

protected:
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};

// -------------------------------------------------------------------------

#ifdef RRMFC_PWMFC_1_3_HELLO_CPP_
CMyApp myApp;
#endif

/*
 * 议题："delete CMainWindow" 在哪：
 *
 * 　　CMainWindow 继承自 CFreamWnd，而 CFreamWnd 在 OnNcDestroy 回调中会 "delete this"，
 * 因而无需关注。
 * 　　但，CFreamWnd 的父类 CWnd 没有此操作，因而直接继承于 CWnd 的类需要关注其销毁。
 */

/// Class MY APPlication :: INITialize INSTANCE.
/** \sa [INITialize INSTANCE](https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance).
 *  \sa [Member Pointer MAIN WiNDow](https://docs.microsoft.com/cpp/mfc/reference/cwinthread-class#m_pmainwnd).
 *  \sa [SHOW WINDOW](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#showwindow).
 *  \sa [UPDATE WINDOW](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#updatewindow).
 */
BOOL CMyApp::InitInstance()
{
    // 此函数基类函数默认操作直接返回 TURE，因而无需调用。
    m_pMainWnd = new CMainWindow;        // 创建窗口类；
    m_pMainWnd->ShowWindow(m_nCmdShow);  // 按给定方式，显示窗口；
    m_pMainWnd->UpdateWindow();          // 重绘窗口；
    return TRUE;                         // 返回 FALSE 可关闭应用。
}

/// Class MY APPlication :: EXIT INSTANCE.
/** \sa [EXIT INSTANCE](https://docs.microsoft.com/zh-cn/cpp/mfc/reference/cwinapp-class#exitinstance). */
int CMyApp::ExitInstance()
{
    return CWinApp::ExitInstance();  // 调用基类函数；此函数返回值将作为退出代码。
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

/// Class MAIN WINDOW :: Constructor.
/** \sa [CREATE](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create). */
CMainWindow::CMainWindow()
{
    Create(                          // 创建窗口：
        NULL,                        // 默认框架；
        _T("The Hello Application")  // 自定义标题。
    );
}

/// Class MAIN WINDOW :: ON PAINT.
/** \sa [ON PAINT](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint).
 *  \sa [Class PAINT Device-Context](https://docs.microsoft.com/cpp/mfc/reference/cpaintdc-class).
 *  \sa [Class RECT](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class).
 *  \sa [GETs CLIENT RECT](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#getclientrect).
 *  \sa [DRAW TEXT](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#drawtext).
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

}// namespace
