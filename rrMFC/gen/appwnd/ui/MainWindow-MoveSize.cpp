/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "utils/dbgcon.h"

#// Message Handlers

VOID MainWindow::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    DbgConPrt(LightYellow, TEXT("MainWindow::OnGetMinMaxInfo\n"));
    CWnd::OnGetMinMaxInfo(lpMMI);
}

VOID MainWindow::
OnEnterSizeMove()
{
    DbgConPrt(LightYellow, TEXT("MainWindow::OnEnterSizeMove\n"));
    CWnd::OnEnterSizeMove();
}

VOID MainWindow::
OnMoving(UINT fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    DbgConPrt(LightYellow, TEXT("MainWindow::OnMoving\n"));
}

VOID MainWindow::
OnSizing(UINT fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    DbgConPrt(LightYellow, TEXT("MainWindow::OnSizing\n"));
}

VOID MainWindow::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainWindow::OnWindowPosChanging\n"));
}

VOID MainWindow::
OnExitSizeMove()
{
    DbgConPrt(LightYellow, TEXT("MainWindow::OnExitSizeMove\n"));
    CWnd::OnExitSizeMove();
}

VOID MainWindow::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DbgConPrt(LightYellow, TEXT("MainWindow::OnMove\n"));
}

VOID MainWindow::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DbgConPrt(LightYellow, TEXT("MainWindow::OnNcCalcSize\n"));
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID MainWindow::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DbgConPrt(LightYellow, TEXT("MainWindow::OnSize\n"));
}

VOID MainWindow::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DbgConPrt(LightYellow, TEXT("MainWindow::OnWindowPosChanged\n"));
}
