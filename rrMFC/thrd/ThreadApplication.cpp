/// \copyright The MIT License

#include "stdafx.h"
#include "ThreadApplication.h"

#include "rrwindows/dbgcon.h"

#include "ui/ThreadDialog.h"

IMPLEMENT_DYNAMIC(ThreadApplication, CWinApp)

#// Constructors

ThreadApplication::
ThreadApplication()
{
    NewDebugConsole();
    DbgConPrtMeth(Red);
}

ThreadApplication::
~ThreadApplication()
{
    DbgConPrtMeth(Red);
    DeleteDebugConsole();
}

#// Overridables

BOOL ThreadApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    ThreadDialog mainWnd;
    m_pMainWnd = &mainWnd;
    mainWnd.DoModal();

    return FALSE;
}
