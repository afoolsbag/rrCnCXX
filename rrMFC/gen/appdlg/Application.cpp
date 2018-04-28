/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon(Red, TEXT("Application::"));
    DbgConPrt(LightRed, TEXT("Constructor\n"));
}

Application::
~Application()
{
    DbgConPrt(Red, TEXT("Application::"));
    DelDbgCon(LightRed, TEXT("Destructor\n"));
}

#// Overridables

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(Red, TEXT("Application::"));
    DbgConPrt(LightRed, TEXT("InitInstance\n"));

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    switch (mainDlg.DoModal()) {
    case IDOK:
        DbgConPrt(LightRed, TEXT("DoModal -> IDOK\n")); break;
    case IDCANCEL:
        DbgConPrt(LightRed, TEXT("DoModal -> IDCANCEL\n")); break;
    case IDABORT:
        DbgConPrt(LightRed, TEXT("DoModal -> IDABORT\n")); break;
    case IDRETRY:
        DbgConPrt(LightRed, TEXT("DoModal -> IDRETRY\n")); break;
    case IDIGNORE:
        DbgConPrt(LightRed, TEXT("DoModal -> IDIGNORE\n")); break;
    case IDYES:
        DbgConPrt(LightRed, TEXT("DoModal -> IDYES\n")); break;
    case IDNO:
        DbgConPrt(LightRed, TEXT("DoModal -> IDNO\n")); break;
    case IDCLOSE:
        DbgConPrt(LightRed, TEXT("DoModal -> IDCLOSE\n")); break;
    case IDHELP:
        DbgConPrt(LightRed, TEXT("DoModal -> IDHELP\n")); break;
    case IDTRYAGAIN:
        DbgConPrt(LightRed, TEXT("DoModal -> IDTRYAGAIN\n")); break;
    case IDCONTINUE:
        DbgConPrt(LightRed, TEXT("DoModal -> IDCONTINUE\n")); break;
    case IDTIMEOUT:
        DbgConPrt(LightRed, TEXT("DoModal -> IDTIMEOUT\n")); break;
    default:
        ASSERT(FALSE); break;
    }

    return FALSE;
}
