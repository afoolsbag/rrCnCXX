/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

#include "ui/MainDialog.h"

IMPLEMENT_DYNAMIC(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDebugConsole();
    DbgConPrtMeth(Red);
}

Application::
~Application()
{
    DbgConPrtMeth(Red);
    DeleteDebugConsole();
}

#// Overridables

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    CONST INT_PTR result = mainDlg.DoModal();

    DbgConPrtMeth(Red);
    switch (result) {
    case IDOK:
        DbgConPut(LightRed, TEXT(" DoModal -> IDOK\n")); break;
    case IDCANCEL:
        DbgConPut(LightRed, TEXT(" DoModal -> IDCANCEL\n")); break;
    case IDABORT:
        DbgConPut(LightRed, TEXT(" DoModal -> IDABORT\n")); break;
    case IDRETRY:
        DbgConPut(LightRed, TEXT(" DoModal -> IDRETRY\n")); break;
    case IDIGNORE:
        DbgConPut(LightRed, TEXT(" DoModal -> IDIGNORE\n")); break;
    case IDYES:
        DbgConPut(LightRed, TEXT(" DoModal -> IDYES\n")); break;
    case IDNO:
        DbgConPut(LightRed, TEXT(" DoModal -> IDNO\n")); break;
    case IDCLOSE:
        DbgConPut(LightRed, TEXT(" DoModal -> IDCLOSE\n")); break;
    case IDHELP:
        DbgConPut(LightRed, TEXT(" DoModal -> IDHELP\n")); break;
    case IDTRYAGAIN:
        DbgConPut(LightRed, TEXT(" DoModal -> IDTRYAGAIN\n")); break;
    case IDCONTINUE:
        DbgConPut(LightRed, TEXT(" DoModal -> IDCONTINUE\n")); break;
    case IDTIMEOUT:
        DbgConPut(LightRed, TEXT(" DoModal -> IDTIMEOUT\n")); break;
    default:
        TRACE1("Unknown switch-case-route with condition: result=%d.", result); ASSERT(FALSE); break;
    }

    return FALSE;
}
