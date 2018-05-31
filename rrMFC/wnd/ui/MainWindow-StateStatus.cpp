/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID MainWindow::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CWnd::OnActivateApp(bActive, dwThreadID);
    DbgConPrtMeth(Yellow);
}

BOOL MainWindow::
OnNcActivate(BOOL bActive)
{
    DbgConPrtMeth(Yellow);
    return CWnd::OnNcActivate(bActive);
}

VOID MainWindow::
OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CWnd::OnActivate(nState, pWndOther, bMinimized);
    DbgConPrtMeth(Yellow);
}
