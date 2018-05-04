/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID MainWindow::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    DbgConPrtMeth(Yellow);
    CWnd::OnGetMinMaxInfo(lpMMI);
}

VOID MainWindow::
OnEnterSizeMove()
{
    DbgConPrtMeth(Yellow);
    CWnd::OnEnterSizeMove();
}

VOID MainWindow::
OnMoving(UINT fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    DbgConPrtMeth(Yellow);
}

VOID MainWindow::
OnSizing(UINT fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    DbgConPrtMeth(Yellow);
}

VOID MainWindow::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DbgConPrtMeth(Yellow);
}

VOID MainWindow::
OnExitSizeMove()
{
    DbgConPrtMeth(Yellow);
    CWnd::OnExitSizeMove();
}

VOID MainWindow::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DbgConPrtMeth(Yellow);
}

VOID MainWindow::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DbgConPrtMeth(Yellow);
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID MainWindow::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DbgConPrtMeth(Yellow);
}

VOID MainWindow::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DbgConPrtMeth(Yellow);
}
