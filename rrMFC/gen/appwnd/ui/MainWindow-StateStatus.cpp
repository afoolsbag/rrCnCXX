/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "utils/dbgcon.h"

#// Message Handlers

VOID MainWindow::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CWnd::OnActivateApp(bActive, dwThreadID);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnActivateApp\n"));
}

BOOL MainWindow::
OnNcActivate(BOOL bActive)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnNcActivate\n"));
    return CWnd::OnNcActivate(bActive);
}

VOID MainWindow::
OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CWnd::OnActivate(nState, pWndOther, bMinimized);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnActivate\n"));
}
