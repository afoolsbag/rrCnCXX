/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "utils/dbgcon.h"

#// Message Handlers

VOID MainWindow::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnGetMinMaxInfo\n"));
    CWnd::OnGetMinMaxInfo(lpMMI);
}

VOID MainWindow::
OnEnterSizeMove()
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnEnterSizeMove\n"));
    CWnd::OnEnterSizeMove();
}

VOID MainWindow::
OnMoving(UINT fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnMoving\n"));
}

VOID MainWindow::
OnSizing(UINT fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnSizing\n"));
}

VOID MainWindow::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnWindowPosChanging\n"));
}

VOID MainWindow::
OnExitSizeMove()
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnExitSizeMove\n"));
    CWnd::OnExitSizeMove();
}

VOID MainWindow::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnMove\n"));
}

VOID MainWindow::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnNcCalcSize\n"));
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID MainWindow::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnSize\n"));
}

VOID MainWindow::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("OnWindowPosChanged\n"));
}
