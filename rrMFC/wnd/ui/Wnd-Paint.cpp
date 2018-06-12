/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnNcPaint()
{
    CWnd::OnNcPaint();
    DbgConMeth();
}

BOOL Window::
OnEraseBkgnd(CDC *pDC)
{
    DbgConMeth();
    return CWnd::OnEraseBkgnd(pDC);
}

VOID Window::
OnPaint()
{
    CWnd::OnPaint();
    DbgConMeth();
}
