/** \file
 *  \brief *Programming Windows with MFC* 1.3.
 *  \author zhengrr
 *  \date 2017-12-8 – 9
 *  \copyright The MIT License
 */
#ifdef ZRR_PWMFC_1_3

#include <afxwin.h>

/// CMyApp
class CMyApp : public CWinApp {  // [Class WINdows APPlication](https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class)
public:
    virtual BOOL InitInstance();  // [INITialize INSTANCE](https://docs.microsoft.com/cpp/mfc/reference/cwinapp-class#initinstance)
};

/// CMainWindow
class CMainWindow : public CFrameWnd {  // [Class FRAME WiNDow](https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class)
public:
    CMainWindow();
protected:
    afx_msg void OnPaint();  // [ON PAINT](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint)
    DECLARE_MESSAGE_MAP()
};

CMyApp myApp;

/// CMyApp::InitInstance
BOOL CMyApp::InitInstance()
{
    m_pMainWnd = new CMainWindow;  // [Member Pointer MAIN WiNDow](https://docs.microsoft.com/cpp/mfc/reference/cwinthread-class#m_pmainwnd)
    m_pMainWnd->ShowWindow(m_nCmdShow);  // [SHOW WINDOW](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#showwindow)
    m_pMainWnd->UpdateWindow();  // [UPDATE WINDOW](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#updatewindow)
    return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

/// CMainWindow::CMainWindow
CMainWindow::CMainWindow()
{
    Create(NULL, _T("The Hello Application"));  // [CREATE](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create)
}

/// CMainWindow::OnPaint
void CMainWindow::OnPaint()
{
    CRect rect;  // [Class RECT](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class)
    GetClientRect(&rect);  // [GETs CLIENT RECT](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#getclientrect)

    CPaintDC dc(this);  // [Class PAINT Device-Context](https://docs.microsoft.com/cpp/mfc/reference/cpaintdc-class)
    dc.DrawText(_T("Hello, MFC"), -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);  // [DRAW TEXT](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#drawtext)
}

#endif// ZRR PWMFC 1.3
