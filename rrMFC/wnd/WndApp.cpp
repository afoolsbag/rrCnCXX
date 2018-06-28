/// \copyright The MIT License

#include "stdafx.h"
#include "WndApp.h"

#include "rrwindows/dbgcon.h"

#include "ui/Wnd.h"

#// Register Messages

UINT RM_CUSTOM_REGISTER_MESSAGE = RegisterWindowMessage(TEXT("RM_CUSTOM_REGISTER_MESSAGE"));

#// Constructors

WindowApplication::
WindowApplication()
{
    AllocDebugConsole();
    DcMeth();
}

WindowApplication::
~WindowApplication()
{
    DcMeth();
    FreeDebugConsole();
}

#// Overridables

BOOL WindowApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DcMeth();

    m_pMainWnd = DEBUG_NEW Window;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}
