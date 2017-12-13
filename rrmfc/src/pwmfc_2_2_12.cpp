/** \file
 *  \brief *Programming Windows with MFC* 2.2.12.
 *  \author zhengrr
 *  \date 2017-12-8 – 13
 *  \copyright The MIT License
 */
#include <afxwin.h>

namespace {

/// CMyApp
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance();
};

/// CMainWindow
class CMainWindow : public CFrameWnd {
public:
    CMainWindow();
protected:
    afx_msg void OnPaint();
    DECLARE_MESSAGE_MAP()
};

#ifdef RRMFC_PWMFC_2_2_12_CPP_
CMyApp myApp;
#endif

/// CMyApp::InitInstance
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

/// CMainWindow::CMainWindow
CMainWindow::CMainWindow()
{
    Create(NULL, _T("Ruler"));
}

/// CMainWindow::OnPaint
void CMainWindow::OnPaint()
{
    CPaintDC dc(this);

    dc.SetMapMode(MM_LOENGLISH);  // [SETs MAPping Mode](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setmapmode)
    dc.SetTextAlign(TA_CENTER|TA_BOTTOM);  // [SETs TEXT-ALIGNment](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#settextalign)
    dc.SetBkMode(TRANSPARENT);

    CBrush brush(RGB(255, 255, 0));  // [BRUSH](https://docs.microsoft.com/cpp/mfc/reference/cbrush-class)
    CBrush *pOldBrush = dc.SelectObject(&brush);
    dc.Rectangle(100, -100, 1300, -200);  // [RECTANGLE](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#rectangle)
    dc.SelectObject(pOldBrush);

    for(int i = 125; i < 1300; i += 25) {
        dc.MoveTo(i, -192);  // [MOVE TO](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#moveto)
        dc.LineTo(i, -200);  // [LINE TO](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#lineto)
    }

    for(int i = 150; i < 1300; i += 50) {
        dc.MoveTo(i, -184);
        dc.LineTo(i, -200);
    }

    for(int i = 200; i < 1300; i += 100) {
        dc.MoveTo(i, -175);
        dc.LineTo(i, -200);

        CString string;
        string.Format(_T("%d"), (i/100) - 1);
        dc.TextOut(i, -175, string);
    }
}

}// namespace
