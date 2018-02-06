/// \copyright The MIT License

#include "CHelloApp.h"


CHelloApp gApp;


// https://docs.microsoft.com/cpp/mfc/reference/cwinthread-class#m_pmainwnd
// https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#showwindow
// https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#updatewindow
BOOL CHelloApp::InitInstance()
{
    // 此函数基类函数默认操作直接返回`TURE`，因而无需调用
    m_pMainWnd = new CHelloMainWnd;           // 创建窗口类
    m_pMainWnd->ShowWindow(m_nCmdShow);  // 按给定方式，显示窗口
    m_pMainWnd->UpdateWindow();          // 重绘窗口
    return TRUE;                         // 返回`FALSE`可关闭应用
}

int CHelloApp::ExitInstance()
{
    return CWinApp::ExitInstance();  // 调用基类函数，此函数返回值将作为退出代码
}


BEGIN_MESSAGE_MAP(CHelloMainWnd, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

//https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#create>
CHelloMainWnd::CHelloMainWnd()
{
    // 创建窗口
    Create(NULL,                            // 默认框架
           TEXT("The Hello Application"));  // 自定义标题
}

// https://docs.microsoft.com/cpp/mfc/reference/cpaintdc-class
// https://docs.microsoft.com/cpp/atl-mfc-shared/reference/crect-class
// https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#getclientrect
// https://docs.microsoft.com/cpp/mfc/reference/cdc-class#drawtext
void CHelloMainWnd::OnPaint()
{
    CPaintDC dc(this);  // 设备上下文

    // 获取窗口用户区（矩形）
    CRect rect;
    GetClientRect(&rect);

    // 绘制文本
    dc.DrawText(TEXT("Hello, MFC."),                      // 文本内容（前景色）
                -1,                                       // 文本长度
                &rect,                                    // 绘制区域（背景色）
                DT_SINGLELINE | DT_CENTER | DT_VCENTER);  // 单行、水平居中、垂直居中
}
