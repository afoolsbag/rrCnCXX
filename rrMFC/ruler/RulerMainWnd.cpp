/// \copyright The MIT License

#include "stdafx.h"
#include "RulerMainWnd.h"

BEGIN_MESSAGE_MAP(CRulerMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CRulerMainWnd::CRulerMainWnd()
{
    Create(NULL, TEXT("The Ruler Application"));
}

VOID CRulerMainWnd::OnPaint()
{
    CPaintDC devctx(this);

    // 初始化设备上下文
    devctx.SetMapMode(MM_LOENGLISH);  // 1 unit = 0.01 inch, ^>
    devctx.SetTextAlign(TA_CENTER | TA_BOTTOM);
    devctx.SetBkMode(TRANSPARENT);

    enum {
        kLeft = 100,
        kTop = -100,
        kRight = 1300,
        kBottom = -200,
        kQtrIn = 25,     ///< 四分之一英寸（Quarter Inch）
        kHlfIn = 50,     ///< 二分之一英寸（Half Inch）
        kInch = 100,     ///< 英寸（Inch）
    };

    // 绘制主体
    CBrush brush(RGB(255, 255, 0)/*黄色*/);
    CBrush *oldbrush = devctx.SelectObject(&brush);
    devctx.Rectangle(kLeft, kTop, kRight, kBottom);
    devctx.SelectObject(oldbrush);

    // 绘制刻度
    for (INT iqtrin = kLeft + kQtrIn; iqtrin < kRight; iqtrin += kQtrIn) {
        devctx.MoveTo(iqtrin, kBottom + 8);
        devctx.LineTo(iqtrin, kBottom);
    }

    for (INT ihlfin = kLeft + kHlfIn; ihlfin < kRight; ihlfin += kHlfIn) {
        devctx.MoveTo(ihlfin, kBottom + 16);
        devctx.LineTo(ihlfin, kBottom);
    }

    for (INT iinch = kLeft + kInch; iinch < kRight; iinch += kInch) {
        devctx.MoveTo(iinch, kBottom + 25);
        devctx.LineTo(iinch, kBottom);

        CString mark;
        mark.Format(TEXT("%i"), (iinch - kLeft) / kInch);
        devctx.TextOut(iinch, kBottom + 25, mark);
    }
}
