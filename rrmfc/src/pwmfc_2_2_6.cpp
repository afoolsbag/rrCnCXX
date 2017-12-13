/** \file
 *  \brief *Programming Windows with MFC* 2.2.6.
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

#ifdef RRMFC_PWMFC_2_2_6_CPP_
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
    
    CFont font;  // [Class FONT](https://docs.microsoft.com/cpp/mfc/reference/cfont-class)
    font.CreatePointFont(72 * 10, _T("Arial"));  // [CREATE POINT FONT](https://docs.microsoft.com/cpp/mfc/reference/cfont-class#createpointfont)

    CPaintDC dc(this);
    dc.SelectObject(&font);  // [SELECT OBJECT](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#selectobject)
    dc.SetBkMode(TRANSPARENT);  // [SETs BacKground MODE](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setbkmode)
    
    CString string = _T("Hello, MFC");  // [Class STRING](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/cstringt-class)

    rect.OffsetRect(16, 16);  // [OFFSET RECT](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#offsetrect)
    dc.SetTextColor(RGB(192, 192, 192));  // [SETs TEXT COLOR](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#settextcolor)
    dc.DrawText(string, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);

    rect.OffsetRect(-16, -16);
    dc.SetTextColor(RGB(0, 0, 0));
    dc.DrawText(string, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
}

}// namespace
