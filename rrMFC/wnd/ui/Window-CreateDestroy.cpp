/// \copyright The MIT License

#include "stdafx.h"
#include "Window.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

BOOL Window::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    DbgConPrtMeth(Yellow);
    return TRUE;
}

INT Window::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrtMeth(Yellow);
    return 0;
}

VOID Window::
OnDestroy()
{
    CWnd::OnDestroy();
    DbgConPrtMeth(Yellow);
}

VOID Window::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    DbgConPrtMeth(Yellow);
}
