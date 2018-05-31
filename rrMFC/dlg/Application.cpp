/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "rrwindows/dbgcon.h"

#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon();
    DbgConPrtMeth(Red);
}

Application::
~Application()
{
    DbgConPrtMeth(Red);
    DelDbgCon();
}

#// Overridables

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtMeth(Red);

    TRACE(traceAppMsg, 0, TEXT("dd\n"));

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    CONST INT_PTR result = mainDlg.DoModal();

    DbgConPrt(Red, TEXT("Application::InitInstance"));
    switch (result) {
    case IDOK:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDOK\n")); break;
    case IDCANCEL:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDCANCEL\n")); break;
    case IDABORT:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDABORT\n")); break;
    case IDRETRY:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDRETRY\n")); break;
    case IDIGNORE:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDIGNORE\n")); break;
    case IDYES:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDYES\n")); break;
    case IDNO:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDNO\n")); break;
    case IDCLOSE:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDCLOSE\n")); break;
    case IDHELP:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDHELP\n")); break;
    case IDTRYAGAIN:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDTRYAGAIN\n")); break;
    case IDCONTINUE:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDCONTINUE\n")); break;
    case IDTIMEOUT:
        DbgConPrt(LightRed, TEXT(" DoModal -> IDTIMEOUT\n")); break;
    default:
        TRACE1("Unknown switch-case-route with condition %d.", result); ASSERT(FALSE); break;
    }

    return FALSE;
}
