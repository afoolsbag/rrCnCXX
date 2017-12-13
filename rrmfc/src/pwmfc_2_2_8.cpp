/** \file
 *  \brief *Programming Windows with MFC* 2.2.8.
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

#ifdef RRMFC_PWMFC_2_2_8_CPP_
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
    Create(NULL, _T("The Hello Application"));
}

/// CMainWindow::OnPaint
void CMainWindow::OnPaint()
{
    CRect rect;
    GetClientRect(&rect);

    CPaintDC dc(this);
    dc.SetViewportOrg(rect.Width()/2, rect.Height()/2);  // [SET VIEWPORT ORiGin](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setviewportorg)
    dc.SetBkMode(TRANSPARENT);
    
    for(int i = 0; i < 360 * 10; i += 15 * 10) {
        LOGFONT lf;  // [LOGical FONT](https://msdn.microsoft.com/library/dd145037.aspx)
        ::ZeroMemory(&lf, sizeof lf);  // [ZERO MEMORY](https://msdn.microsoft.com/library/aa366920.aspx)
        lf.lfHeight = 160;
        lf.lfWeight = FW_BOLD;
        lf.lfEscapement = i;
        lf.lfOrientation = i;
        ::lstrcpy(lf.lfFaceName, _T("Arial"));  // [Long STRing CoPY](https://msdn.microsoft.com/library/ms647490.aspx)

        CFont font;
        font.CreatePointFontIndirect(&lf);  // [CREATE POINT FONT INDIRECT](https://docs.microsoft.com/cpp/mfc/reference/cfont-class#createpointfontindirect)

        CFont *pOldFont = dc.SelectObject(&font);
        dc.TextOut(0, 0, CString(_T("Hello, MFC")));  // [TEXT OUT](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#textout)
        dc.SelectObject(pOldFont);
    }
}

}// namespace
