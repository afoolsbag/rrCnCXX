/** \file
 *  \brief *Programming Windows with MFC* 2.3.6.
 *  \author zhengrr
 *  \date 2017-12-8 – 13
 *  \copyright The MIT License
 */
#include <afxwin.h>

#define LINESIZE 8

namespace {

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
    afx_msg void OnPaint();
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);  // [ON CREATE](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate)
    afx_msg void OnSize(UINT nType, int cx, int cy);  // [ON SIZE changed](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize)
    afx_msg void OnHScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);  // [ON Horizontal SCROLL bar](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onhscroll)
    afx_msg void OnVScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);  // [ON Vertical SCROLL bar](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onvscroll)

    int m_nCellWidth;    ///< 单元格宽度；
    int m_nCellHeight;   ///< 单元格高度；
    int m_nRibbonWidth;  ///< 行头宽度；
    int m_nViewWidth;    ///< 工作区宽度；
    int m_nViewHeight;   ///< 工作区高度；
    int m_nHScrollPos;   ///< 水平滚动条位置；
    int m_nVScrollPos;   ///< 垂直滚动条位置；
    int m_nHPageSize;    ///< 页面宽度；
    int m_nVPageSize;    ///< 页面高度。

    DECLARE_MESSAGE_MAP()
};

#ifdef RRMFC_PWMFC_2_3_6_CPP_
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

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_PAINT()
    ON_WM_HSCROLL()
    ON_WM_VSCROLL()
END_MESSAGE_MAP()

/// CMainWindow::CMainWindow
CMainWindow::CMainWindow()
{
    Create(NULL, _T("Accel"), WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL);
}

/// CMainWindow::OnCreate
int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (-1 == CFrameWnd::OnCreate(lpCreateStruct))
        return -1;

    CClientDC dc(this);  // [Class CLIENT Device-Context](https://docs.microsoft.com/cpp/mfc/reference/cclientdc-class)
    m_nCellWidth = dc.GetDeviceCaps(LOGPIXELSX);  // [GETs DEVICE CAPS](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#getdevicecaps)
    m_nCellHeight = dc.GetDeviceCaps(LOGPIXELSY)/4;
    m_nRibbonWidth = m_nCellWidth/2;
    m_nViewWidth = 26 * m_nCellWidth + m_nRibbonWidth;
    m_nViewHeight = 100 * m_nCellHeight;
    return 0;
}

/// CMainWindow::OnSize
void CMainWindow::OnSize(UINT nType, int cx, int cy)
{
    CFrameWnd::OnSize(nType, cx, cy);

    int nHScrollMax = 0;
    m_nHScrollPos = m_nHPageSize = 0;
    if (cx < m_nViewWidth) {
        nHScrollMax = m_nViewWidth - 1;
        m_nHPageSize = cx;
        m_nHScrollPos = min(m_nHScrollPos, m_nViewWidth - m_nHPageSize - 1);
    }

    SCROLLINFO si;  // [SCROLL INFOrmation](https://msdn.microsoft.com/library/bb787537.aspx)
    si.fMask = SIF_PAGE|SIF_RANGE|SIF_POS;
    si.nMin = 0;
    si.nMax = nHScrollMax;
    si.nPos = m_nHScrollPos;
    si.nPage = m_nHPageSize;
    SetScrollInfo(SB_HORZ, &si, TRUE);  // [SET SCROLL INFOrmation](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#setscrollinfo)

    int nVScrollMax = 0;
    m_nVScrollPos = m_nVPageSize = 0;
    if (cy < m_nViewHeight) {
        nVScrollMax = m_nViewHeight - 1;
        m_nVPageSize = cy;
        m_nVScrollPos = min(m_nVScrollPos, m_nViewHeight - m_nVPageSize - 1);
    }

    si.fMask = SIF_PAGE|SIF_RANGE|SIF_POS;
    si.nMin = 0;
    si.nMax = nVScrollMax;
    si.nPos = m_nVScrollPos;
    si.nPage = m_nVPageSize;
    SetScrollInfo(SB_VERT, &si, TRUE);
}

