/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

IMPLEMENT_DYNCREATE(MainWindow, CFrameWnd)

BEGIN_MESSAGE_MAP(MainWindow, CFrameWnd)
    ON_WM_PAINT()
END_MESSAGE_MAP()

MainWindow::MainWindow()
{
    Create(NULL, TEXT("The MFC Application"));
}

VOID MainWindow::OnPaint()
{
    CPaintDC devCtx(this);  // device-context

    CRect cltRect;  // client rect
    GetClientRect(&cltRect);

    devCtx.DrawText(
        TEXT("The MFC Application"), -1,
        &cltRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
