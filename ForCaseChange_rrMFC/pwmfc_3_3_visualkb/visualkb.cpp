/** \copyright The MIT License */

#include "visualkb.hpp"

CMyApp myApp;

/// Class MY APPlication :: INITialize INSTANCE.
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

/// Class MAIN WINDOW :: Constructor.
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
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    CreateEx(
        0,
        strWndClass,
        _T("Visual Keyboard"),
        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,  // 禁止缩放、最大化
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL
    );
}

/// Class MAIN WINDOW :: ON CREATE.
int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (-1 == CWnd::OnCreate(lpCreateStruct))
        return -1;

    CClientDC dc(this);

    // 获取字符尺寸数据
    TEXTMETRIC tm;
    dc.GetTextMetrics(&tm);
    m_cxChar = tm.tmAveCharWidth;
    m_cyChar = tm.tmHeight;
    m_cyLine = tm.tmHeight + tm.tmExternalLeading;

    m_rcTextBoxBorder.SetRect(16, 16,
                              64*m_cxChar + 16, 3*m_cyChar/2 + 16);

    m_rcTextBox = m_rcTextBoxBorder;
    m_rcTextBox.InflateRect(-2, -2);

    m_rcMsgBoxBorder.SetRect(16, 4*m_cyChar + 16,
                             64*m_cxChar + 16, MAX_STRINGS*m_cyLine + 6*m_cyChar + 16);

    m_rcScroll.SetRect(m_cxChar + 16, 6 * m_cyChar + 16,
                       63*m_cxChar + 16, MAX_STRINGS*m_cyLine + 5*m_cyChar + 16);

    m_ptTextOrigin.x = m_cxChar + 16;
    m_ptTextOrigin.y = m_cyChar / 4 + 16;
    m_ptCaretPos = m_ptTextOrigin;
    m_nTextLimit = 63*m_cxChar + 16;

    m_ptHeaderOrigin.x = m_cxChar + 16;
    m_ptHeaderOrigin.y = 3*m_cyChar + 16;

    m_ptUpperMsgOrigin.x = m_cxChar + 16;
    m_ptUpperMsgOrigin.y = 5*m_cyChar + 16;

    m_ptLowerMsgOrigin.x = m_cxChar + 16;
    m_ptLowerMsgOrigin.y = 5*m_cyChar + (MAX_STRINGS-1)*m_cyLine + 16;

    m_nTabStops[0] = 24*m_cxChar + 16;
    m_nTabStops[1] = 30*m_cxChar + 16;
    m_nTabStops[2] = 36*m_cxChar + 16;
    m_nTabStops[3] = 42*m_cxChar + 16;
    m_nTabStops[4] = 46*m_cxChar + 16;
    m_nTabStops[5] = 50*m_cxChar + 16;
    m_nTabStops[6] = 54*m_cxChar + 16;

    CRect rect(0, 0,
               m_rcMsgBoxBorder.right + 16, m_rcMsgBoxBorder.bottom + 16);
    CalcWindowRect(&rect);
    SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(),
                 SWP_NOZORDER|SWP_NOMOVE|SWP_NOREDRAW);
    return 0;
}

/// Class MAIN WINDOW :: POST NonClient DESTROY.
void CMainWindow::PostNcDestroy()
{
    delete this;
}

/// Class MAIN WINDOW :: ON PAINT
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);

    // 文本框与消息框的边框
    dc.DrawEdge(m_rcTextBoxBorder, EDGE_SUNKEN, BF_RECT);
    dc.DrawEdge(m_rcMsgBoxBorder, EDGE_SUNKEN, BF_RECT);

    DrawInputText(&dc);
    DrawMessageHeader(&dc);
    DrawMessages(&dc);
}

/// Class MAIN WINDOW :: ON SET FOCUS
void CMainWindow::OnSetFocus(CWnd *pWnd)
{
    CreateSolidCaret(                             // 创建插入符：
        max(2, ::GetSystemMetrics(SM_CXBORDER)),  // 宽度；
        m_cyChar                                  // 高度。
    );
    SetCaretPos(m_ptCaretPos);                    // 配置插入符位置；
    ShowCaret();                                  // 显示插入符。
}

