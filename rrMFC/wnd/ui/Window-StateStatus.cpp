/// \copyright The MIT License

#include "stdafx.h"
#include "Window.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CWnd::OnActivateApp(bActive, dwThreadID);
    DbgConPrtMeth(Yellow);
}

BOOL Window::
OnNcActivate(BOOL bActive)
{
    DbgConPrtMeth(Yellow);
    return CWnd::OnNcActivate(bActive);
}

VOID Window::
OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CWnd::OnActivate(nState, pWndOther, bMinimized);
    DbgConPrtMeth(Yellow);
}
