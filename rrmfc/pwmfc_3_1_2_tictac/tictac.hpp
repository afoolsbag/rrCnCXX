/** \file
 *  \brief *Programming Windows with MFC* 3.1.2 TicTac.
 *  \author zhengrr
 *  \date 2017-12-9 – 15
 *  \copyright The MIT License */

#include <afxwin.h>

#define EX 1
#define OH 2

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
