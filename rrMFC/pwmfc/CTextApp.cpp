/// \copyright The MIT License

#include "CTextApp.h"


CTextApp gApp;


BOOL CTextApp::InitInstance()
{
    m_pMainWnd = new CTextMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}


BEGIN_MESSAGE_MAP(CTextMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CTextMainWnd::CTextMainWnd()
{
    Create(NULL, TEXT("The Text Application"));
}


// https://docs.microsoft.com/cpp/mfc/reference/cfont-class
// https://docs.microsoft.com/cpp/mfc/reference/cfont-class#createpointfont
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#selectobject
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setbkmode
// https://docs.microsoft.com/cpp/atl-mfc-shared/reference/cstringt-class
// https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#offsetrect
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#settextcolor
void CTextMainWnd::OnPaint()
{
    CPaintDC dc(this);

    CFont font;
    // 创建字体：
    font.CreatePointFont(
        72 * 10,       // 72磅
        TEXT("Arial")  // Arial字体
    );

    dc.SelectObject(&font);     // 设备上下文属性：字体
    dc.SetBkMode(TRANSPARENT);  // 设备上下文属性：背景模式－透明

    CRect rect;
    GetClientRect(&rect);
    CString text = TEXT("Hello, MFC.");

    rect.OffsetRect(16, 16);    // 偏移矩形
    dc.SetTextColor(RGB(192, 192, 192));
    dc.DrawText(text, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    rect.OffsetRect(-16, -16);
    dc.SetTextColor(RGB(0, 0, 0));
    dc.DrawText(text, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
