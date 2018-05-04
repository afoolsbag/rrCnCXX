/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

BOOL MainWindow::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    DbgConPrtMeth(Yellow);
    return TRUE;
}

INT MainWindow::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrtMeth(Yellow);
    return 0;
}

VOID MainWindow::
OnDestroy()
{
    CWnd::OnDestroy();
    DbgConPrtMeth(Yellow);
}

VOID MainWindow::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    DbgConPrtMeth(Yellow);
}
