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

CONST INT CVisualKeyboardMainWnd::kMaxMsgs;

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

VOID CVisualKeyboardMainWnd::OnPaint()
{
    CPaintDC devctx(this);

    devctx.DrawEdge(kTxtPadBox, EDGE_SUNKEN, BF_RECT);
    devctx.DrawEdge(kMsgPadBox, EDGE_SUNKEN, BF_RECT);

    DrawInputText(&devctx);
    DrawMessageHeader(&devctx);
    DrawMessages(&devctx);
}

VOID CVisualKeyboardMainWnd::OnSetFocus(CWnd *pWnd)
{
    CreateSolidCaret(max(2, GetSystemMetrics(SM_CXBORDER)), kCharHt);
    SetCaretPos(caret_pos_);
    ShowCaret();
}

VOID CVisualKeyboardMainWnd::OnKillFocus(CWnd *pWnd)
{
    HideCaret();
    caret_pos_ = GetCaretPos();
    DestroyCaret();
}

BOOL CVisualKeyboardMainWnd::OnSetCursor(CWnd *pWnd, UINT nHitTest, UINT message)
{
    if (nHitTest == HTCLIENT) {
        DWORD pos = GetMessagePos();
        CPoint point(LOWORD(pos), HIWORD(pos));
        ScreenToClient(&point);
        SetCursor(kTxtEltBox.PtInRect(point) ? kIbeamCursor : kArrowCursor);
        return TRUE;
    }
    return CWnd::OnSetCursor(pWnd, nHitTest, message);
}

VOID CVisualKeyboardMainWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
    if (kTxtEltBox.PtInRect(point)) {
        txt_idx_ = getTxtIdx(point);
        PositionCaret();
    }
}

VOID CVisualKeyboardMainWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(TEXT("WM_KEYDOWN"), nChar, nRepCnt, nFlags);

    switch (nChar) {

    case VK_LEFT:
        if (m_nTextPos != 0) {
            m_nTextPos--;
            PositionCaret();
        }
        break;

    case VK_RIGHT:
        if (m_nTextPos != m_strInputText.GetLength()) {
            m_nTextPos++;
            PositionCaret();
        }
        break;

    case VK_HOME:
        m_nTextPos = 0;
        PositionCaret();
        break;

    case VK_END:
        m_nTextPos = m_strInputText.GetLength();
        PositionCaret();
        break;
    }
}

VOID CVisualKeyboardMainWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_CHAR"), nChar, nRepCnt, nFlags);

    CClientDC dc(this);

    //
    // Determine which character was just input from the keyboard.
    //
    switch (nChar) {

    case VK_ESCAPE:
    case VK_RETURN:
        m_strInputText.Empty();
        m_nTextPos = 0;
        break;

    case VK_BACK:
        if (m_nTextPos != 0) {
            m_strInputText = m_strInputText.Left(m_nTextPos - 1) +
                m_strInputText.Right(m_strInputText.GetLength() -
                                     m_nTextPos);
            m_nTextPos--;
        }
        break;

    default:
        if ((nChar >= 0) && (nChar <= 31))
            return;

        if (m_nTextPos == m_strInputText.GetLength()) {
            m_strInputText += nChar;
            m_nTextPos++;
        } else
            m_strInputText.SetAt(m_nTextPos++, nChar);

        CSize size = dc.GetTextExtent(m_strInputText,
                                      m_strInputText.GetLength());

        if ((m_ptTextOrigin.x + size.cx) > m_nTextLimit) {
            m_strInputText = nChar;
            m_nTextPos = 1;
        }
        break;
    }

    //
    // Update the contents of the text box.
    //
    HideCaret();
    DrawInputText(&dc);
    PositionCaret(&dc);
    ShowCaret();
}

VOID CVisualKeyboardMainWnd::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_KEYUP"), nChar, nRepCnt, nFlags);
    CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}

VOID CVisualKeyboardMainWnd::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_SYSKEYDOWN"), nChar, nRepCnt, nFlags);
    CWnd::OnSysKeyDown(nChar, nRepCnt, nFlags);
}

VOID CVisualKeyboardMainWnd::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_SYSCHAR"), nChar, nRepCnt, nFlags);
    CWnd::OnSysChar(nChar, nRepCnt, nFlags);
}

VOID CVisualKeyboardMainWnd::OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_SYSKEYUP"), nChar, nRepCnt, nFlags);
    CWnd::OnSysKeyUp(nChar, nRepCnt, nFlags);
}