/// Class MAIN WINDOW :: ON KILL FOCUS
void CMainWindow::OnKillFocus(CWnd *pWnd)
{
    HideCaret();                   // 隐藏插入符；
    m_ptCaretPos = GetCaretPos();  // 保存插入符位置；
    ::DestroyCaret();              // 销毁插入符。
}

/// Class MAIN WINDOW :: ON SET CURSOR
BOOL CMainWindow::OnSetCursor(CWnd *pWnd, UINT nHitTest, UINT message)
{
    // 当鼠标在编辑区上时，鼠标改为 "I" 样式
    if (nHitTest == HTCLIENT) {
        DWORD dwPos = ::GetMessagePos();
        CPoint point(LOWORD (dwPos), HIWORD (dwPos));
        ScreenToClient(&point);
        ::SetCursor(m_rcTextBox.PtInRect(point) ? m_hCursorIBeam : m_hCursorArrow);
        return TRUE;
    }
    return CWnd::OnSetCursor(pWnd, nHitTest, message);
}

/// Class MAIN WINDOW :: ON Left BUTTON DOWN
void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
    // 当点击编辑区时，将光标移动到附近
    if (m_rcTextBox.PtInRect(point)) {
        m_nTextPos = GetNearestPos(point);
        PositionCaret();
    }
}

/// Class MAIN WINDOW :: ON KEY DOWN
void CMainWindow::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_KEYDOWN"), nChar, nRepCnt, nFlags);

    switch (nChar) {
    case VK_LEFT:
        if (0 != m_nTextPos) {
            m_nTextPos--;
            PositionCaret();
        }
        break;

    case VK_RIGHT:
        if (m_strInputText.GetLength() != m_nTextPos) {
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

/// Class MAIN WINDOW :: ON CHAR
void CMainWindow::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_CHAR"), nChar, nRepCnt, nFlags);

    CClientDC dc(this);

    switch (nChar) {
        case VK_ESCAPE:
        case VK_RETURN:
            m_strInputText.Empty();
            m_nTextPos = 0;
            break;

        case VK_BACK:
            if (m_nTextPos != 0) {
                m_strInputText =
                      m_strInputText.Left(m_nTextPos - 1)
                    + m_strInputText.Right(m_strInputText.GetLength() - m_nTextPos);
                m_nTextPos--;
            }
            break;

        default:
            if (0 <= nChar && nChar <= 31)
                return;

            if (m_strInputText.GetLength() == m_nTextPos) {
                m_strInputText += (WCHAR)nChar;
                ++m_nTextPos;
            } else
                m_strInputText.SetAt(m_nTextPos++, nChar);

            CSize size = dc.GetTextExtent(m_strInputText,
                                          m_strInputText.GetLength());

            if ((m_ptTextOrigin.x + size.cx) > m_nTextLimit) {
                m_strInputText = (WCHAR)nChar;
                m_nTextPos = 1;
            }
            break;
    }

    HideCaret();
    DrawInputText(&dc);
    PositionCaret(&dc);
    ShowCaret();
}

/// Class MAIN WINDOW :: ON KEY UP
void CMainWindow::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_KEYUP"), nChar, nRepCnt, nFlags);
    CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}

/// Class MAIN WINDOW :: ON SYStem KEY DOWN
void CMainWindow::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_SYSKEYDOWN"), nChar, nRepCnt, nFlags);
    CWnd::OnSysKeyDown(nChar, nRepCnt, nFlags);
}

/// Class MAIN WINDOW :: ON SYStem CHAR
void CMainWindow::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_SYSCHAR"), nChar, nRepCnt, nFlags);
    CWnd::OnSysChar(nChar, nRepCnt, nFlags);
}

/// Class MAIN WINDOW :: ON SYStem KEY UP
void CMainWindow::OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    ShowMessage(_T("WM_SYSKEYUP"), nChar, nRepCnt, nFlags);
    CWnd::OnSysKeyUp(nChar, nRepCnt, nFlags);
}

/// Class MAIN WINDOW :: POSITION CARET
void CMainWindow::PositionCaret(CDC *pDC)
{
    BOOL bRelease = FALSE;

    if (pDC == NULL) {
        pDC = GetDC();
        bRelease = TRUE;
    }

    CPoint point = m_ptTextOrigin;
    CString string = m_strInputText.Left(m_nTextPos);
    point.x += (pDC->GetTextExtent(string, string.GetLength())).cx;
    SetCaretPos(point);

    if (bRelease)
        ReleaseDC(pDC);
}

