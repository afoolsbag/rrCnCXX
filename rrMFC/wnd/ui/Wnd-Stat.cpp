/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CWnd::OnActivateApp(bActive, dwThreadID);
    DbgConMeth();
}

BOOL Window::
OnNcActivate(BOOL bActive)
{
    DbgConMeth();
    return CWnd::OnNcActivate(bActive);
}

VOID Window::
OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CWnd::OnActivate(nState, pWndOther, bMinimized);
    DbgConMeth();
}
