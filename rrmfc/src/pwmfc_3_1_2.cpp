/** \file
 *  \brief *Programming Windows with MFC* 3.1.2.
 *  \author zhengrr
 *  \date 2017-12-9
 *  \copyright The MIT License
 */
#ifdef ZRR_PWMFC_3_1_2

#include <afxwin.h>

#define EX 1
#define OH 2

/// CMyApp
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// CMainWindow
class CMainWindow : public CWnd {
public:
    CMainWindow();

protected:
    virtual void PostNcDestroy();

    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

    static const CRect m_rcSquares[9];
    int m_nGameGrid[9];
    int m_nNextChar;
    int GetRextID(CPoint point);
    void DrawBoard(CDC *pDC);
    void DrawX(CDC *pDC, int nPos);
    void DrawO(CDC *pDC, int nPos);
    void CheckForGameOver();
    int IsWinner();
    BOOL IsDraw();
    void ResetGame();

    DECLARE_MESSAGE_MAP()
};

CMyApp myApp;

/// CMyApp::InitInstance
BOOL CMyApp::InitInstance()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CWnd)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

/// CMainWindow::CMainWindow
CMainWindow::CMainWindow()
{
    m_nNextChar = EX;
    ::ZeroMemory(m_nGameGrid, 9 * sizeof m_nGameGrid[0]);

    CString strWndClass = AfxRegisterWndClass(
        CS_DBLCLKS,
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
        (HBRUSH)(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO));

    CreateEx(
        0, strWndClass, _T("Tic-Tac-Toe"),
        WS_OVERLAPPED|WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL);

    CRect rect(0, 0, 352, 352);
    CalcWindowRect(&rect);
    SetWindowPos(NULL, 0, 0, rect.Width(), rect.Height(), SWP_NOZORDER|SWP_NOMOVE|SWP_NOREDRAW);
}

/// CMainWindow::PostNcDestroy
void CMainWindow::PostNcDestroy()
{
    delete this;
}

/// CMainWindow::OnPaint
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);
    DrawBoard(&dc);
}

/// CMainWindow::OnLButtonDown
void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
    if (EX != m_nNextChar) return;
    int nPos = GetRextID(point);
    if (-1 == nPos || 0 != m_nGameGrid[nPos]) return;

    m_nGameGrid[nPos] = EX;
    m_nNextChar = OH;

    CClientDC dc(this);
    DrawX(&dc, nPos);
    CheckForGameOver();
}

/// CMainWindow::OnNcLButtonDblClk
void CMainWindow::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    CClientDC dc(this);
    if (RGB(0, 0, 0) == dc.GetPixel(point)) ResetGame();
}

/// CMainWindow::OnRButtonDown
void CMainWindow::OnRButtonDown(UINT nFlags, CPoint point)
{
    if (OH != m_nNextChar) return;
    int nPos = GetRextID(point);
    if (-1 == nPos || 0 != m_nGameGrid[nPos]) return;

    m_nGameGrid[nPos] = OH;
    m_nNextChar = EX;

    CClientDC dc(this);
    DrawO(&dc, nPos);
    CheckForGameOver();
}

/// CMainWindow::m_rcSquares
const CRect CMainWindow::m_rcSquares[9] = {
    CRect( 16,  16, 112, 112),
    CRect(128,  16, 224, 112),
    CRect(240,  16, 336, 112),
    CRect( 16, 128, 112, 224),
    CRect(128, 128, 224, 224),
    CRect(240, 128, 336, 224),
    CRect( 16, 240, 112, 336),
    CRect(128, 240, 224, 336),
    CRect(240, 240, 336, 336)
};

/// CMainWindow::GetRextID
int CMainWindow::GetRextID(CPoint point)
{
    for (int i = 0; i < 9; ++i) {
        if (m_rcSquares[i].PtInRect(point)) return i;
    }
    return -1;
}

/// CMainWindow::DrawBoard
void CMainWindow::DrawBoard(CDC *pDC)
{
    CPen pen(PS_SOLID, 16, RGB(0, 0, 0));
    CPen *pOldPen = pDC->SelectObject(&pen);

    pDC->MoveTo(120,  16);
    pDC->LineTo(120, 336);
    pDC->MoveTo(232,  16);
    pDC->LineTo(232, 336);
    pDC->MoveTo( 16, 120);
    pDC->LineTo(336, 120);
    pDC->MoveTo( 16, 232);
    pDC->LineTo(336, 232);

    for (int i = 0; i < 9; ++i) {
        if (EX == m_nGameGrid[i]) DrawX(pDC, i);
        if (OH == m_nGameGrid[i]) DrawO(pDC, i);
    }

    pDC->SelectObject(&pOldPen);
}

/// void CMainWindow::DrawX
void CMainWindow::DrawX(CDC *pDC, int nPos)
{
    CPen pen(PS_SOLID, 16, RGB(255, 0, 0));
    CPen *pOldPen = pDC->SelectObject(&pen);

    CRect rect = m_rcSquares[nPos];
    rect.DeflateRect(16, 16);
    pDC->MoveTo(rect.left, rect.top);
    pDC->LineTo(rect.right, rect.bottom);
    pDC->MoveTo(rect.left, rect.bottom);
    pDC->LineTo(rect.right, rect.top);

    pDC->SelectObject(&pOldPen);
}

/// void CMainWindow::DrawO
void CMainWindow::DrawO(CDC *pDC, int nPos)
{
    CPen pen(PS_SOLID, 16, RGB(0, 0, 255));
    CPen *pOldPen = pDC->SelectObject(&pen);

    CRect rect = m_rcSquares[nPos];
    rect.DeflateRect(16, 16);
    pDC->Ellipse(rect);

    pDC->SelectObject(&pOldPen);
}

/// void CMainWindow::CheckForGameOver
void CMainWindow::CheckForGameOver()
{
    int nWinner;

    if (nWinner = IsWinner()) {
        CString string = (EX == nWinner) ? _T("X wins!") : _T("O wins!");
        MessageBox(string, _T("Game Over"), MB_ICONEXCLAMATION|MB_OK);
        ResetGame();
    } else if (IsDraw()) {
        MessageBox(_T("It's draw!"), _T("Game Over"), MB_ICONEXCLAMATION|MB_OK);
        ResetGame();
    }
}

/// int CMainWindow::IsWinner
int CMainWindow::IsWinner()
{
    /* 6 7 8 *
     * 3 4 5 *
     * 0 1 2 */
    static int nPattern[8][3] = {
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        0, 3, 6, 
        1, 4, 7, 
        2, 5, 8, 
        0, 4, 8, 
        2, 4, 6
    };
    for (int i = 0; i < 8; ++i) {
        if (EX == m_nGameGrid[nPattern[i][0]] &&
            EX == m_nGameGrid[nPattern[i][1]] &&
            EX == m_nGameGrid[nPattern[i][2]])
            return EX;
        if (OH == m_nGameGrid[nPattern[i][0]] &&
            OH == m_nGameGrid[nPattern[i][1]] &&
            OH == m_nGameGrid[nPattern[i][2]])
            return OH;
    }
    return 0;
}

/// BOOL CMainWindow::IsDraw
BOOL CMainWindow::IsDraw()
{
    for (int i = 0; i < 9; ++i) {
        if (0 == m_nGameGrid[i]) return FALSE;
    }
    return TRUE;
}

/// CMainWindow::ResetGame
void CMainWindow::ResetGame()
{
    m_nNextChar = EX;
    ::ZeroMemory(m_nGameGrid, 9 * sizeof m_nGameGrid[0]);
    Invalidate();
}

#endif// ZRR PWMFC 3.1.2
