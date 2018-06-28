/// \copyright The MIT License

#include "stdafx.h"
#include "BxsApp.h"

#include "rrwindows/dbgcon.h"

#include "ui/BxsDlg.h"

#// Constructors

BoxesApplication::
BoxesApplication()
{
    AllocDebugConsole();
    DcMeth();
}

BoxesApplication::
~BoxesApplication()
{
    DcMeth();
    FreeDebugConsole();
}

#// Overridables

BOOL BoxesApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DcMeth();

    BoxesDialog mainWnd;
    m_pMainWnd = &mainWnd;
    mainWnd.DoModal();

    return FALSE;
}
