/** \copyright The MIT License */

#include "mfc.hpp"

#include <math.h>

#define SEGMENTS 500
#define PI 3.1415926

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
    Create(NULL, _T("Programming Windows with MFC 2.2.1"));
}

/*
 * 议题：设备上下文的种类和属性：
 *
 *  CPaintDC     仅OnPaint回调，用户区
 *  CClientDC    除OnPaint回调，用户区
 *  CWindowDC    窗口内（含用户区）
 *  CMetaFileDC  GDI元文件
 *
 *  TexxtColor   Black        前景颜色
 *  BkColor      White        背景颜色
 *  BkMode       OPAQUE       背景模式
 *  MapMode      MM_TEXT      映射模式
 *  ROP2         R2_COPYPEN   绘图模式
 *  Position     (0, 0)       当前位置
 *  Pen          BLACK_PEN    当前画笔
 *  Brush        WHITE_BRUSH  当前画刷
 *  Font         SYSTEM_FONT  当前字体
 */

/// Class Main Window :: On Paint.
/** \sa <https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#width>.
 *  \sa <https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class#height>.
 *  \sa <https://docs.microsoft.com/cpp/atl-mfc-shared/reference/cpoint-class>.
 *  \sa <https://docs.microsoft.com/cpp/mfc/reference/cdc-class#polyline>.
 */
void CMainWindow::OnPaint()
{
    CRect rect;
    GetClientRect(&rect);
    int nWidth = rect.Width();
    int nHeight = rect.Height();

    CPoint aPoint[SEGMENTS];        // 计算正弦曲线，并取其上点
    for(int i = 0; i < SEGMENTS; ++i) {
        aPoint[i].x = (i * nWidth) / SEGMENTS;
        aPoint[i].y = (nHeight / 2) * (1 - sin(2*PI*i/SEGMENTS));
    }

    CPaintDC dc(this);
    dc.Polyline(aPoint, SEGMENTS);  // 画折线（不含当前位置）
}