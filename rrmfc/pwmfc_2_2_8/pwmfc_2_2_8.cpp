/** \file
 *  \brief *Programming Windows with MFC* 2.2.8.
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

#ifdef RRMFC_PWMFC_2_2_8_CPP_
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
    Create(NULL, _T("Programming Windows with MFC 2.2.8"));
}

/*
 * 议题："SetWindowOrg" 和 "SetViewportOrg"：
 *
 * 　　"SetWindowOrg(x, y)" 将逻辑坐标(x, y)移动到设备原点（左上角）；
 * 　　"SetViewportOrg(x, y)" 将逻辑原点(0, 0)移动到设备指定点（某个点）。
 */

/// Class MAIN WINDOW :: ON PAINT.
/** \sa [SET VIEWPORT ORiGin](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setviewportorg).
 *  \sa [LOGical FONT](https://msdn.microsoft.com/library/dd145037.aspx).
 *  \sa [ZERO MEMORY](https://msdn.microsoft.com/library/aa366920.aspx).
 *  \sa [Long STRing CoPY](https://msdn.microsoft.com/library/ms647490.aspx).
 *  \sa [CREATE POINT FONT INDIRECT](https://docs.microsoft.com/cpp/mfc/reference/cfont-class#createpointfontindirect).
 *  \sa [TEXT OUT](https://docs.microsoft.com/cpp/mfc/reference/cdc-class#textout).
 */
void CMainWindow::OnPaint()
{
    CRect rect;
    GetClientRect(&rect);

    CPaintDC dc(this);
    dc.SetViewportOrg(rect.Width()/2, rect.Height()/2);  // 将逻辑原点移动到用户区正中。
    dc.SetBkMode(TRANSPARENT);
    
    for(int i = 0; i < 360 * 10; i += 15 * 10) {
        LOGFONT lf;                             // 字体样式：
        ::ZeroMemory(&lf, sizeof lf);
        lf.lfHeight = 16 * 10;                  // 16磅；
        lf.lfWeight = FW_BOLD;                  // 粗体；
        lf.lfEscapement = i;                    // 不知是啥，与下一字段一起设定旋转角度；
        lf.lfOrientation = i;                   // 角度；
        ::lstrcpy(lf.lfFaceName, _T("Arial"));  // Arial 字体。

        CFont font;
        font.CreatePointFontIndirect(&lf);

        CFont *pOldFont = dc.SelectObject(&font);
        dc.TextOut(0, 0, CString(_T("Hello, MFC")));
        dc.SelectObject(pOldFont);
    }
}

}// namespace
