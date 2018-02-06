/// \copyright The MIT License

#include "CRulerApp.h"


CRulerApp gApp;


BOOL CRulerApp::InitInstance()
{
    m_pMainWnd = new CRulerMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}


BEGIN_MESSAGE_MAP(CRulerMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CRulerMainWnd::CRulerMainWnd()
{
    Create(NULL, TEXT("The Ruler Application"));
}

// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#setmapmode
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#settextalign
// https://docs.microsoft.com/cpp/mfc/reference/cbrush-class
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#rectangle
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#moveto
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#lineto
void CRulerMainWnd::OnPaint()
{
    CPaintDC dc(this);

    dc.SetMapMode(MM_LOENGLISH);  // 1 unit === 0.01 in., y(^)/x(>).
    dc.SetTextAlign(TA_CENTER | TA_BOTTOM);
    dc.SetBkMode(TRANSPARENT);

    //     100                                   1300
    // -100 ----------------~ . ` ~-----------------
    //      |(100, -100)      . `                  |
    //      |                 . `                  |
    //      |                 . `      (1300, -200)|
    // -200 ----------------~ . ` ~-----------------

    CBrush brush(RGB(255, 255, 0));
    CBrush *brushptrOld = dc.SelectObject(&brush);
    dc.Rectangle(100, -100, 1300, -200);
    dc.SelectObject(brushptrOld);

    for (int i = 100 + 25; i < 1300; i += 25) {
        dc.MoveTo(i, -192);
        dc.LineTo(i, -200);
    }

    for (int i = 100 + 50; i < 1300; i += 50) {
        dc.MoveTo(i, -184);
        dc.LineTo(i, -200);
    }

    for (int i = 100 + 100; i < 1300; i += 100) {
        dc.MoveTo(i, -175);
        dc.LineTo(i, -200);

        CString inch;
        inch.Format(TEXT("%i"), i / 100 - 1);
        dc.TextOut(i, -175, inch);
    }
}
