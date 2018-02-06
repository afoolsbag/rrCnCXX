/// \copyright The MIT License

#include "CRotateTextApp.h"


CRotateTextApp gApp;


BOOL CRotateTextApp::InitInstance()
{
    m_pMainWnd = new CRotateTextMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}


BEGIN_MESSAGE_MAP(CRotateTextMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CRotateTextMainWnd::CRotateTextMainWnd()
{
    Create(NULL, TEXT("The Rotate Text Application"));
}

// `SetWindowOrg`和`SetViewportOrg`
//
// `SetWindowOrg(x, y)` 将逻辑坐标`(x, y)`移动到设备原点（左上角）；
// `SetViewportOrg(x, y)` 将逻辑原点`(0, 0)`移动到设备指定点（某个点）。
//
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setviewportorg
// https://msdn.microsoft.com/library/dd145037.aspx
// https://msdn.microsoft.com/library/aa366920.aspx
// https://msdn.microsoft.com/library/ms647490.aspx
// https://docs.microsoft.com/cpp/mfc/reference/cfont-class#createpointfontindirect
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#textout
void CRotateTextMainWnd::OnPaint()
{
    CRect rect;
    GetClientRect(&rect);

    CPaintDC dc(this);
    dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);  // 将逻辑原点移动到用户区正中。
    dc.SetBkMode(TRANSPARENT);

    for (int i = 0; i < 360/*deg*/ * 10; i += 15/*deg*/ * 10) {
        LOGFONT lf;                             // 字体样式
        ZeroMemory(&lf, sizeof lf);
        lf.lfHeight = 16 * 10;                  // 16磅
        lf.lfWeight = FW_BOLD;                  // 粗体
        lf.lfEscapement = i;
        lf.lfOrientation = lf.lfEscapement;     // 角度
        lstrcpy(lf.lfFaceName, TEXT("Arial"));  // Arial字体

        CFont font;
        font.CreatePointFontIndirect(&lf);

        CFont *fontptrOld = dc.SelectObject(&font);
        dc.TextOut(0, 0, CString(TEXT("Hello, MFC")));
        dc.SelectObject(fontptrOld);
    }
}
