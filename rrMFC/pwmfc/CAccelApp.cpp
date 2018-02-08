/// \copyright The MIT License

#include "CAccelApp.h"

namespace {
const int kLineSize = 8;
}// namespace

CAccelApp g_app;

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
INT CAccelMainWnd::OnCreate(LPCREATESTRUCT creating_info)
{
    // 此函数应当总是调用其基类函数
    if (-1 == CFrameWnd::OnCreate(creating_info))
        return -1;

    CClientDC dc(this);

    //      Ribbon Cell x 26
    // Cell
    //   x               .25 in
    //  100 .5 in  1 in

    CONST INT kInchWidth = dc.GetDeviceCaps(LOGPIXELSX);
    CONST INT kInchHeight = dc.GetDeviceCaps(LOGPIXELSY);

    ribbon_width_ = kInchWidth / 2;
    cell_width_ = kInchWidth;
    cell_height_ = kInchHeight / 4;
    sheet_width_ = ribbon_width_ + 26 * cell_width_;
    sheet_heigth_ = 100 * cell_height_;

    return 0;
}

// https://msdn.microsoft.com/library/bb787537.aspx
// https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#setscrollinfo
VOID CAccelMainWnd::OnSize(UINT size_type, INT client_width, INT client_height)
{
    CFrameWnd::OnSize(size_type, client_width, client_height);

    client_width_ = client_width;
    client_height_ = client_height;

    SCROLLINFO scoll_info;

    // 水平滚动条
    INT hrz_scroll_max = 0;
    hrz_scroll_pos_ = 0;

    // 若表格尺寸大于用户区尺寸（太宽，一页放不下）
    if (client_width_ < sheet_width_) {
        hrz_scroll_max = sheet_width_ - 1;
        hrz_scroll_pos_ = min(hrz_scroll_pos_,
                              sheet_width_ - client_width_ - 1);  // 防抖动
    }

    scoll_info.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    scoll_info.nMin = 0;                // 范围下限
    scoll_info.nMax = hrz_scroll_max;   // 范围上限
    scoll_info.nPage = client_width_;   // 页面尺寸
    scoll_info.nPos = hrz_scroll_pos_;  // 位置
    // 设置滚动条
    SetScrollInfo(SB_HORZ,      // 水平滚动条
                  &scoll_info,  // 滚动条信息
                  TRUE);        // 需要重绘滚动条

    // 垂直滚动条，同水平滚动条
    INT vrt_scroll_max = 0;
    vrt_scroll_pos_ = 0;

    if (client_height_ < sheet_heigth_) {
        vrt_scroll_max = sheet_heigth_ - 1;
        vrt_scroll_pos_ = min(vrt_scroll_pos_,
                              sheet_heigth_ - client_height_ - 1);
    }

    scoll_info.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    scoll_info.nMin = 0;
    scoll_info.nMax = vrt_scroll_max;
    scoll_info.nPage = client_height_;
    scoll_info.nPos = vrt_scroll_pos_;
    SetScrollInfo(SB_VERT, &scoll_info, TRUE);
}

// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setwindoworg
// https://docs.microsoft.com/cpp/mfc/reference/cpen-class
void CAccelMainWnd::OnPaint()
{
    CPaintDC dc(this);

    dc.SetWindowOrg(hrz_scroll_pos_, vrt_scroll_pos_);

    // 画网格线
    CPen pen(PS_SOLID, 0, RGB(192, 192, 192));
    CPen *old_pen = dc.SelectObject(&pen);

    for (int hrzline = 0; hrzline < 99; ++hrzline) {
        int y = cell_height_ + hrzline * cell_height_;
        dc.MoveTo(0, y);
        dc.LineTo(sheet_width_, y);
    }

    for (int vrtline = 0; vrtline < 26; ++vrtline) {
        int x = ribbon_width_ + vrtline * cell_width_;
        dc.MoveTo(x, 0);
        dc.LineTo(x, sheet_heigth_);
    }

    dc.SelectObject(old_pen);

    // 画头行、头列
    CBrush brush;
    brush.CreateStockObject(LTGRAY_BRUSH);

    CRect rectTop(0, 0, sheet_width_, cell_height_);
    dc.FillRect(rectTop, &brush);
    CRect rectLeft(0, 0, ribbon_width_, sheet_heigth_);
    dc.FillRect(rectLeft, &brush);

    dc.MoveTo(0, cell_height_);
    dc.LineTo(sheet_width_, cell_height_);
    dc.MoveTo(ribbon_width_, 0);
    dc.LineTo(ribbon_width_, sheet_heigth_);

    // 画列头、行头
    dc.SetBkMode(TRANSPARENT);
    for (int i = 0; i < 99; ++i) {
        int y = i * cell_height_ + cell_height_;
        dc.MoveTo(0, y);
        dc.LineTo(ribbon_width_, y);

        CString text;
        text.Format(TEXT("%i"), 1 + i);

        CRect rect(0, y, ribbon_width_, y + cell_height_);
        dc.DrawText(text, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        rect.top++;
        dc.Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128));
    }

    for (int j = 0; j < 26; ++j) {
        int x = j * cell_width_ + ribbon_width_;
        dc.MoveTo(x, 0);
        dc.LineTo(x, cell_height_);

        CString text;
        text.Format(TEXT("%c"), 'A' + j);
        CRect rect(x, 0, x + cell_width_, cell_height_);
        dc.DrawText(text, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        rect.left++;
        dc.Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128));
    }
}

VOID CAccelMainWnd::OnHScroll(
    UINT scroll_code, UINT scroll_pos, CScrollBar *scroll_bar)
{
    INT delta;

    switch (scroll_code) {
    case SB_LINELEFT: delta = -kLineSize; break;
    case SB_PAGELEFT: delta = -client_width_; break;
    case SB_THUMBTRACK: delta = (INT)scroll_pos - hrz_scroll_pos_; break;
    case SB_PAGERIGHT: delta = client_width_; break;
    case SB_LINERIGHT: delta = kLineSize; break;
    default: return;
    }

    CONST INT kMaxPos = sheet_width_ - client_width_;
    INT pos = hrz_scroll_pos_ + delta;

    if (pos < 0)
        delta = -hrz_scroll_pos_;
    else if (pos > kMaxPos)
        delta = kMaxPos - hrz_scroll_pos_;

    if (0 != delta) {
        hrz_scroll_pos_ += delta;
        SetScrollPos(SB_HORZ, hrz_scroll_pos_, TRUE);
        ScrollWindow(-delta, 0);
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
