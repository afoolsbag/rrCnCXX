/// \copyright The MIT License

#include "stdafx.h"
#include "HiddenWindow.h"

#include "main.h"

#// Private Message
#define PM_CUSTOM_PRIVATE_MESSAGE (WM_USER + 1)

IMPLEMENT_DYNCREATE(HiddenWindow, CFrameWnd)

BEGIN_MESSAGE_MAP(HiddenWindow, CFrameWnd)
    ON_WM_CREATE()
    ON_MESSAGE(PM_CUSTOM_PRIVATE_MESSAGE, &HiddenWindow::OnCustomPrivateMessage)
    ON_MESSAGE(AM_CUSTOM_APPLICATION_MESSAGE, &HiddenWindow::OnCustomApplicationMessage)
    ON_REGISTERED_MESSAGE(RM_CUSTOM_REGISTER_MESSAGE, &HiddenWindow::OnCustomRegisterMessage)
END_MESSAGE_MAP()

HiddenWindow::HiddenWindow()
{
    Create(NULL, TEXT("Hidden Window"));
}

INT HiddenWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    PostMessage(PM_CUSTOM_PRIVATE_MESSAGE);
    PostMessage(AM_CUSTOM_APPLICATION_MESSAGE);
    ::PostMessage(HWND_BROADCAST, RM_CUSTOM_REGISTER_MESSAGE, 0, 0);

    return 0;
}

LRESULT HiddenWindow::OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam)
{
    TRACE(TEXT("PM_CUSTOM_PRIVATE_MESSAGE\n"));
    return 0;
}

LRESULT HiddenWindow::OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam)
{
    TRACE(TEXT("AM_CUSTOM_APPLICATION_MESSAGE\n"));
    return 0;
}

LRESULT HiddenWindow::OnCustomRegisterMessage(WPARAM wParam, LPARAM lParam)
{
    TRACE(TEXT("RM_CUSTOM_REGISTER_MESSAGE"));
    return 0;
}
