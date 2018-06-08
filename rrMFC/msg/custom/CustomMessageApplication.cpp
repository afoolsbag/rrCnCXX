/// \copyright The MIT License

#include "stdafx.h"
#include "CustomMessageApplication.h"

#include "rrwindows/dbgcon.h"

#include "ui/CustomMessageWindow.h"

#// Register Messages
UINT RM_CUSTOM_REGISTER_MESSAGE = RegisterWindowMessage(TEXT("RM_CUSTOM_REGISTER_MESSAGE"));

IMPLEMENT_DYNAMIC(CustomMessageApplication, CWinApp)

#// Constructors

CustomMessageApplication::
CustomMessageApplication()
{
    NewDebugConsole();
    DbgConPrtMeth(Red);
}

CustomMessageApplication::
~CustomMessageApplication()
{
    DbgConPrtMeth(Red);
    DeleteDebugConsole();
}

#// Overridables

BOOL CustomMessageApplication::
InitInstance()
{
    CWinApp::InitInstance();

    m_pMainWnd = new CustomMessageWindow;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}
