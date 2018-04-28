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
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnNcCreate\n"));
    return TRUE;
}

INT MainWindow::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnCreate\n"));
    return 0;
}

VOID MainWindow::
OnDestroy()
{
    CWnd::OnDestroy();
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnDestroy\n"));
}

VOID MainWindow::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnNcDestroy\n"));
}
