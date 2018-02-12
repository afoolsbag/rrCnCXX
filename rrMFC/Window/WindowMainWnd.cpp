/// \copyright The MIT License

#include "Window/stdafx.h"
#include "Window/WindowMainWnd.h"

BEGIN_MESSAGE_MAP(CWindowMainWnd, CWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

CWindowMainWnd::CWindowMainWnd()
{
    // 注册框架窗口类
    // 类样式
    // 窗口光标
    // 窗口背景色
    // 窗口图标
    CONST CString wnd_class_name = AfxRegisterWndClass(
        0,
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
        (HBRUSH)(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    // 创建窗口
    // 无扩展样式，自定义框架，自定义标题
    // 标题边框、标题、系统菜单、最小化
    // 初始位置，初始尺寸
    CreateEx(
        0, wnd_class_name, TEXT("The Window Application"),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL
    );

    CRect rect(0, 0, 352, 352);
    CalcWindowRect(&rect);
    // 设置窗口位置
    // 位置，尺寸
    // 不前置后置（Z轴）、不移动（忽略位置参数）、不重绘
    SetWindowPos(
        NULL,
        0, 0, rect.Width(), rect.Height(),
        SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW
    );
}

VOID CWindowMainWnd::PostNcDestroy()
{
    delete this;
}

VOID CWindowMainWnd::OnPaint()
{
    CPaintDC devctx(this);

    CRect cltrect;
    GetClientRect(&cltrect);

    devctx.DrawText(
        TEXT("The Window Application"), -1,
        &cltrect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
