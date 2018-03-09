/// \copyright The MIT License

#include "stdafx.h"
#include "AccelMainWnd.h"

BEGIN_MESSAGE_MAP(CAccelMainWnd, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_PAINT()
    ON_WM_HSCROLL()
    ON_WM_VSCROLL()
END_MESSAGE_MAP()

CAccelMainWnd::CAccelMainWnd()
{
    Create(NULL, TEXT("The Accel Application"));
}

INT CAccelMainWnd::OnCreate(LPCREATESTRUCT creating_info)
{
    if (CFrameWnd::OnCreate(creating_info) == -1)
        return -1;

    CClientDC devctx(this);
    CONST INT kHrzInch = devctx.GetDeviceCaps(LOGPIXELSX);
    CONST INT kVrtInch = devctx.GetDeviceCaps(LOGPIXELSY);

    ribbon_width_ = kHrzInch / 2;
    cell_width_ = kHrzInch;
    cell_height_ = kVrtInch / 4;
    sheet_width_ = ribbon_width_ + 26 * cell_width_;
    sheet_height_ = 100 * cell_height_;

    return 0;
}

VOID CAccelMainWnd::OnSize(UINT resizing_type, INT client_width, INT client_height)
{
    CFrameWnd::OnSize(resizing_type, client_width, client_height);

    client_width_ = client_width;
    client_height_ = client_height;

    SCROLLINFO scroll;

    INT hrz_scroll_max;
    if (client_width_ < sheet_width_) {
        hrz_scroll_max = sheet_width_;
        hrz_scroll_pos_ = min(hrz_scroll_pos_, sheet_width_ - client_width_);
    } else {
        hrz_scroll_max = 0;
        hrz_scroll_pos_ = 0;
    }
    scroll.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    scroll.nMin = 0;
    scroll.nMax = hrz_scroll_max;
    scroll.nPage = client_width_;
    scroll.nPos = hrz_scroll_pos_;
    SetScrollInfo(SB_HORZ, &scroll, TRUE);

    INT vrt_scroll_max;
    if (client_height_ < sheet_height_) {
        vrt_scroll_max = sheet_height_;
        vrt_scroll_pos_ = min(vrt_scroll_pos_, sheet_height_ - client_height_);
    } else {
        vrt_scroll_max = 0;
        vrt_scroll_pos_ = 0;
    }
    scroll.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
    scroll.nMin = 0;
    scroll.nMax = vrt_scroll_max;
    scroll.nPage = client_width_;
    scroll.nPos = vrt_scroll_pos_;
    SetScrollInfo(SB_VERT, &scroll, TRUE);
}

VOID CAccelMainWnd::OnPaint()
{
    CPaintDC devctx(this);

    devctx.SetWindowOrg(hrz_scroll_pos_, vrt_scroll_pos_);

    // 绘制网格线
    CPen pen(PS_SOLID, 0, RGB(192, 192, 192)/*Grey*/);
    CPen *oldpen = devctx.SelectObject(&pen);

    for (INT hrzline = 0; hrzline < 99; hrzline++) {
        CONST INT kY = cell_height_ + hrzline * cell_height_;
        devctx.MoveTo(0, kY);
        devctx.LineTo(sheet_width_, kY);
    }

    for (INT vrtline = 0; vrtline < 26; vrtline++) {
        CONST INT kX = ribbon_width_ + vrtline * cell_width_;
        devctx.MoveTo(kX, 0);
        devctx.LineTo(kX, sheet_height_);
    }

    devctx.SelectObject(oldpen);

    // 绘制行头和列头
    CBrush brush;
    brush.CreateStockObject(LTGRAY_BRUSH);

    CRect top_rect(0, 0, sheet_width_, cell_height_);
    devctx.FillRect(top_rect, &brush);
    CRect left_rect(0, 0, ribbon_width_, sheet_height_);
    devctx.FillRect(left_rect, &brush);

    devctx.MoveTo(0, cell_height_);
    devctx.LineTo(sheet_width_, cell_height_);
    devctx.MoveTo(ribbon_width_, 0);
    devctx.LineTo(ribbon_width_, sheet_height_);

    // 绘制数字和字母
    devctx.SetBkMode(TRANSPARENT);

    for (INT row_header = 1; row_header < 100; row_header++) {
        CONST INT kTop = row_header * cell_height_;
        devctx.MoveTo(0, kTop);
        devctx.LineTo(ribbon_width_, kTop);

        CString number;
        number.Format(TEXT("%i"), row_header);

        CRect rect(0, kTop, ribbon_width_, kTop + cell_height_);
        devctx.DrawText(number, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        rect.top++;
        devctx.Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128)/*Gray*/);
    }

    for (INT column_header = 1; column_header < 27; column_header++) {
        int kLeft = ribbon_width_ + (column_header - 1) * cell_width_;
        devctx.MoveTo(kLeft, 0);
        devctx.LineTo(kLeft, cell_height_);

        CString letter;
        letter.Format(TEXT("%c"), 'A' + (column_header - 1));

        CRect rect(kLeft, 0, kLeft + cell_width_, cell_height_);
        devctx.DrawText(letter, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        rect.left++;
        devctx.Draw3dRect(rect, RGB(255, 255, 255), RGB(128, 128, 128)/*Gray*/);
    }
}

void CAccelMainWnd::OnHScroll(UINT scrol_code, UINT scroll_pos, CScrollBar *scroll_bar)
{
    CONST INT kLineSize = 8;
    int delta;

    switch (scrol_code) {
    case SB_LINELEFT: delta = -kLineSize; break;
    case SB_PAGELEFT: delta = -client_width_; break;
    case SB_THUMBTRACK: delta = (INT)scroll_pos - hrz_scroll_pos_; break;
    case SB_PAGERIGHT: delta = client_width_; break;
    case SB_LINERIGHT: delta = kLineSize; break;
    default: return;
    }

    // 检查改变量是否超出限制，并相应给予调整
    CONST INT hrz_scroll_check = hrz_scroll_pos_ + delta;
    CONST INT hrz_scroll_max = sheet_width_ - client_width_;

    if (hrz_scroll_check < 0)
        delta = 0 - hrz_scroll_pos_;
    else if (hrz_scroll_max < hrz_scroll_check)
        delta = hrz_scroll_max - hrz_scroll_pos_;

    if (delta != 0) {
        hrz_scroll_pos_ += delta;
        SetScrollPos(SB_HORZ, hrz_scroll_pos_, TRUE);
        ScrollWindow(-delta, 0);
    }
}

void CAccelMainWnd::OnVScroll(UINT scrol_code, UINT scroll_pos, CScrollBar *scroll_bar)
{
    CONST INT kLineSize = 8;
    int delta;

    switch (scrol_code) {
    case SB_LINEUP: delta = -kLineSize; break;
    case SB_PAGEUP: delta = -client_height_; break;
    case SB_THUMBTRACK: delta = (INT)scroll_pos - vrt_scroll_pos_; break;
    case SB_PAGEDOWN: delta = client_height_; break;
    case SB_LINEDOWN: delta = kLineSize; break;
    default: return;
    }

    // 检查改变量是否超出限制，并相应给予调整
    CONST INT vrt_scroll_check = vrt_scroll_pos_ + delta;
    CONST INT vrt_scroll_max = sheet_height_ - client_height_;

    if (vrt_scroll_check < 0)
        delta = 0 - vrt_scroll_pos_;
    else if (vrt_scroll_max < vrt_scroll_check)
        delta = vrt_scroll_max - vrt_scroll_pos_;

    if (delta != 0) {
        vrt_scroll_pos_ += delta;
        SetScrollPos(SB_VERT, vrt_scroll_pos_, TRUE);
        ScrollWindow(0, -delta);
    }
}
