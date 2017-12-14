/** \file
 *  \brief *Programming Windows with MFC* 2.2.6.
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

#ifdef RRMFC_PWMFC_2_2_6_CPP_
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
    Create(NULL, _T("Programming Windows with MFC 2.2.6"));
}

/// Class MAIN WINDOW :: ON PAINT.
/** \sa [Class FONT](https://docs.microsoft.com/cpp/mfc/reference/cfont-class).
 *  \sa [CREATE POINT FONT](https://docs.microsoft.com/cpp/mfc/reference/cfont-class#createpointfont).
 *  \sa [SELECT OBJECT](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#selectobject).
 *  \sa [SETs BacKground MODE](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setbkmode).
 *  \sa [Class STRING](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/cstringt-class).
 *  \sa [OFFSET RECT](https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#offsetrect).
 *  \sa [SETs TEXT COLOR](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#settextcolor).
 */
void CMainWindow::OnPaint()
{
    CRect rect;
    GetClientRect(&rect);
    
    CFont font;
    font.CreatePointFont(  // 创建字体：
        72 * 10,           // 72磅;
        _T("Arial")        // Arial 字体。
    );

    CPaintDC dc(this);
    dc.SelectObject(&font);     // 设备上下文属性：字体；
    dc.SetBkMode(TRANSPARENT);  // 设备上下文属性：背景模式－透明。
    
    CString string = _T("Hello, MFC");

    rect.OffsetRect(16, 16);    // 移动矩形。
    dc.SetTextColor(RGB(192, 192, 192));
    dc.DrawText(string, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);

    rect.OffsetRect(-16, -16);
    dc.SetTextColor(RGB(0, 0, 0));
    dc.DrawText(string, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
}

}// namespace
