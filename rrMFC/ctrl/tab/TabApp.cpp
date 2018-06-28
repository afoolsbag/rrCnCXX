/// \copyright The MIT License

#include "stdafx.h"
#include "TabApp.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/dbgprt.h"

#include "ui/TabDlg.h"

#// Constructors

TabApplication::
TabApplication()
{
    AllocDebugConsole();
    DcMeth();
}

TabApplication::
~TabApplication()
{
    DcMeth();
    FreeDebugConsole();
}

#// Overridables

BOOL TabApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DcMeth();

    TabDialog mainWnd;
    m_pMainWnd = &mainWnd;
    CONST INT_PTR result = mainWnd.DoModal();

    switch (result) {
    case IDOK:
        break;
    case IDCANCEL:
        break;
    default:
        DpErrorSwitchUnknown(result);
        break;
    }

    return FALSE;
}
