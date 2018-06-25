/// \copyright The MIT License

#include "stdafx.h"
#include "DlgApp.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/prtdbgstr.h"

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
    case IDOK://fallthrough
    case IDCANCEL://fallthrough
    case IDABORT://fallthrough
    case IDRETRY://fallthrough
    case IDIGNORE://fallthrough
    case IDYES://fallthrough
    case IDNO://fallthrough
    case IDCLOSE://fallthrough
    case IDHELP://fallthrough
    case IDTRYAGAIN://fallthrough
    case IDCONTINUE://fallthrough
    case IDTIMEOUT:
        break;
    default:
        DpErrorSwitchUnknown(result);
        break;
    }

    return FALSE;
}
