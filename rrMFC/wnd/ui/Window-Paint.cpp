/// \copyright The MIT License

#include "stdafx.h"
#include "Window.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnNcPaint()
{
    CWnd::OnNcPaint();
    DbgConPrtMeth(Yellow);
}

BOOL Window::
OnEraseBkgnd(CDC *pDC)
{
    DbgConPrtMeth(Yellow);
    return CWnd::OnEraseBkgnd(pDC);
}

VOID Window::
OnPaint()
{
    CWnd::OnPaint();
    DbgConPrtMeth(Yellow);
}