/// CMainWindow::OnPaint
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);

    dc.SetWindowOrg(m_nHScrollPos, m_nVScrollPos);  // [SETs Window ORiGin](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setwindoworg)

    /* 画网格线 */
    CPen pen(PS_SOLID, 0, RGB(192, 192, 192));  // [Class PEN](https://docs.microsoft.com/cpp/mfc/reference/cpen-class)
    CPen *pOldPen = dc.SelectObject(&pen);

    for (int i = 0; i < 99; ++i) {
        int y = i * m_nCellHeight + m_nCellHeight;
        dc.MoveTo(0, y);
        dc.LineTo(m_nViewWidth, y);
    }

    for (int j = 0; j < 26; ++j) {
        int x = j * m_nCellWidth + m_nRibbonWidth;
        dc.MoveTo(x, 0);
        dc.LineTo(x, m_nViewWidth);
    }

    dc.SelectObject(pOldPen);

    /* 画头行、头列 */
    CBrush brush;
    brush.CreateStockObject(LTGRAY_BRUSH);

    CRect rcTop(0, 0, m_nViewWidth, m_nCellHeight);
    dc.FillRect(rcTop, &brush);
    CRect rcLeft(0, 0, m_nRibbonWidth, m_nViewHeight);
    dc.FillRect(rcLeft, &brush);

    dc.MoveTo(0, m_nCellHeight);
    dc.LineTo(m_nViewWidth, m_nCellHeight);
    dc.MoveTo(m_nRibbonWidth, 0);
    dc.LineTo(m_nRibbonWidth, m_nViewHeight);

    /* 画列头、行头 */
    dc.SetBkMode(TRANSPARENT);
    for (int i = 0; i < 99; ++i) {
        int y = i * m_nCellHeight + m_nCellHeight;
        dc.MoveTo(0, y);
        dc.LineTo(m_nRibbonWidth, y);

        CString string;
        string.Format(_T("%d"), 1 + i);

        CRect rect(0, y, m_nRibbonWidth, y + m_nCellHeight);
        dc.DrawText(string, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);

        rect.top++;
        dc.Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128));
    }

    for (int j = 0; j < 26; ++j) {
        int x = j * m_nCellWidth + m_nRibbonWidth;
        dc.MoveTo(x, 0);
        dc.LineTo(x, m_nCellHeight);

        CString string;
        string.Format(_T("%c"), 'A' + j);
         CRect rect(x, 0, x + m_nCellWidth, m_nCellHeight);
         dc.DrawText(string, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);

         rect.left++;
         dc.Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128));
    }
}

/// CMainWindow::OnHScroll
void CMainWindow::OnHScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar)
{
    int nDelta;

    switch (nCode) {
        case SB_LINELEFT: nDelta = -LINESIZE; break;
        case SB_PAGELEFT: nDelta = -m_nHPageSize; break;
        case SB_THUMBTRACK: nDelta = (int)nPos - m_nHScrollPos; break;
        case SB_PAGERIGHT: nDelta = m_nHPageSize; break;
        case SB_LINERIGHT: nDelta = LINESIZE; break;
        default: return;
    }

    int nScrollPos = m_nHScrollPos + nDelta;
    int nMaxPos = m_nViewWidth - m_nHPageSize;

    if (nScrollPos < 0)
        nDelta = -m_nHScrollPos;
    else if (nScrollPos > nMaxPos)
        nDelta = nMaxPos - m_nHScrollPos;

    if (0 != nDelta) {
        m_nHScrollPos += nDelta;
        SetScrollPos(SB_HORZ, m_nHScrollPos, TRUE);
        ScrollWindow(-nDelta, 0);
    }
}

/// CMainWindow::OnVScroll
void CMainWindow::OnVScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar)
{
    int nDelta;

    switch (nCode) {
        case SB_LINEUP: nDelta = -LINESIZE; break;
        case SB_PAGEUP: nDelta = -m_nVPageSize; break;
        case SB_THUMBTRACK: nDelta = (int)nPos - m_nVScrollPos; break;
        case SB_PAGEDOWN: nDelta = m_nVPageSize; break;
        case SB_LINEDOWN: nDelta = LINESIZE; break;
        default: return;
    }

    int nScrollPos = m_nVScrollPos + nDelta;
    int nMaxPos = m_nViewHeight - m_nVPageSize;

    if (nScrollPos < 0)
        nDelta = -m_nVScrollPos;
    else if (nScrollPos > nMaxPos)
        nDelta = nMaxPos - m_nVScrollPos;

    if (0 != nDelta) {
        m_nVScrollPos += nDelta;
        SetScrollPos(SB_VERT, m_nVScrollPos, TRUE);
        ScrollWindow(0, -nDelta);
    }
}

}// namespace
