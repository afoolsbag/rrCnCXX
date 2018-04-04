/// \copyright The MIT License

#include "stdafx.h"
#include "MainWnd.h"

BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWnd::CMainWnd()
{
    // 创建窗口（默认框架，自定义标题） 
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create
    Create(NULL, TEXT("The Abc Application"));
}

VOID CMainWnd::OnPaint()
{
    // 设备上下文 
    // https://docs.microsoft.com/cpp/mfc/reference/cpaintdc-class
    CPaintDC devctx(this);

    // 获取窗口用户区（矩形） 
    // https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#getclientrect
    CRect cltrect;
    GetClientRect(&cltrect);

    // 绘制文本（文本内容（前景色），文本长度，绘制区域（背景色），单行、水平居中、垂直居中） 
    // https://docs.microsoft.com/cpp/mfc/reference/cdc-class#drawtext
    devctx.DrawText(
        TEXT("The Abc Application"), -1,
        &cltrect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
