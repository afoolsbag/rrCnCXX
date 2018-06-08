/// \copyright The MIT License

#include "stdafx.h"
#include "WindowApplication.h"

#include "rrwindows/dbgcon.h"

#include "ui/Window.h"

IMPLEMENT_DYNAMIC(WindowApplication, CWinApp)

#// Constructors

WindowApplication::
WindowApplication()
{
    NewDebugConsole();
    DbgConPrtMeth(Red);
}

WindowApplication::
~WindowApplication()
{
    DbgConPrtMeth(Red);
    DeleteDebugConsole();
}

#// Overridables

BOOL WindowApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    m_pMainWnd = DEBUG_NEW Window;
    m_pMainWnd->ShowWindow(m_nCmdShow);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}
