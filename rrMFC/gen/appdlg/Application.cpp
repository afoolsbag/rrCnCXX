/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.h"

#include "resource.h"
#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

#// Constructors

Application::
Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
}

#// Overridables

Application::
~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(LightRed, TEXT("Application::InitInstance\n"));

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    switch (mainDlg.DoModal()) {
    case IDOK: DbgConPrt(LightRed, TEXT("IDOK\n")); break;
    case IDCANCEL:DbgConPrt(LightRed, TEXT("IDCANCEL\n")); break;
    case IDABORT: DbgConPrt(LightRed, TEXT("IDABORT\n")); break;
    case IDRETRY: DbgConPrt(LightRed, TEXT("IDRETRY\n")); break;
    case IDIGNORE: DbgConPrt(LightRed, TEXT("IDIGNORE\n")); break;
    case IDYES: DbgConPrt(LightRed, TEXT("IDYES\n")); break;
    case IDNO: DbgConPrt(LightRed, TEXT("IDNO\n")); break;
    case IDCLOSE: DbgConPrt(LightRed, TEXT("IDCLOSE\n")); break;
    case IDHELP: DbgConPrt(LightRed, TEXT("IDHELP\n")); break;
    case IDTRYAGAIN: DbgConPrt(LightRed, TEXT("IDTRYAGAIN\n")); break;
    case IDCONTINUE: DbgConPrt(LightRed, TEXT("IDCONTINUE\n")); break;
    case IDTIMEOUT: DbgConPrt(LightRed, TEXT("IDTIMEOUT\n")); break;
    default: ASSERT(FALSE); break;
    }

    return FALSE;
}
