/** \file
 *  \brief *Programming Windows with MFC* 3.1.8.
 *  \author zhengrr
 *  \date 2017-12-9
 *  \copyright The MIT License
 */
#ifdef ZRR_PWMFC_3_1_8

#include <afxwin.h>

/// CMyApp
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// CMainWindow
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();

protected:
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);

    BOOL m_bTracking;
    BOOL m_bCaptureEnabled;
    CPoint m_ptFrom;
    CPoint m_ptTo;

    void InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo);

    DECLARE_MESSAGE_MAP()
};

CMyApp myApp;

/// CMyApp::InitInstance
BOOL CMyApp::InitInstance()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_NCLBUTTONDOWN()
END_MESSAGE_MAP()

/// CMainWindow::CMainWindow
CMainWindow::CMainWindow()
{
    m_bTracking = FALSE;
    m_bCaptureEnabled = TRUE;

    CString strWndClass = AfxRegisterWndClass(
        0,
        AfxGetApp()->LoadStandardCursor(IDC_CROSS),
        (HBRUSH)(COLOR_WINDOW + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

    Create(strWndClass, _T("Mouse Capture Demo (Capture Enabled)"));
}

/// CMainWindow::OnLButtonDown
void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
    m_ptFrom = point;
    m_ptTo = point;
    m_bTracking = TRUE;
    if (m_bCaptureEnabled) SetCapture();
}

/// CMainWindow::OnLButtonUp
void CMainWindow::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (!m_bTracking) return;
    m_bTracking = FALSE;
    if (this == GetCapture()) ::ReleaseCapture();
    CClientDC dc(this);
    InvertLine(&dc, m_ptFrom, m_ptTo);

    CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
    dc.SelectObject(&pen);
    dc.MoveTo(m_ptFrom);
    dc.LineTo(point);
}

/// CMainWindow::OnMouseMove
void CMainWindow::OnMouseMove(UINT nFlags, CPoint point)
{
    if (!m_bTracking) return;
    CClientDC dc(this);
    InvertLine(&dc, m_ptFrom, m_ptTo);
    InvertLine(&dc, m_ptFrom, point);
    m_ptTo = point;
}

/// CMainWindow::OnNcLButtonDown
void CMainWindow::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
    if (HTCAPTION == nHitTest) {
        m_bCaptureEnabled = m_bCaptureEnabled ? FALSE : TRUE;
        SetWindowText(m_bCaptureEnabled ?
            _T("Mouse Capture Demo (Capture Enabled)") : _T("Mouse Capture Demo (Capture Disabled)"));
    }
    CFrameWnd::OnNcLButtonDown(nHitTest, point);
}

/// CMainWindow::InvertLine
void CMainWindow::InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo)
{
    int nOldMode = pDC->SetROP2(R2_NOT);
    pDC->MoveTo(ptFrom);
    pDC->LineTo(ptTo);
    pDC->SetROP2(nOldMode);
}

#endif// ZRR PWMFC 3.1.8
