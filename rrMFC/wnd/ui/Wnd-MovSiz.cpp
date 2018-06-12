/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    DbgConMeth();
    CWnd::OnGetMinMaxInfo(lpMMI);
}

VOID Window::
OnEnterSizeMove()
{
    DbgConMeth();
    CWnd::OnEnterSizeMove();
}

VOID Window::
OnMoving(UINT fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    DbgConMeth();
}

VOID Window::
OnSizing(UINT fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    DbgConMeth();
}

VOID Window::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DbgConMeth();
}

VOID Window::
OnExitSizeMove()
{
    DbgConMeth();
    CWnd::OnExitSizeMove();
}

VOID Window::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DbgConMeth();
}

VOID Window::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DbgConMeth();
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID Window::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DbgConMeth();
}

VOID Window::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DbgConMeth();
}
