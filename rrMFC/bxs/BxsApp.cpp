/// \copyright The MIT License

#include "stdafx.h"
#include "BxsApp.h"

#include "rrwindows/dbgcon.h"

#include "ui/BxsDlg.h"

#// Constructors

BoxesApplication::
BoxesApplication()
{
    NewDebugConsole();
    DbgConMeth();
}

BoxesApplication::
~BoxesApplication()
{
    DbgConMeth();
    DeleteDebugConsole();
}

#// Overridables

BOOL BoxesApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConMeth();

    BoxesDialog mainWnd;
    m_pMainWnd = &mainWnd;
    mainWnd.DoModal();

    return FALSE;
}