/// Class MAIN WINDOW :: GET NEAREST POS
int CMainWindow::GetNearestPos(CPoint point)
{
    if (point.x <= m_ptTextOrigin.x)
        return 0;

    CClientDC dc(this);
    int nLen = m_strInputText.GetLength();
    if (point.x >= (m_ptTextOrigin.x +
                    (dc.GetTextExtent(m_strInputText, nLen)).cx))
        return nLen;

    int i = 0;
    int nPrevChar = m_ptTextOrigin.x;
    int nNextChar = m_ptTextOrigin.x;

    while (nNextChar < point.x) {
        i++;
        nPrevChar = nNextChar;
        nNextChar = m_ptTextOrigin.x +
                    (dc.GetTextExtent(m_strInputText.Left(i), i)).cx;
    }
    return ((point.x - nPrevChar) < (nNextChar - point.x)) ? i - 1 : i;
}

/// Class MAIN WINDOW :: DRAW INPUT TEXT
void CMainWindow::DrawInputText(CDC *pDC)
{
    pDC->ExtTextOut(m_ptTextOrigin.x, m_ptTextOrigin.y,
                    ETO_OPAQUE, m_rcTextBox, m_strInputText, NULL);
}

/// Class MAIN WINDOW :: SHOW MESSAGE
void CMainWindow::ShowMessage(LPCTSTR pszMessage, UINT nChar,
                              UINT nRepCnt, UINT nFlags)
{
    CString string;
    string.Format(_T ("%s\t %u\t  %u\t  %u\t  %u\t  %u\t  %u\t   %u"),
                  pszMessage, nChar, nRepCnt, nFlags & 0xFF,
                  (nFlags >> 8) & 0x01,
                  (nFlags >> 13) & 0x01,
                  (nFlags >> 14) & 0x01,
                  (nFlags >> 15) & 0x01);

    ScrollWindow(0, -m_cyLine, &m_rcScroll);
    ValidateRect(m_rcScroll);

    CClientDC dc(this);
    dc.SetBkColor((COLORREF) ::GetSysColor(COLOR_3DFACE));

    m_strMessages[m_nMsgPos] = string;
    dc.TabbedTextOut(m_ptLowerMsgOrigin.x, m_ptLowerMsgOrigin.y,
                     m_strMessages[m_nMsgPos],
                     m_strMessages[m_nMsgPos].GetLength(),
                     sizeof(m_nTabStops), m_nTabStops, m_ptLowerMsgOrigin.x);

    if (++m_nMsgPos == MAX_STRINGS)
        m_nMsgPos = 0;
}

/// Class MAIN WINDOW :: DRAW MESSAGE HEADER
void CMainWindow::DrawMessageHeader(CDC *pDC)
{
    static CString string =
        _T ("Message\tChar\tRep\tScan\tExt\tCon\tPrv\tTran");

    pDC->SetBkColor((COLORREF) ::GetSysColor(COLOR_3DFACE));
    pDC->TabbedTextOut(m_ptHeaderOrigin.x, m_ptHeaderOrigin.y,
                       string, string.GetLength(), sizeof(m_nTabStops),
                       m_nTabStops,
                       m_ptHeaderOrigin.x);
}

/// Class MAIN WINDOW :: DRAW MESSAGES
void CMainWindow::DrawMessages(CDC *pDC)
{
    int nPos = m_nMsgPos;
    pDC->SetBkColor((COLORREF) ::GetSysColor(COLOR_3DFACE));

    for (int i = 0; i < MAX_STRINGS; i++) {
        pDC->TabbedTextOut(m_ptUpperMsgOrigin.x,
                           m_ptUpperMsgOrigin.y + (m_cyLine * i),
                           m_strMessages[nPos], m_strMessages[nPos].GetLength(),
                           sizeof(m_nTabStops), m_nTabStops,
                           m_ptUpperMsgOrigin.x);

        if (++nPos == MAX_STRINGS)
            nPos = 0;
    }
}
