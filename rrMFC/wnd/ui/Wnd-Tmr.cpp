/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#// Message Handlers

VOID Window::
OnTimer(UINT_PTR nIDEvent)
{
    DcMeth();
    switch (nIDEvent) {
    case ALPHA: break;
    case BETA: break;
    case GAMMA: break;
    default: break;
    }
    CWnd::OnTimer(nIDEvent);
}
