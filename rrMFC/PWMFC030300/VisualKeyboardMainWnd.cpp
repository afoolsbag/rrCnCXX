/// \copyright The MIT License

#include "stdafx.h"
#include "VisualKeyboardMainWnd.h"

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
    kArrowCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
    kIbeamCursor = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);

    CString wndclname = AfxRegisterWndClass(
        0,
        NULL,
        (HBRUSH)(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    CreateEx(0, wndclname, TEXT("The VisualKeyboard Application"),
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
    kCharWd = text_metric.tmAveCharWidth;
    kCharHt = text_metric.tmHeight;
    kLineHt = text_metric.tmHeight + text_metric.tmExternalLeading;

    CONST INT kTxtPadBoxL = kWndBoxPadL;
    CONST INT kTxtPadBoxT = kWndBoxPadT;
    kTxtPadBox.SetRect(
        kTxtPadBoxL,
        kTxtPadBoxT,
        kTxtPadBoxL + 64 * kCharWd,
        kTxtPadBoxT + 1.5 * kCharHt);

    kTxtEltBox = kTxtPadBox;
    kTxtEltBox.InflateRect(-2, -2);

    CONST INT kMsgPadBoxL = kWndBoxPadL;
    CONST INT kMsgPadBoxT = kWndBoxPadT + 4 * kCharHt;
    kMsgPadBox.SetRect(
        kMsgPadBoxL,
        kMsgPadBoxT,
        kMsgPadBoxL + 64 * kCharWd,
        kMsgPadBoxT + 2 * kCharHt + kMaxMsgs * kLineHt);

    kWndPadBox.SetRect(
        0, 0,
        kMsgPadBox.right + kWndBoxPadR, kMsgPadBox.bottom + kWndBoxPadB);

    CRect wndrect = kWndPadBox;
    CalcWindowRect(&wndrect);
    SetWindowPos(NULL, 0, 0, wndrect.Width(), wndrect.Height(),
                 SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
    return 0;
}
