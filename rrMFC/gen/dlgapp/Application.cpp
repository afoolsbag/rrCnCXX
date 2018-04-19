/// \copyright The MIT License

#include "stdafx.h"
#include "Application.h"

#include "utils/dbgcon.inl"

#include "resource.h"
#include "ui/MainDialog.h"

IMPLEMENT_DYNCREATE(Application, CWinApp)

Application::
Application()
{
    NewDbgCon(LightRed, TEXT("Application::Constructor\n"));
}

Application::
~Application()
{
    DelDbgCon(LightRed, TEXT("Application::Destructor\n"));
}

BOOL Application::
InitApplication()
{
    DbgConPrt(LightRed, TEXT("Application::InitApplication"));
    DbgConPrt(Red, TEXT(" without doc, for hooks\n"));
    return CWinApp::InitApplication();
}

BOOL Application::
InitInstance()
{
    CWinApp::InitInstance();
    DbgConPrt(LightRed, TEXT("Application::InitInstance\n"));

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    switch (mainDlg.DoModal()) {
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
    default: ASSERT(FALSE); break;
    }

    return FALSE;
}

INT Application::
ExitInstance()
{
    DbgConPrt(LightRed, TEXT("Application::ExitInstance\n"));
    return CWinApp::ExitInstance();
}
