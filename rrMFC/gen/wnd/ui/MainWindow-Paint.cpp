/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID MainWindow::
OnNcPaint()
{
    CWnd::OnNcPaint();
    DbgConPrtMeth(Yellow);
}

BOOL MainWindow::
OnEraseBkgnd(CDC *pDC)
{
    DbgConPrtMeth(Yellow);
    return CWnd::OnEraseBkgnd(pDC);
}

VOID MainWindow::
OnPaint()
{
    CWnd::OnPaint();
    DbgConPrtMeth(Yellow);
}
