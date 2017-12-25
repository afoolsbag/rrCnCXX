/** \copyright The MIT License */

#include "accel.hpp"

#define LINESIZE 8

CMyApp myApp;

/// Class My Application :: Initialize Instance.
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

/// Class Main Window :: Constructor.
CMainWindow::CMainWindow()
{
    Create(                    // 创建窗口：
        NULL,                  // 默认框架；
        _T("Accel"),           // 自定义标题；
          WS_OVERLAPPEDWINDOW  // 标题、系统菜单、最小化、最大化、边框、缩放；
        | WS_HSCROLL           // 水平滚动条；
        | WS_VSCROLL           // 垂直滚动条。
    );
}

/// Class Main Window :: On Create.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cclientdc-class>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cdc-class#getdevicecaps>.
 */
int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (-1 == CFrameWnd::OnCreate(lpCreateStruct))  // 此函数应当总是调用其基类函数。
        return -1;

    CClientDC dc(this);
    // Cell     1.  in. *   .25 in.
    // Ribbon    .5 in. *   .25 in.
    // View    26.5 in. * 25.   in.
    m_nCellWidth = dc.GetDeviceCaps(LOGPIXELSX);       // 水平方向，一英寸对应像素数；
    m_nCellHeight = dc.GetDeviceCaps(LOGPIXELSY) / 4;  // 垂直方向，一英寸对应像素数
    m_nRibbonWidth = m_nCellWidth / 2;
    m_nViewWidth = 26 * m_nCellWidth + m_nRibbonWidth;
    m_nViewHeight = 100 * m_nCellHeight;
    return 0;
}

/// Class Main Window :: On Size.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsize>.
 *  \sa <https://msdn.microsoft.com/library/bb787537.aspx>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#setscrollinfo>.
 */
void CMainWindow::OnSize(UINT nType, int cx, int cy)
{
    CFrameWnd::OnSize(nType, cx, cy);

    // 初始化
    int nHScrollMax = 0;
    m_nHScrollPos = m_nHPageSize = 0;

    // 若逻辑尺寸大于设备尺寸（太宽，一页放不下）
    if (cx < m_nViewWidth) {
        nHScrollMax = m_nViewWidth - 1;
        m_nHPageSize = cx;
        m_nHScrollPos = min(m_nHScrollPos, m_nViewWidth - m_nHPageSize - 1);  // 防抖动
    }

    SCROLLINFO si;
    si.fMask = SIF_ALL;       // 等价于 SIF_PAGE|SIF_POS|SIF_RANGE;
    si.nMin = 0;              // 范围下限；
    si.nMax = nHScrollMax;    // 范围上限；
    si.nPos = m_nHScrollPos;  // 位置；
    si.nPage = m_nHPageSize;  // 页面尺寸。
    SetScrollInfo(            // 设置滚动条：
        SB_HORZ,              // 水平滚动条；
        &si,                  // 滚动条信息；
        TRUE                  // 需要重绘滚动条。
    );

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

/// Class Main Window :: On Paint.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setwindoworg>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cpen-class>.
 */
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);

    dc.SetWindowOrg(m_nHScrollPos, m_nVScrollPos);

    /* 画网格线 */
    CPen pen(PS_SOLID, 0, RGB(192, 192, 192));
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

/// Class Main Window :: On Horizontal Scroll.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onhscroll>.
 */
void CMainWindow::OnHScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar)
{
    int nDelta;

    switch (nCode) {
        case SB_LINELEFT: nDelta = -LINESIZE; break;                    // 箭头被单击；
        case SB_PAGELEFT: nDelta = -m_nHPageSize; break;                // 轨道被单击；
        case SB_THUMBTRACK: nDelta = (int)nPos - m_nHScrollPos; break;  // 滑块被拖动。
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

/// Class Main Window :: On Vertical Scroll.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onvscroll>.
 */
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
