/// \copyright The MIT License

#include "stdafx.h"
#include "BxsApp.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/exepath.h"

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

    // Initialization
    free(const_cast<LPTSTR>(m_pszProfileName));
    m_pszProfileName = _tcsdup(InitializationPath());

    BoxesDialog mainWnd;
    m_pMainWnd = &mainWnd;
    mainWnd.DoModal();

    return FALSE;
}