VOID CVisualKeyboardMainWnd::PositionCaret(CDC* pDC)
{
    BOOL bRelease = FALSE;

    //
    // Create a device context if pDC is NULL.
    //
    if (pDC == NULL) {
        pDC = GetDC();
        bRelease = TRUE;
    }

    //
    // Position the caret just right of the character whose 0-based
    // index is stored in m_nTextPos.
    //
    CPoint point = m_ptTextOrigin;
    CString string = m_strInputText.Left(m_nTextPos);
    point.x += (pDC->GetTextExtent(string, string.GetLength())).cx;
    SetCaretPos(point);

    //
    // Release the device context if it was created inside this function.
    //
    if (bRelease)
        ReleaseDC(pDC);
}

INT CVisualKeyboardMainWnd::getTxtIdx(CPoint point)
{
    if (point.x <= kTxtPos.x)
        return 0;

    CClientDC devctx(this);
    int len = txt_.GetLength();
    if (kTxtPos.x + devctx.GetTextExtent(txt_, len).cx <= point.x)
        return len;

    for (INT idx = 0; idx < len; idx++)
        if (point.x <= kTxtPos.x + devctx.GetTextExtent(txt_, idx).cx)
            return idx;

    return -1;
}

VOID CVisualKeyboardMainWnd::DrawInputText(CDC* pDC)
{
    pDC->ExtTextOut(m_ptTextOrigin.x, m_ptTextOrigin.y,
                    ETO_OPAQUE, m_rcTextBox, m_strInputText, NULL);
}

VOID CVisualKeyboardMainWnd::ShowMessage(LPCTSTR pszMessage, UINT nChar,
                                         UINT nRepCnt, UINT nFlags)
{
    //
    // Formulate a message string.
    //
    CString string;
    string.Format(_T("%s\t %u\t  %u\t  %u\t  %u\t  %u\t  %u\t   %u"),
                  pszMessage, nChar, nRepCnt, nFlags & 0xFF,
                  (nFlags >> 8) & 0x01,
                  (nFlags >> 13) & 0x01,
                  (nFlags >> 14) & 0x01,
                  (nFlags >> 15) & 0x01);

    //
    // Scroll the other message strings up and validate the scroll
    // rectangle to prevent OnPaint from being called.
    //
    ScrollWindow(0, -m_cyLine, &m_rcScroll);
    ValidateRect(m_rcScroll);

    //
    // Record the new message string and display it in the window.
    //
    CClientDC dc(this);
    dc.SetBkColor((COLORREF) ::GetSysColor(COLOR_3DFACE));

    m_strMessages[m_nMsgPos] = string;
    dc.TabbedTextOut(m_ptLowerMsgOrigin.x, m_ptLowerMsgOrigin.y,
                     m_strMessages[m_nMsgPos], m_strMessages[m_nMsgPos].GetLength(),
                     sizeof(m_nTabStops), m_nTabStops, m_ptLowerMsgOrigin.x);

    //
    // Update the array index that specifies where the next message
    // string will be stored.
    //
    if (++m_nMsgPos == MAX_STRINGS)
        m_nMsgPos = 0;
}

VOID CVisualKeyboardMainWnd::DrawMessageHeader(CDC* pDC)
{
    static CString string =
        _T("Message\tChar\tRep\tScan\tExt\tCon\tPrv\tTran");

    pDC->SetBkColor((COLORREF) ::GetSysColor(COLOR_3DFACE));
    pDC->TabbedTextOut(m_ptHeaderOrigin.x, m_ptHeaderOrigin.y,
                       string, string.GetLength(), sizeof(m_nTabStops), m_nTabStops,
                       m_ptHeaderOrigin.x);
}

VOID CVisualKeyboardMainWnd::DrawMessages(CDC* pDC)
{
    int nPos = m_nMsgPos;
    pDC->SetBkColor((COLORREF) ::GetSysColor(COLOR_3DFACE));

    for (int i = 0; i < MAX_STRINGS; i++) {
        pDC->TabbedTextOut(m_ptUpperMsgOrigin.x,
                           m_ptUpperMsgOrigin.y + (m_cyLine * i),
                           m_strMessages[nPos], m_strMessages[nPos].GetLength(),
                           sizeof(m_nTabStops), m_nTabStops, m_ptUpperMsgOrigin.x);

        if (++nPos == MAX_STRINGS)
            nPos = 0;
    }
}
