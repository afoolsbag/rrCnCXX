/// \copyright The MIT License

#include "stdafx.h"
#include "Window.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    DbgConPrtMeth(Yellow);
    CWnd::OnGetMinMaxInfo(lpMMI);
}

VOID Window::
OnEnterSizeMove()
{
    DbgConPrtMeth(Yellow);
    CWnd::OnEnterSizeMove();
}

VOID Window::
OnMoving(UINT fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    DbgConPrtMeth(Yellow);
}

VOID Window::
OnSizing(UINT fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    DbgConPrtMeth(Yellow);
}

VOID Window::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DbgConPrtMeth(Yellow);
}

VOID Window::
OnExitSizeMove()
{
    DbgConPrtMeth(Yellow);
    CWnd::OnExitSizeMove();
}

VOID Window::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DbgConPrtMeth(Yellow);
}

VOID Window::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DbgConPrtMeth(Yellow);
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID Window::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DbgConPrtMeth(Yellow);
}

VOID Window::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DbgConPrtMeth(Yellow);
}
