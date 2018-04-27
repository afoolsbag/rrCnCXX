/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "utils/dbgcon.h"

#// Message Handlers

BOOL MainWindow::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    DbgConPrt(LightYellow, TEXT("MainWindow::OnNcCreate\n"));
    return TRUE;
}

INT MainWindow::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(LightYellow, TEXT("MainWindow::OnCreate\n"));
    return 0;
}

VOID MainWindow::
OnDestroy()
{
    CWnd::OnDestroy();
    DbgConPrt(LightYellow, TEXT("MainWindow::OnDestroy\n"));
}

VOID MainWindow::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    DbgConPrt(LightYellow, TEXT("MainWindow::OnNcDestroy\n"));
}
