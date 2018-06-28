/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

LRESULT Window::
OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam)
{
    UNUSED(wParam); UNUSED(lParam);
    DcMeth();
    return 0;
}

LRESULT Window::
OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam)
{
    UNUSED(wParam); UNUSED(lParam);
    DcMeth();
    return 0;
}

LRESULT Window::
OnCustomRegisterMessage(WPARAM wParam, LPARAM lParam)
{
    UNUSED(wParam); UNUSED(lParam);
    DcMeth();
    return 0;
}
