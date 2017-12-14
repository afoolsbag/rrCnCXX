/** \file
 *  \brief *Programming Windows with MFC* 3.1.2 TicTac.
 *  \author zhengrr
 *  \date 2017-12-9 – 14
 *  \copyright The MIT License
 */
#include <afxwin.h>

#define EX 1
#define OH 2

namespace {

/// Class MY APPlication.
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// Class MAIN WINDOW.
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
    int GetNextID(CPoint point);
    void DrawBoard(CDC *pDC);
    void DrawX(CDC *pDC, int nPos);
    void DrawO(CDC *pDC, int nPos);
    void CheckForGameOver();
    int IsWinner();
    BOOL IsDraw();
    void ResetGame();

    DECLARE_MESSAGE_MAP()
};

// -------------------------------------------------------------------------

#ifdef RRMFC_PWMFC_3_1_2_TICTAC_CPP_
CMyApp myApp;
#endif

/// Class MY APPlication :: INITialize INSTANCE.
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

/// Class MAIN WINDOW :: Constructor.
/** \sa [CALCulates WINDOW RECT](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#calcwindowrect). */
CMainWindow::CMainWindow()
{
    m_nNextChar = EX;
    ::ZeroMemory(m_nGameGrid, 9 * sizeof m_nGameGrid[0]);

    CString strWndClass = AfxRegisterWndClass(       // 创建框架窗口类：
        CS_DBLCLKS,                                  // 类样式：注册双击事件；
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),  // 窗口光标；
        (HBRUSH)(COLOR_3DFACE + 1),                  // 窗口背景色；
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)   // 窗口图标。
    );

    CreateEx(                          // 创建窗口：
        0,                             // 无扩展样式；
        strWndClass,                   // 自定义框架；
        _T("Tic-Tac-Toe"),             // 自定义标题；
          WS_OVERLAPPED                // 标题、边框、
        | WS_CAPTION                   // 标题、
        | WS_SYSMENU                   // 系统菜单、
        | WS_MINIMIZEBOX,              // 最小化；
        CW_USEDEFAULT, CW_USEDEFAULT,  // 初始位置；
        CW_USEDEFAULT, CW_USEDEFAULT,  // 初始尺寸。
        NULL, NULL
    );

    CRect rect(0, 0, 352, 352);
    CalcWindowRect(&rect);
    SetWindowPos(                     // 设置窗口位置：
        NULL,
        0, 0,                         // 位置；
        rect.Width(), rect.Height(),  // 尺寸；
          SWP_NOZORDER                // 不前置后置（Z轴）、
        | SWP_NOMOVE                  // 不移动（忽略位置参数）、
        | SWP_NOREDRAW                // 不重绘。
    );
}

/// Class MAIN WINDOW :: POST NonClient DESTROY.
/** \sa [POST NonClient DESTROY](https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy). */
void CMainWindow::PostNcDestroy()
{
    delete this;
}

/// Class MAIN WINDOW :: ON PAINT
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);
    DrawBoard(&dc);
}

/// Class MAIN WINDOW :: ON Left BUTTON DOWN
void CMainWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
    if (EX != m_nNextChar) return;
    int nPos = GetNextID(point);
    if (-1 == nPos || 0 != m_nGameGrid[nPos]) return;

    m_nGameGrid[nPos] = EX;
    m_nNextChar = OH;

    CClientDC dc(this);
    DrawX(&dc, nPos);
    CheckForGameOver();
}

/// Class MAIN WINDOW :: ON Left BUTTON DouBLe CLicK
void CMainWindow::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    CClientDC dc(this);
    if (RGB(0, 0, 0) == dc.GetPixel(point)) ResetGame();
}

/// Class MAIN WINDOW ::ON Right BUTTON DOWN
void CMainWindow::OnRButtonDown(UINT nFlags, CPoint point)
{
    if (OH != m_nNextChar) return;
    int nPos = GetNextID(point);
    if (-1 == nPos || 0 != m_nGameGrid[nPos]) return;

    m_nGameGrid[nPos] = OH;
    m_nNextChar = EX;

    CClientDC dc(this);
    DrawO(&dc, nPos);
    CheckForGameOver();
}

/// Class MAIN WINDOW :: m_rcSquares
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

/// Class MAIN WINDOW :: GET NEXT ID
int CMainWindow::GetNextID(CPoint point)
{
    for (int i = 0; i < 9; ++i) {
        if (m_rcSquares[i].PtInRect(point)) return i;
    }
    return -1;
}

/// Class MAIN WINDOW :: DRAW BOARD
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

/// Class MAIN WINDOW :: DRAW X
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

/// Class MAIN WINDOW :: DRAW O
void CMainWindow::DrawO(CDC *pDC, int nPos)
{
    CPen pen(PS_SOLID, 16, RGB(0, 0, 255));
    CPen *pOldPen = pDC->SelectObject(&pen);

    CRect rect = m_rcSquares[nPos];
    rect.DeflateRect(16, 16);
    pDC->Ellipse(rect);

    pDC->SelectObject(&pOldPen);
}

/// Class MAIN WINDOW :: CHECK FOR GAME OVER
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

/// Class MAIN WINDOW :: IS WINNER
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

/// Class MAIN WINDOW :: IS DRAW
BOOL CMainWindow::IsDraw()
{
    for (int i = 0; i < 9; ++i) {
        if (0 == m_nGameGrid[i]) return FALSE;
    }
    return TRUE;
}

/// Class MAIN WINDOW :: RESET GAME
void CMainWindow::ResetGame()
{
    m_nNextChar = EX;
    ::ZeroMemory(m_nGameGrid, 9 * sizeof m_nGameGrid[0]);
    Invalidate();
}

}// namespace
