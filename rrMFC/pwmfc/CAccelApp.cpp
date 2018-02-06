/// \copyright The MIT License

#include "CAccelApp.h"

namespace {
const int kLineSize = 8;
}// namespace


CAccelApp gApp;


BOOL CAccelApp::InitInstance()
{
    m_pMainWnd = new CAccelMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}


BEGIN_MESSAGE_MAP(CAccelMainWnd, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_PAINT()
    ON_WM_HSCROLL()
    ON_WM_VSCROLL()
END_MESSAGE_MAP()

CAccelMainWnd::CAccelMainWnd()
{
    // 创建窗口
    Create(NULL,                // 默认框架
           TEXT("Accel"),       // 自定义标题
           WS_OVERLAPPEDWINDOW  // 标题、系统菜单、最小化、最大化、边框、缩放；
           | WS_HSCROLL         // 水平滚动条
           | WS_VSCROLL);       // 垂直滚动条
}

// https://docs.microsoft.com/cpp/mfc/reference/cclientdc-class
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#getdevicecaps
int CAccelMainWnd::OnCreate(LPCREATESTRUCT infoptrCreate)
{
    // 此函数应当总是调用其基类函数
    if (-1 == CFrameWnd::OnCreate(infoptrCreate))
        return -1;

    CClientDC dc(this);
    //      Ribbon Cell x 26
    // Cell
    //   x               .25 in
    //  100 .5 in  1 in
    cellWidth_ = dc.GetDeviceCaps(LOGPIXELSX);      // 水平方向，一英寸对应像素数
    ribbonWidth_ = cellWidth_ / 2;
    cellHeight_ = dc.GetDeviceCaps(LOGPIXELSY) / 4;  // 垂直方向，一英寸对应像素数
    sheetWidth_ = ribbonWidth_ + 26 * cellWidth_;
    sheetHeigth_ = 100 * cellHeight_;
    return 0;
}

// https://msdn.microsoft.com/library/bb787537.aspx
// https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#setscrollinfo
void CAccelMainWnd::OnSize(UINT tySize, INT wdClient, INT htClient)
{
    CFrameWnd::OnSize(tySize, wdClient, htClient);

    clientWidth = wdClient;
    clientHeight = htClient;
    SCROLLINFO infoScoll;

    // 水平滚动条
    INT hmaxHrzScroll = 0;
    hposHrzScroll_ = 0;

    // 若表格尺寸大于用户区尺寸（太宽，一页放不下）
    if (clientWidth < sheetWidth_) {
        hmaxHrzScroll = sheetWidth_ - 1;
        hposHrzScroll_ = min(hposHrzScroll_, sheetWidth_ - wdClient_ - 1);  // 防抖动
    }

    infoScoll.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    infoScoll.nMin = 0;               // 范围下限
    infoScoll.nMax = hmaxHrzScroll;   // 范围上限
    infoScoll.nPage = clientWidth;      // 页面尺寸
    infoScoll.nPos = hposHrzScroll_;  // 位置
    // 设置滚动条
    SetScrollInfo(SB_HORZ,     // 水平滚动条
                  &infoScoll,  // 滚动条信息
                  TRUE);       // 需要重绘滚动条

    // 垂直滚动条，同水平滚动条
    INT vmaxVrtScroll = 0;
    vposVrtScroll_ = 0;

    if (clientHeight < sheetHeigth_) {
        vmaxVrtScroll = sheetHeigth_ - 1;
        vposVrtScroll_ = min(vposVrtScroll_, htSheet_ - htClient_ - 1);
    }

    infoScoll.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    infoScoll.nMin = 0;
    infoScoll.nMax = vmaxVrtScroll;
    infoScoll.nPage = clientHeight;
    infoScoll.nPos = vposVrtScroll_;
    SetScrollInfo(SB_VERT, &infoScoll, TRUE);
}

// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setwindoworg
// https://docs.microsoft.com/cpp/mfc/reference/cpen-class
void CAccelMainWnd::OnPaint()
{
    CPaintDC dc(this);

    dc.SetWindowOrg(hposHrzScroll_, vposVrtScroll_);

    // 画网格线
    CPen pen(PS_SOLID, 0, RGB(192, 192, 192));
    CPen *penptrOld = dc.SelectObject(&pen);

    for (int hrzline = 0; hrzline < 99; ++hrzline) {
        int y = cellHeight_ + hrzline * cellHeight_;
        dc.MoveTo(0, y);
        dc.LineTo(sheetWidth_, y);
    }

    for (int vrtline = 0; vrtline < 26; ++vrtline) {
        int x = ribbonWidth_ + vrtline * cellWidth_;
        dc.MoveTo(x, 0);
        dc.LineTo(x, sheetHeigth_);
    }

    dc.SelectObject(penptrOld);

    // 画头行、头列
    CBrush brush;
    brush.CreateStockObject(LTGRAY_BRUSH);

    CRect rectTop(0, 0, sheetWidth_, cellHeight_);
    dc.FillRect(rectTop, &brush);
    CRect rectLeft(0, 0, ribbonWidth_, sheetHeigth_);
    dc.FillRect(rectLeft, &brush);

    // 
    dc.MoveTo(0, cellHeight_);
    dc.LineTo(sheetWidth_, cellHeight_);
    dc.MoveTo(ribbonWidth_, 0);
    dc.LineTo(ribbonWidth_, sheetHeigth_);

    /* 画列头、行头 */
    dc.SetBkMode(TRANSPARENT);
    for (int i = 0; i < 99; ++i) {
        int y = i * m_nCellHeight + m_nCellHeight;
        dc.MoveTo(0, y);
        dc.LineTo(m_nRibbonWidth, y);

        CString string;
        string.Format(_T("%d"), 1 + i);

        CRect rect(0, y, m_nRibbonWidth, y + m_nCellHeight);
        dc.DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

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
        dc.DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

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
