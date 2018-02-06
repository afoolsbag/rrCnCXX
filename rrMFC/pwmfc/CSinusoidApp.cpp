/// \copyright The MIT License

#include "CSinusoidApp.h"

#include <cmath>

namespace {
const double kPi = 3.1415926;  ///< 圆周率近似值
const int kSegments = 500;     ///< 采样片段数目
}// namespace


CSinusoidApp gApp;


BOOL CSinusoidApp::InitInstance()
{
    m_pMainWnd = new CSinusoidMainWnd;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}


BEGIN_MESSAGE_MAP(CSinusoidMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CSinusoidMainWnd::CSinusoidMainWnd()
{
    Create(NULL, TEXT("The Sinusoid Application"));
}

// 设备上下文的种类和属性：
//
// CPaintDC     仅OnPaint回调，用户区
// CClientDC    除OnPaint回调，用户区
// CWindowDC    窗口内（含用户区）
// CMetaFileDC  GDI元文件
//
// TexxtColor   Black        前景颜色
// BkColor      White        背景颜色
// BkMode       OPAQUE       背景模式
// MapMode      MM_TEXT      映射模式
// ROP2         R2_COPYPEN   绘图模式
// Position     (0, 0)       当前位置
// Pen          BLACK_PEN    当前画笔
// Brush        WHITE_BRUSH  当前画刷
// Font         SYSTEM_FONT  当前字体
//
// https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#width
// https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#height
// https://docs.microsoft.com/cpp/atl-mfc-shared/reference/cpoint-class
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#polyline
void CSinusoidMainWnd::OnPaint()
{
    CPaintDC dc(this);

    CRect rect;
    GetClientRect(&rect);
    const int wd = rect.Width();
    const int ht = rect.Height();

    // 按采样数目，计算并取正弦曲线上的点
    CPoint pts[kSegments];
    for (int i = 0; i < kSegments; ++i) {
        pts[i].x = (i * wd) / kSegments;
        pts[i].y = (ht / 2) * (1 - sin(2 * kPi*i / kSegments));
    }

    dc.Polyline(pts, kSegments);  // 画折线（不含当前位置）
}
