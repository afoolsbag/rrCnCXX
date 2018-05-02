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

    MainDialog mainDlg;
    m_pMainWnd = &mainDlg;
    mainDlg.DoModal();

    return FALSE;
}
