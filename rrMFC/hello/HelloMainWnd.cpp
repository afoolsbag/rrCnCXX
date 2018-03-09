/// \copyright The MIT License

#include "stdafx.h"
#include "HelloMainWnd.h"

BEGIN_MESSAGE_MAP(CHelloMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CHelloMainWnd::CHelloMainWnd()
{
    // 创建窗口，默认框架，自定义标题
    Create(NULL, TEXT("The Hello Application"));
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create
}

VOID CHelloMainWnd::OnPaint()
{
    // 设备上下文
    CPaintDC devctx(this);
    // https://docs.microsoft.com/cpp/mfc/reference/cpaintdc-class

    // 获取窗口用户区（矩形）
    CRect cltrect;
    GetClientRect(&cltrect);
    // https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#getclientrect

    // 绘制文本
    // 文本内容（前景色），文本长度
    // 绘制区域（背景色），单行、水平居中、垂直居中
    devctx.DrawText(
        TEXT("The Hello Application"), -1,
        &cltrect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    // https://docs.microsoft.com/cpp/mfc/reference/cdc-class#drawtext
}
