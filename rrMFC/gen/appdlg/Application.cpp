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
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("Constructor\n"));
}

Application::
~Application()
{
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("Destructor\n"));
    DelDbgCon();
}

#// Overridables

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrtDbl(Red, TEXT("Application::"), LightRed, TEXT("InitInstance\n"));

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    switch (mainDlg.DoModal()) {
    case IDOK:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDOK\n")); break;
    case IDCANCEL:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDCANCEL\n")); break;
    case IDABORT:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDABORT\n")); break;
    case IDRETRY:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDRETRY\n")); break;
    case IDIGNORE:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDIGNORE\n")); break;
    case IDYES:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDYES\n")); break;
    case IDNO:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDNO\n")); break;
    case IDCLOSE:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDCLOSE\n")); break;
    case IDHELP:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDHELP\n")); break;
    case IDTRYAGAIN:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDTRYAGAIN\n")); break;
    case IDCONTINUE:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDCONTINUE\n")); break;
    case IDTIMEOUT:
        DbgConPrtDbl(Red, TEXT("Application::InitInstance"), LightRed, TEXT(" DoModal -> IDTIMEOUT\n")); break;
    default:
        ASSERT(FALSE); break;
    }

    return FALSE;
}
