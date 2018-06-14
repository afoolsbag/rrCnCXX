/// \copyright The MIT License

#include "stdafx.h"
#include "DlgApp.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/prtdbg.h"

#include "ui/Dlg.h"

#// Constructors

DialogApplication::
DialogApplication()
{
    NewDebugConsole();
    DbgConMeth();
}

DialogApplication::
~DialogApplication()
{
    DbgConMeth();
    DeleteDebugConsole();
}

#// Overridables

BOOL DialogApplication::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConMeth();

    Dialog mainWnd;
    m_pMainWnd = &mainWnd;
    CONST INT_PTR result = mainWnd.DoModal();

    switch (result) {
    case IDOK: break;
    case IDCANCEL: break;
    case IDABORT: break;
    case IDRETRY: break;
    case IDIGNORE: break;
    case IDYES: break;
    case IDNO: break;
    case IDCLOSE: break;
    case IDHELP: break;
    case IDTRYAGAIN: break;
    case IDCONTINUE: break;
    case IDTIMEOUT: break;
    default: DpError("Unknown switch-case-route with condition: result=%d.", result); break;
    }

    return FALSE;
}
