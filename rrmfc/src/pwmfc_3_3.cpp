/** \file
 *  \brief *Programming Windows with MFC* 3.3.
 *  \author zhengrr
 *  \date 2017-12-13
 *  \copyright The MIT License
 */
#include <afxwin.h>

#define MAX_STRINGS 12

namespace {

/// CMuApp
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// CMainWindow
class CMainWindow : public CWnd {
public:
    CMainWindow();

protected:
    int GetNearestPos(CPoint point);
    void PositionCaret(CDC *pDC = NULL);
    void DrawInputText(CDC *pCD);
    void ShowMessage(LPCTSTR pszMessage, UINT nChar, UINT nRepCnt, UINT nFlags);
    void DrawMessageHeader(CDC *pDC);
    void DrawMessage(CDC *pDC);

    virtual void PostNcDestroy();

    afx_msg int OnCreate(LPCREATESTRUCT lpcreatestruct);
    afx_msg void OnPaint();
    afx_msg void OnSetFocus(CWnd *pWnd);
    afx_msg void OnKillFocus(CWnd *pWnd);
    afx_msg BOOL OnSetCursor(CWnd *pWnd, UINT nHitTest, UINT message);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);

    int m_cxChar;
    int m_cyChar;
    int m_cyLine;
    int m_nTextPos;
    int m_nTabStop[7];
    int m_nTextLimit;
    int m_nMsgPos;

    HCURSOR m_hCursorArrow;
    HCURSOR m_hCursorIBeam;

    CPoint m_ptTextOrigin;
    CPoint m_ptHeaderOrigin;
    CPoint m_ptUpperMsgOrigin;
    CPoint m_ptLowerMsgOrigin;
    CPoint m_ptCaretPos;

    CRect m_rcTextBox;
    CRect m_rcTextBoxBorder;
    CRect m_rcMsgBoxBorder;
    CRect m_rcScroll;

    CString m_strInputText;
    CString m_strMessages[MAX_STRINGS];

    DECLARE_MESSAGE_MAP()
};

#ifndef RRMFC_PWMFC_3_3_CPP_
CMyApp myApp;
#endif

/// CMyApp::InitInstance
BOOL CMyApp::InitInstance()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_WM_SETFOCUS()
    ON_WM_KILLFOCUS()
    ON_WM_SETCURSOR()
    ON_WM_LBUTTONDOWN()
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()
    ON_WM_SYSKEYDOWN()
    ON_WM_SYSKEYUP()
    ON_WM_CHAR()
    ON_WM_SYSCHAR()
END_MESSAGE_MAP()

/// CMainWindow::CMainWindow
CMainWindow::CMainWindow()
{
    m_nTextPos = 0;
    m_nMsgPos = 0;

    m_hCursorArrow = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
    m_hCursorIBeam = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);

    CString strWndClass = AfxRegisterWndClass(
        0,
        NULL,
        (HBRUSH)(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

    CreateEx(
        0, strWndClass, _T("Visual Keyboard"),
        WS_OVERLAPPED|WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL);
}

///
int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if(-1 == CWnd::OnCreate(lpCreateStruct))
        return -1;

    CClientDC dc(this);

    TEXTMETRIC tm;
    dc.GetTextMetrics(&tm);
    m_cxChar = tm.tmAveCharWidth;
    m_cyChar = tm.tmHeight;
    m_cyLine = tm.tmHeight + tm.tmExternalLeading;

    m_rcTextBoxBorder.SetRect(
        16,
        16,
        64 * m_cxChar + 16,
        3 * m_cyChar / 2 + 16);
    m_rcTextBox = m_rcTextBoxBorder;
    m_rcTextBox.InflateRect(-2, -2);

    m_rcMsgBoxBorder.SetRect(
        16,
        4 * m_cyChar + 16,
        64 * m_cxChar + 16,
        MAX_STRINGS * m_cyLine + 6 * m_cyChar + 16);
    m_rcScroll.SetRect(
        m_cxChar + 16,
        6 * m_cyChar + 16,
        63 * m_cxChar + 16,
        MAX_STRINGS * m_cyLine + 5 * m_cyChar + 16);

    m_ptTextOrigin.x = m_cxChar + 16;
    m_ptTextOrigin.y = m_cyChar / 4 + 16;
    m_ptCaretPos = m_ptTextOrigin;
    m_nTextLimit = 63 * m_cxChar + 16;

    m_ptHeaderOrigin.x = m_cxChar + 16;

}

}// namespace
