/// \copyright The MIT License

#include "stdafx.h"
#include "VisualKeyboardMainWnd.h"

namespace {

CONST INT kMarginLeft {16};
CONST INT kMarginTop {16};
CONST INT kMarginRight {16};
CONST INT kMarginBottom {16};

CONST INT kMaxMessages {12};

}// namespace

BEGIN_MESSAGE_MAP(CVisualKeyboardMainWnd, CWnd)
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_WM_SETFOCUS()
    ON_WM_KILLFOCUS()
    ON_WM_SETCURSOR()
    ON_WM_LBUTTONDOWN()
    ON_WM_KEYDOWN()
    ON_WM_CHAR()
    ON_WM_KEYUP()
    ON_WM_SYSKEYDOWN()
    ON_WM_SYSCHAR()
    ON_WM_SYSKEYUP()
END_MESSAGE_MAP()

CVisualKeyboardMainWnd::CVisualKeyboardMainWnd()
{
    arrow_cursor_ = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
    ibeam_cursor_ = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);

    CString wndclname = AfxRegisterWndClass(
        0,
        NULL,
        (HBRUSH)(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    CreateEx(0, wndclname, TEXT("The Visual Keyboard Application"),
             WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
             CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
             NULL, NULL);
}

VOID CVisualKeyboardMainWnd::PostNcDestroy()
{
    delete this;
}

INT CVisualKeyboardMainWnd::OnCreate(LPCREATESTRUCT creating_info)
{
    if (CWnd::OnCreate(creating_info) == -1)
        return -1;

    CClientDC devctx(this);

    TEXTMETRIC text_metric;
    devctx.GetTextMetrics(&text_metric);
    char_width_ = text_metric.tmAveCharWidth;
    char_height_ = text_metric.tmHeight;
    line_height_ = text_metric.tmHeight + text_metric.tmExternalLeading;

    text_box_border_.SetRect(
        kMarginLeft,
        kMarginTop,
        kMarginLeft
        + 64 * char_width_,
        kMarginTop
        + 1.5 * char_height_);

    text_box_ = text_box_border_;
    text_box_.InflateRect(-2, -2);

    message_box_border_.SetRect(
        kMarginLeft,
        kMarginTop + 4 * char_height_,
        kMarginLeft
        + 64 * char_width_,
        kMarginLeft + 4 * char_height_
        + 2 * char_height_ + kMaxMessages * line_height_);

    CRect rect(0,
               0,
               message_box_border_.right + kMarginRight,
               message_box_border_.bottom + kMarginBottom);
    CalcWindowRect(&rect);
    SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(),
                 SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
    return 0;
}
