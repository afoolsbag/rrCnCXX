/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "utils/dbgcon.h"

#// Message Handlers

VOID MainWindow::
OnNcPaint()
{
    CWnd::OnNcPaint();
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnNcPaint\n"));
}

BOOL MainWindow::
OnEraseBkgnd(CDC *pDC)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnEraseBkgnd\n"));
    return CWnd::OnEraseBkgnd(pDC);
}

VOID MainWindow::
OnPaint()
{
    CWnd::OnPaint();
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnPaint\n"));
}
