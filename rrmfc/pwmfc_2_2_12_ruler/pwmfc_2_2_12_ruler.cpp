/** \file
 *  \brief *Programming Windows with MFC* 2.2.12 Ruler.
 *  \author zhengrr
 *  \date 2017-12-8 – 14
 *  \copyright The MIT License
 */
#include <afxwin.h>

namespace {

/// Class MY APPlication.
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// Class MAIN WINDOW.
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();

protected:
    afx_msg void OnPaint();

    DECLARE_MESSAGE_MAP()
};

// -------------------------------------------------------------------------

#ifdef RRMFC_PWMFC_2_2_12_RULER_CPP_
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

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

/// Class MAIN WINDOW :: Constructor.
CMainWindow::CMainWindow()
{
    Create(NULL, _T("Ruler"));
}

/// Class MAIN WINDOW :: ON PAINT.
/** \sa [SETs MAPping Mode](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setmapmode).
 *  \sa [SETs TEXT-ALIGNment](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#settextalign).
 *  \sa [BRUSH](https://docs.microsoft.com/cpp/mfc/reference/cbrush-class).
 *  \sa [RECTANGLE](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#rectangle).
 *  \sa [MOVE TO](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#moveto).
 *  \sa [LINE TO](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#lineto).
 */
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);

    dc.SetMapMode(MM_LOENGLISH);  // 1 unit ~ 0.01 in., y v / > x.
    dc.SetTextAlign(TA_CENTER|TA_BOTTOM);
    dc.SetBkMode(TRANSPARENT);

    /* ----------------~.'~-----------------
     * |(100, -100)     .'                 |
     * |                .'                 |
     * |                .'     (1300, -200)|
     * ----------------~.'~----------------- */
    CBrush brush(RGB(255, 255, 0));
    CBrush *pOldBrush = dc.SelectObject(&brush);
    dc.Rectangle(100, -100, 1300, -200);
    dc.SelectObject(pOldBrush);

    for(int i = 125; i < 1300; i += 25) {
        dc.MoveTo(i, -192);
        dc.LineTo(i, -200);
    }

    for(int i = 150; i < 1300; i += 50) {
        dc.MoveTo(i, -184);
        dc.LineTo(i, -200);
    }

    for(int i = 200; i < 1300; i += 100) {
        dc.MoveTo(i, -175);
        dc.LineTo(i, -200);

        CString string;
        string.Format(_T("%d"), i / 100 - 1);
        dc.TextOut(i, -175, string);
    }
}

}// namespace
