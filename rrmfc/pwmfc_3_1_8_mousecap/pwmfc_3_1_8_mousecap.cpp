/** \file
 *  \brief *Programming Windows with MFC* 3.1.8 MouseCap.
 *  \author zhengrr
 *  \date 2017-12-9 – 14
 *  \copyright The MIT License
 */
#include <afxwin.h>

namespace {

/// Class MY APPlication.
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// Class MAIN WINDOW.
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

// -------------------------------------------------------------------------

#ifdef RRMFC_PWMFC_3_1_8_MOUSECAP_CPP_
CMyApp myApp;
#endif

/// Class MY APPlication :: INITialize INSTANCE.
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

/// Class MAIN WINDOW :: Constructor.
CMainWindow::CMainWindow()
{
    m_bTracking = FALSE;
    m_bCaptureEnabled = TRUE;

    CString strWndClass = AfxRegisterWndClass(
        0,
        AfxGetApp()->LoadStandardCursor(IDC_CROSS),
        (HBRUSH)(COLOR_WINDOW + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    Create(strWndClass, _T("Mouse Capture Demo (Capture Enabled)"));
}

/// Class MAIN WINDOW :: ON Left BUTTON DOWN
void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
    m_ptFrom = point;
    m_ptTo = point;
    m_bTracking = TRUE;
    if (m_bCaptureEnabled)
        SetCapture();
}

/// Class MAIN WINDOW :: ON Left BUTTON UP
void CMainWindow::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (!m_bTracking)
        return;
    m_bTracking = FALSE;
    if (this == GetCapture())
        ::ReleaseCapture();
    CClientDC dc(this);
    InvertLine(&dc, m_ptFrom, m_ptTo);

    CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
    dc.SelectObject(&pen);
    dc.MoveTo(m_ptFrom);
    dc.LineTo(point);
}

/// Class MAIN WINDOW :: ON MOUSE MOVE
void CMainWindow::OnMouseMove(UINT nFlags, CPoint point)
{
    if (!m_bTracking)
        return;
    CClientDC dc(this);
    InvertLine(&dc, m_ptFrom, m_ptTo);
    InvertLine(&dc, m_ptFrom, point);
    m_ptTo = point;
}

/// Class MAIN WINDOW :: ON NonClient Left BUTTON DOWN
void CMainWindow::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
    if (HTCAPTION == nHitTest) {
        m_bCaptureEnabled = m_bCaptureEnabled ? FALSE : TRUE;
        SetWindowText(m_bCaptureEnabled ?
            _T("Mouse Capture Demo (Capture Enabled)") : _T("Mouse Capture Demo (Capture Disabled)"));
    }
    CFrameWnd::OnNcLButtonDown(nHitTest, point);
}

/// Class MAIN WINDOW :: INVERT LINE
void CMainWindow::InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo)
{
    int nOldMode = pDC->SetROP2(R2_NOT);

    pDC->MoveTo(ptFrom);
    pDC->LineTo(ptTo);

    pDC->SetROP2(nOldMode);
}

}// namespace
