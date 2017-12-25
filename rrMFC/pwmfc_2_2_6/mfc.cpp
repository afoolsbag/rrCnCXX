/** \copyright The MIT License */

#include "mfc.hpp"

// -------------------------------------------------------------------------

CMyApp myApp;

/// Class My Application :: Initialize Instance.
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

/// Class Main Window :: Constructor.
CMainWindow::CMainWindow()
{
    Create(NULL, _T("Programming Windows with MFC 2.2.6"));
}

/// Class MAIN WINDOW :: ON PAINT.
/** \sa <https://docs.microsoft.com/cpp/mfc/reference/cfont-class>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cfont-class#createpointfont>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cdc-class#selectobject>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setbkmode>.
 *  \sa <https://docs.microsoft.com/cpp/atl-mfc-shared/reference/cstringt-class>.
 *  \sa <https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#offsetrect>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cdc-class#settextcolor>.
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
