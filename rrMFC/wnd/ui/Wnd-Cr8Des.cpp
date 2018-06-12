/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

BOOL Window::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    DbgConMeth();
    return TRUE;
}

INT Window::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConMeth();
    return 0;
}

VOID Window::
OnDestroy()
{
    CWnd::OnDestroy();
    DbgConMeth();
}

VOID Window::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    DbgConMeth();
}
