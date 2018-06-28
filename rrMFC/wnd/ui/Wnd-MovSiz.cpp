/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    DcMeth();
    CWnd::OnGetMinMaxInfo(lpMMI);
}

VOID Window::
OnEnterSizeMove()
{
    DcMeth();
    CWnd::OnEnterSizeMove();
}

VOID Window::
OnMoving(UINT fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    DcMeth();
}

VOID Window::
OnSizing(UINT fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    DcMeth();
}

VOID Window::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DcMeth();
}

VOID Window::
OnExitSizeMove()
{
    DcMeth();
    CWnd::OnExitSizeMove();
}

VOID Window::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DcMeth();
}

VOID Window::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DcMeth();
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

VOID Window::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DcMeth();
}

VOID Window::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DcMeth();
}
