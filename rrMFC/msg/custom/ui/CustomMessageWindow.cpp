/// \copyright The MIT License

#include "stdafx.h"
#include "CustomMessageWindow.h"

#include "rrwindows/dbgcon.h"

#include "CustomMessageApplication.h"

#// Private Message
#define PM_CUSTOM_PRIVATE_MESSAGE (WM_USER + 1)

IMPLEMENT_DYNAMIC(CustomMessageWindow, CWnd)

BEGIN_MESSAGE_MAP(CustomMessageWindow, CWnd)
    ON_WM_CREATE()
    ON_MESSAGE(PM_CUSTOM_PRIVATE_MESSAGE, &CustomMessageWindow::OnCustomPrivateMessage)
    ON_MESSAGE(AM_CUSTOM_APPLICATION_MESSAGE, &CustomMessageWindow::OnCustomApplicationMessage)
    ON_REGISTERED_MESSAGE(RM_CUSTOM_REGISTER_MESSAGE, &CustomMessageWindow::OnCustomRegisterMessage)
END_MESSAGE_MAP()

CustomMessageWindow::
CustomMessageWindow()
{
    DbgConPrtMeth(Yellow);

    CString strWndClass = AfxRegisterWndClass(
        CS_DBLCLKS,
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
        reinterpret_cast<HBRUSH>(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    CreateEx(0, strWndClass, TEXT("Custom Message"),
             WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_THICKFRAME,
             CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
             NULL, NULL);
}

CustomMessageWindow::
~CustomMessageWindow()
{
    DbgConPrtMeth(Yellow);
}


INT CustomMessageWindow::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DbgConPrtMeth(Yellow);

    PostMessage(PM_CUSTOM_PRIVATE_MESSAGE);
    PostMessage(AM_CUSTOM_APPLICATION_MESSAGE);
    ::PostMessage(HWND_BROADCAST, RM_CUSTOM_REGISTER_MESSAGE, NULL, NULL);

    return 0;
}

LRESULT CustomMessageWindow::
OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    UNUSED_ALWAYS(lParam);
    DbgConPrtMeth(Yellow);
    return 0;
}

LRESULT CustomMessageWindow::
OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    UNUSED_ALWAYS(lParam);
    DbgConPrtMeth(Yellow);
    return 0;
}

LRESULT CustomMessageWindow::
OnCustomRegisterMessage(WPARAM wParam, LPARAM lParam)
{
    UNUSED_ALWAYS(wParam);
    UNUSED_ALWAYS(lParam);
    DbgConPrtMeth(Yellow);
    return 0;
}
